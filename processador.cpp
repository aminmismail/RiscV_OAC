#include <iostream>
#include <cstring>
#include "processador.hpp"

using namespace std;

// Construtor da classe
Processador::Processador() = default;

// Passa para a InstructionMem as instruções lidas do arquivo
void Processador::inicializa(unsigned int *instrucoes) {
    this->instructionMemory->inicializa(instrucoes);
}

// Executa um clock da riscv
void Processador::executa() {
    // Executa o Program Couter com o valor do mux3
    pc->executa(mux3->getOutput());
    cout << "-----------------------" << endl;
    cout << "PC: " << pc->getOutput() << endl;

    // Define a instrução a ser executada
    instructionMemory->executa(pc->getOutput());
    printf("Instrucao: 0x%08x\n", instructionMemory->getInstruction());

    // Incrementa o PC em 4 para ir para a próxima instrução
    adder1->executa(pc->getOutput(), 4);

    int instrucao = instructionMemory->getInstruction();

    // Define os sinais de controle
    cout << "Sinais de Controle " << endl;
    control->executa(instrucao & 127);
    cout << "Branch  : " << control->getBranch() << endl;
    printf("ALUOP   : %02d\n", control->getAluOp());
    cout << "ALUSrc  : " << control->getAluSrc() << endl;
    cout << "MemRead : " << control->getMemRead() << endl;
    cout << "MemWrite: " << control->getMemWrite() << endl;
    cout << "MemToReg: " << control->getMemToReg() << endl;
    cout << "RegWrite: " << control->getRegWrite() << endl;
    cout << "-----------------------" << endl;

    // Coloca os dados dos registradores definidos no ReadData
    registers->executa((instrucao >> 15) & 31, (instrucao >> 20) & 31);
    cout << "Registradores " << endl;
    cout << "DataReg1: " << registers->getReadData1() << endl;
    cout << "DataReg2: " << registers->getReadData2() << endl;
    cout << "-----------------------" << endl;

    // Gera o Immediate
    immgen->executa(instrucao);
    cout << "Output ImmGen: " << immgen->getOutput() << endl;
    cout << "-----------------------" << endl;

    // Determina a entrada da ale entre o registrador 2 e o imm
    mux1->executa(registers->getReadData2(), immgen->getOutput(), control->getAluSrc());

    // Define a operação a ser executada pela alu
    aluControl->executa(instrucao, control->getAluOp());

    // Executa a operação
    alu->executa(registers->getReadData1(), mux1->getOutput(), aluControl->getOutput());
    cout << "ALU" << endl;
    cout << "Output ALU: " << alu->getOutput() << endl;
    cout << "Flag Zero: " << alu->getZero() << endl;
    cout << "-----------------------" << endl;

    // Soma o valor de PC com o Immediate
    adder2->executa(pc->getOutput(), immgen->getOutput());

    // Escolhe se inverte ou não a flag zero
    mux2->executa(alu->getZero(), (!alu->getZero()), ((instrucao >> 12) & 1));

    // Escolhe entre a saida dos dois somadores para pc
    mux3->executa(adder1->getOutput(), adder2->getOutput(), (control->getBranch() & mux2->getOutput()));

    // Lê ou escreve na memória de dados
    dataMemory->executa(alu->getOutput(), registers->getReadData2(), control->getMemRead(), control->getMemWrite());

    // Define qual dado será escrito nos registradores
    mux4->executa(alu->getOutput(), dataMemory->getReadData(), control->getMemToReg());

    // Escreve o output da alu ou da memória em um registrador
    registers->executa((instrucao >> 7) & 31, mux4->getOutput(), control->getRegWrite());

}

// Imprime o valor dos registradores
void Processador::printRegistradores() {
    int i, j;
    unsigned int const *registers = this->registers->getMemory();
    for (i = 0, j = 16; i < 16 && j < 32; ++i, ++j) {
        cout << "reg[" << i << "] = " << (int) registers[i] << "\t";
        cout << "reg[" << j << "] = " << (int) registers[j] << endl;
    }
}


// Imprime o valor dos registradores com contrúdos diferentes de zero
void Processador::printMemoria() {
    unsigned char const *dataMem = this->dataMemory->getMemory();
    int valor;
    for (int i = 0; i < 4096; ++i) {
        memcpy(&valor, &dataMem[i], sizeof(int));
        if (dataMem[i] != 0) cout << "Mem[" << i << "] = " << valor << endl;
    }
}