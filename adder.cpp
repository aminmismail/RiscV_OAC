#include "adder.hpp"

// Construtor padrão
Adder::Adder() = default;

// Executa a soma
void Adder::executa(int inputA, int inputB) {
    this->output = inputA + inputB;
}

// Retorna o valor de output
int Adder::getOutput() {
    return output;
}
