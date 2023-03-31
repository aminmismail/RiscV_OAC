#ifndef CONTROL_HPP
#define CONTROL_HPP

// definie os sinais de controle
class Control {

private:
    // Cada variável guarda o valor de um sinal de controle
	int Branch;
	int MemRead;
	int MemToReg;
	int ALUOp;
	int MemWrite;
	int ALUSrc;
	int RegWrite;

public:
    // Construtor da classe
	Control();

    // Define o valor dos sinais com base na instrução
	void executa(int input);

    //Retornam o valor das variáveis
	int getBranch();
	int getAluOp();
    int getAluSrc();
    int getMemRead();
    int getMemToReg();
	int getMemWrite();
	int getRegWrite();
};

#endif //CONTROL_HPP