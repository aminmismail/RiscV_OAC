#include "mux.hpp"

// Construtor da classe
MUX::MUX(){
    MUXoutput = 0;
}

// Escolhe entre o inputA e o inputB com base no valor de inputControl
// Requer dois valores de possíveis saidas e um de controle
void MUX::executa(int inputA, int inputB, int inputContol){
    if(inputContol == 0) this->MUXoutput = inputA;
    else this->MUXoutput = inputB;
}

// Retorna o valor de PCoutput
int MUX::getOutput(){
    return MUXoutput;
}