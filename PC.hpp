#ifndef PC_HPP
#define PC_HPP

// Unidade responsável por informar qual instrução será executada no ciclo
class PC {
private:
    // Endereço da memória que contém a instrução
    int PCoutput;

public:
    // Construtor da classe
	PC();
    // Define o valor de PCoutput a partir do input
    // Requer um valor de entrada
	void executa(int input);
    // Retorna o valor de PCoutput
	int getOutput();
};

#endif //PC_HPP