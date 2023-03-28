#ifndef PROCESSADOR_HPP
#define PROCESSADOR_HPP


#include "PC.hpp"
#include "adder.hpp"
#include "instructionMemory.hpp"
#include "control.hpp"
#include "mux.hpp"
#include "registers.hpp"
#include "immGen.hpp"
#include "aluControl.hpp"
#include "alu.hpp"
#include "dataMemory.hpp"

// Classe que simulara o processador da máquina virtual
// Essa classe posuirá cada uma das unidades necessárias
class Processador{
public:
    /* Todas as unidades presentes na arquitetura RISC-V monociclo
     *
     * adder1 é o adder que soma o valor de pc com 4
     * adder2 soma pc com o immediate
     *
     * mux1 é o que está entre registers e a alu, escolhe a fonte dos dados da alu
     * mux2 é o que utiliza o valor de zero e escolhe se vai fazer branch
     * mux3 é o que escolhe qual dos somadores será retornado para o pc
     * mux4 é o que está após a memória de dados, escolhe entre dados da memória ou da alu
     */
	PC *pc = new PC();
	Adder *adder1 = new Adder();
	InstructionMemory *instructionMemory = new InstructionMemory();
	Control *control = new Control();
	Registers *registers = new Registers();
	ImmGen *immgen = new ImmGen();
	MUX *mux1 = new MUX();
	Adder *adder2 = new Adder();
	ALU *alu = new ALU();
	ALUControl *aluControl = new ALUControl();
	MUX *mux2 = new MUX();
	MUX *mux3 = new MUX();
	DataMemory *dataMemory = new DataMemory();
	MUX *mux4 = new MUX();

public:
	Processador();
    // Passa para a InstructionMemory as instruções lidas do arquivo
    // Requer um vetor de inteiros com as instruções
	void inicializa(unsigned int *instructionMemoryRef);

    // Executa um clock
	void executa();

    // Imprime o valor dos registradores com contrúdos diferentes de zero
	void printRegistradores();

    // Imprime o valor de memória de dados com conteúdos diferentes de zero
	void printMemoria();

};

#endif //PROCESSADOR_HPP