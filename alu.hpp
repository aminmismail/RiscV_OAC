#ifndef ALU_HPP
#define ALU_HPP

// executa a soma, subtração, and e or
class ALU {
private:
    // Armazena o resultado da operação
	int output;

    // Armazena se o resultado foi 0 ou não
	int zero;

public:
    // Construtor da classe
	ALU();

    // Executa a operação informada por inputControl em inputA e inputB
	void executa(int inputA, int inputB, int inputControl);

    // Retorna o valor de PCoutput
	int getOutput();

    // Retorna o valor da flag zero
	int getZero();
};


#endif //ALU_HPP