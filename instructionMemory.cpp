#include <string>
#include <iostream>
#include "instructionMemory.hpp"

// Construtor da classe
InstructionMemory::InstructionMemory(){
    this->memory = nullptr;
}

// Armazena todas as instruções na memória
// Requer um vetor do conteúdo lido do arquivo
void InstructionMemory::inicializa(unsigned int *memRef){
    this->memory = memRef;
}

// Define o valor da instrução com base na memoria
void InstructionMemory::executa(int input){
    this->instruction = this->memory[input/4];
	    if(!this->instruction){
		    std::cout << "\nPrograma finalizado!\n\n";
		    exit(0);
	}
}

// Retorna a instrução a ser executada
int InstructionMemory::getInstruction(){
    return instruction;
}
