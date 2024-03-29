#include <string>
#include <iostream>
#include "immGen.hpp"

// Construtor padrão da classe
ImmGen::ImmGen() = default;

// Gera o Immediate a partir da instrução
void ImmGen::executa(int input) {
    // Obtem os primeiros 7 bits da instrução para o opcode
    int opcode = input & 127;

    switch (opcode) {
        // Caso seja ADDI
        case 19:
            output = (input >> 20);
            if (output >> 11) output += 0xFFFFF000;
            break;

            // Caso seja LW
        case 3:
            output = (input >> 20);
            if (output >> 11) output += 0xFFFFF000;
            break;

            // Caso seja SW
        case 35: {
            int aux1 = (input >> 7) & 31;
            int aux2 = (input >> 20) & 4064;
            output = aux2 + aux1;
            if (output >> 11) output += 0xFFFFF000;
        }
            break;

            // Caso seja Tipo B
        case 99: {
            int aux1 = (input >> 7) & 30;
            int aux2 = (input >> 20) & 2016;
            int aux3 = (input << 4) & 2048;
            int aux4 = (input >> 19) & 4096;
            output = aux4 | aux3 | aux2 | aux1;
            if (output >> 12) output += 0xFFFFE000;
        }
            break;
    }
}

// Retorna o valor de PCoutput
int ImmGen::getOutput() {
    return output;
}
