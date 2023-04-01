#ifndef IMMGEN_HPP
#define IMMGEN_HPP

// Decodifica o valor immediate
class ImmGen {
private:
    // Armazena o valor de immediate
    int output;

public:
    // Construtor da classe
    ImmGen();

    // Gera o immediate a partir da instrução
    void executa(int input);

    // Retorna o valor de PCoutput
    int getOutput();
};

#endif //IMMGEN_HPP