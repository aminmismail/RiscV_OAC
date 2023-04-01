#ifndef PROCESSADOR_HPP
#define PROCESSADOR_HPP


#include "PC.hpp"
#include "adder.hpp"
#include "instructionMem.hpp"
#include "control.hpp"
#include "mux.hpp"
#include "registers.hpp"
#include "immGen.hpp"
#include "aluControl.hpp"
#include "alu.hpp"
#include "dataMem.hpp"

// simula o processador da máquina virtual
class Processador{
public:
	PC *pc = new PC();
	Adder *adder1 = new Adder(); //adder1 soma o valor pc+4
    Adder *adder2 = new Adder(); //adder2 soma pc com imm
	InstructionMemory *instructionMemory = new InstructionMemory();
	Control *control = new Control();
	Registers *registers = new Registers();
	ImmGen *immgen = new ImmGen();
	MUX *mux1 = new MUX(); //escolhe a fonte dos dados da alu
    MUX *mux2 = new MUX(); //utiliza o valor de zero e escolhe se vai fazer branch ou nao
    MUX *mux3 = new MUX(); //escolhe qual dos somadores será retornado para o pc
    MUX *mux4 = new MUX(); //escolhe entre os dados da memória ou da alu
	ALU *alu = new ALU();
	ALUControl *aluControl = new ALUControl();
	DataMem *dataMemory = new DataMem();


public:
	Processador();

    // Passa para a InstructionMemory as instruções lidas do arquivo
	void inicializa(unsigned int *instructionMemoryRef);

    // Executa um clock
	void executa();

    // Imprime o valor dos registradores
	void printRegistradores();

    // Imprime o valor de memória de dados com valores diferentes de zero
	void printMemoria();

};

#endif //PROCESSADOR_HPP