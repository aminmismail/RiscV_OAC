#include <string>
#include <iostream>
#include "instructionMem.hpp"

// Construtor da classe
InstructionMemory::InstructionMemory() {
    this->memory = nullptr;
}

// Armazena todas as instruções na memória
void InstructionMemory::inicializa(unsigned int *memRef) {
    this->memory = memRef;
}

// Retorna a instrução a ser executada
int InstructionMemory::getInstruction() {
    return instruction;
}

// Define o valor da instrução com base na memoria
void InstructionMemory::executa(int input) {
    this->instruction = this->memory[input];
    if (!this->instruction) {
        std::cout << "\nPrograma encerrado!\n";
        exit(0);
    }
}