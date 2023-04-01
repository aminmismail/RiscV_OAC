#ifndef MULTIPLEXER_HPP
#define MULTIPLEXER_HPP

// Escolhe entre dois inputs
class MUX {
private:
    // Resultado do mux
    int MUXoutput;

public:
    // Construtor da classe
    MUX();

    // Escolhe entre o inputA e o inputB com base no valor de inputControl
    void executa(int inputA, int inputB, int inputContol);

    // Retorna o valor de output
    int getOutput();
};

#endif //MULTIPLEXER_HPP