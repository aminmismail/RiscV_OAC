#include "PC.hpp"

// Construtor da classe
PC::PC(){
	this->PCoutput = 0;
}


// Define o valor de PCoutput a partir do input
// Requer um valor de entrada
void PC::executa(int input) {
	this->PCoutput = input;
}

// Retorna o valor de PCoutput
int PC::getOutput() {
    return PCoutput;
}
