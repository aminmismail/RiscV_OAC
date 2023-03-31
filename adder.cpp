#include "adder.hpp"

// Construtor padrão
Adder::Adder() = default;

// Executa a soma
// O resultado é armazenado na variável output
void Adder::executa(int inputA, int inputB) {
	this->output = inputA + inputB;
}

// Retorna o valor de output
int Adder::getOutput() {
    return output;
}
