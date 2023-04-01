#include "control.hpp"
#include <iostream>

// Construtor padrão da classe
Control::Control() = default;

// Define o valor dos sinais de controle com base na instrução
void Control::executa(int input) {
    switch (input) {
        // Tipo R
        case 51:
            std::cout << "Instrucao do Tipo R" << std::endl;
            this->Branch = 0;
            this->MemRead = 0;
            this->MemToReg = 0;
            this->ALUOp = 2;
            this->MemWrite = 0;
            this->ALUSrc = 0;
            this->RegWrite = 1;
            break;

            // ADDI
        case 19:
            std::cout << "Instrucao ADDI" << std::endl;
            this->Branch = 0;
            this->MemRead = 0;
            this->MemToReg = 0;
            this->ALUOp = 0;
            this->MemWrite = 0;
            this->ALUSrc = 1;
            this->RegWrite = 1;
            break;

            //  LW
        case 3:
            std::cout << "Instrucao LW" << std::endl;
            this->Branch = 0;
            this->MemRead = 1;
            this->MemToReg = 1;
            this->ALUOp = 0;
            this->MemWrite = 0;
            this->ALUSrc = 1;
            this->RegWrite = 1;
            break;

            //  SW
        case 35:
            std::cout << "Instrucao SW" << std::endl;
            this->Branch = 0;
            this->MemRead = 0;
            this->MemToReg = 0;
            this->ALUOp = 0;
            this->MemWrite = 1;
            this->ALUSrc = 1;
            this->RegWrite = 0;
            break;

            // Tipo B
        case 99:
            std::cout << "Instrucao do Tipo B" << std::endl;
            this->Branch = 1;
            this->MemRead = 0;
            this->MemToReg = 0;
            this->ALUOp = 1;
            this->MemWrite = 0;
            this->ALUSrc = 0;
            this->RegWrite = 0;
            break;
    }
}

//retornam o valor dos sinais de controle
int Control::getBranch() {
    return Branch;
}

int Control::getMemRead() {
    return MemRead;
}

int Control::getMemToReg() {
    return MemToReg;
}

int Control::getAluOp() {
    return ALUOp;
}

int Control::getMemWrite() {
    return MemWrite;
}

int Control::getAluSrc() {
    return ALUSrc;
}

int Control::getRegWrite() {
    return RegWrite;
}