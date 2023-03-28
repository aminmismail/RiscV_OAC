#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP

// Unidade responsável por escolher entre dois inputs
class MUX {
private:
    // Resultado da multiplexação
    int MUXoutput;

public:
    // Construtor da classe
	MUX();
    // Escolhe entre o inputA e o inputB com base no valor de inputControl
    // Requer dois valores de possíveis saidas e um de controle
	void executa(int inputA, int inputB, int inputContol);
    // Retorna o valor de PCoutput
	int getOutput();
};

#endif //MULTIPLEXER_HPP