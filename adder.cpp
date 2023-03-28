#include "adder.hpp"

// Construtor padrão para a classe
Adder::Adder() = default;

// Função que executa a soma
// Requer duas entradas que serão utilizadas na soma
// O resultado é armazenado na variável PCoutput
void Adder::executa(int inputA, int inputB) {
	this->output = inputA + inputB;
}

// Retorna o valor de PCoutput
int Adder::getOutput() {
    return output;
}
