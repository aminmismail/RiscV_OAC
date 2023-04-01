#ifndef INSTRUCTIONMEM_HPP
#define INSTRUCTIONMEM_HPP

//armazena as instruções que serão executadas
class InstructionMemory {
private:
    // armazena as instruções como inteiros
    unsigned int *memory;

    // Instrucao a ser executada nesse clock
    int instruction;

public:
    // Construtor da classe
    InstructionMemory();

    // Define o valor da instrução com base no local da memória
    void executa(int input);

    // Retorna a instrução a ser executada
    int getInstruction();

    // Armazena todas as instruções na memória
    void inicializa(unsigned int *memRef);


};

#endif //INSTRUCTIONMEM_HPP