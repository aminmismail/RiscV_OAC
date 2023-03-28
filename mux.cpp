#include "mux.hpp"

// Construtor da classe
MUX::MUX() = default;

// Escolhe entre o inputA e o inputB com base no valor de inputControl
// Requer dois valores de possíveis saidas e um de controle
void MUX::executa(int inputA, int inputB, int inputContol){
	this->MUXoutput = inputContol ? inputB : inputA;
}

// Retorna o valor de PCoutput
int MUX::getOutput(){
    return MUXoutput;
}