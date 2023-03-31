#include "PC.hpp"

// Construtor da classe
PC::PC(){
	PCoutput = 0;
}

// Retorna o valor de PCoutput
int PC::getOutput() {
    return PCoutput;
}

// Define o valor de PCoutput a partir do input
void PC::executa(int input) {
	this->PCoutput = input;
}


