#include "alu.hpp"

// Construtor da classe
ALU::ALU() = default;

// Executa a operação informada por inputControl em inputA e inputB
void ALU::executa(int inputA, int inputB, int inputControl) {
    switch (inputControl) {
        case 0:
            this->output = inputA & inputB; //and binario
            break;

        case 1:
            this->output = inputA | inputB; // or
            break;

        case 2:
            this->output = inputA + inputB; //soma
            break;

        case 6:
            this->output = inputA - inputB; //subtracao
            break;
    }
    zero = (!output); //zero ativado qnd output é zero
}

// Retorna o valor de output
int ALU::getOutput() {
    return output;
}

// Retorna o valor da flag zero
int ALU::getZero() {
    return zero;
}
