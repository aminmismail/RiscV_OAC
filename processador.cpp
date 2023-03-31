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
    cout << "PC: " << pc->getOutput() << endl;
    // Executa o Program Couter com o valor do mux3
	pc->executa(mux3->getOutput());
	cout << "PC: " << pc->getOutput() << endl;

    // Define a instrução a ser executada
	instructionMemory->executa(pc->getOutput());
	cout << "InstructionMemory: " << instructionMemory->getInstruction() << endl;

    // Incrementa o PC em 4 para ir para a próxima instrução
	adder1->executa(pc->getOutput(), 4);
	cout << "Adder: " << adder1->getOutput() << endl;

	int instrucao = instructionMemory->getInstruction();

    // Define os sinais de controle
	cout << "Sinais de Controle: " << endl;
	control->executa(instrucao & 127);
	cout << "Branch  : " << control->getBranch() << endl;
    cout << "ALUOP   : " << control->getAluOp() << endl;
    cout << "ALUSrc  : " << control->getAluSrc() << endl;
	cout << "MemRead : " << control->getMemRead() << endl;
    cout << "MemWrite: " << control->getMemWrite() << endl;
	cout << "MemToReg: " << control->getMemToReg() << endl;
	cout << "RegWrite: " << control->getRegWrite() << endl;

    // Coloca os dados dos registradores definidos no ReadData
	registers->executa((instrucao >> 15) & 31, (instrucao >> 20) & 31);
	cout << "Registers Read: " << endl;
	cout << "ReadData1: "  << registers->getReadData1() << endl;
	cout << "ReadData2: " << registers->getReadData2() << endl;

    // Gera o Immediate
	cout << "ImmGen " << endl;
	immgen->executa(instrucao);
    cout << "Output: " << immgen->getOutput() << endl;

    // Determina a entrada da ale entre o registrador 2 e o Immediate
	mux1->executa(registers->getReadData2(), immgen->getOutput(), control->getAluSrc());
	cout << "Saida Mux1: " << mux1->getOutput() << endl;

    // Define a operação a ser executada pela alu
	aluControl->executa(instrucao, control->getAluOp());
	cout << "ALUControl: " << aluControl->getOutput() << endl;

    // Executa a operação
	alu->executa(registers->getReadData1(), mux1->getOutput(), aluControl->getOutput());
	cout << "ALU: " << endl;
	cout << "Output: " << alu->getOutput() << endl;
	cout << "Zero  : " << alu->getZero() << endl;

    // Soma o valor de PC com o Immediate
	adder2->executa(pc->getOutput(), immgen->getOutput());
	cout << "Saida Adder2: " << adder2->getOutput() << endl;

    // Escolhe se inverte ou não a flag zero
	mux2->executa(alu->getZero(), (!alu->getZero()), ((instrucao >> 12) & 1));
	cout << "Saida Mux2: " << mux2->getOutput() << endl;

    // Escolhe entre a saida dos dois somadores para pc
	mux3->executa(adder1->getOutput(), adder2->getOutput(), (control->getBranch() & mux2->getOutput()));
	cout << "Saida Mux3: " << mux3->getOutput() << endl;

    // Lê ou escreve na memória de dados
	dataMemory->executa(alu->getOutput(), registers->getReadData2(), control->getMemRead(), control->getMemWrite());
	cout << "DataMem: " << endl;
	if(control->getMemRead()){
		cout << "Operacao Lida " << endl;
		cout << "Endereco: " << alu->getOutput() << endl;
		cout << "Dado: " << dataMemory->getReadData() << endl;
	}
	if(control->getMemWrite()){
		cout << "Operacao escrita" << endl;
		cout << "Endereco: " << alu->getOutput() << endl;
		cout << "Dado: " << registers->getReadData2() << endl;
	}

    // Define qual dado será escrito nos registradores
	mux4->executa(alu->getOutput(), dataMemory->getReadData(), control->getMemToReg());
	cout << "Saida Mux4: " << mux4->getOutput() << endl;

    // Escreve o PCoutput da alu ou da memória em um registrador se a flag for 1
	registers->executa((instrucao >> 7) & 31, mux4->getOutput(), control->getRegWrite());
	cout << "Escrita em registrador " << endl;
	cout << "Registrador: " << ((instrucao >> 7) & 32) << endl;
	cout << "Dado: " << mux4->getOutput() << endl;
	
}

// Imprime o valor dos registradores
void Processador::printRegistradores() {
    unsigned int const *registers = this->registers->getMemory();

    for (int i = 0; i < 32; ++i) {
        cout << "reg[" << i << "] = " << (int) registers[i] << endl;
    }
}


// Imprime o valor dos registradores com contrúdos diferentes de zero
void Processador::printMemoria(){
        unsigned char const *dataMem = this->dataMemory->getMemory();
        int val;

        for (int i = 0; i < 4096; ++i) {
            memcpy(&val, &dataMem[i], sizeof(int));
            if (dataMem[i] != 0) cout << "Mem[" << i << "] = " << val << endl;
        }
}