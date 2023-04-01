#ifndef VM_HPP
#define VM_HPP
#include "processador.hpp"

// representa a máquina virtual
class VM {
private:
    // Ponteiro para um processador
    Processador *processador;

public:
    // Construtor da classe
    VM(char *path);

    // Executa o clock
    void clock();

    // Transforma uma string em int equivalente aos bits da instrução
    static unsigned int lerInstrucao(const char str[255]);
};

#endif //VM_HPP