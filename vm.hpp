#ifndef VM_HPP
#define VM_HPP

// Classe que representa a máquina virtual
class VM {
private:
    // Ponteiro para um processador
    class Processador *processador;

public:
    // Construtor da classe
    // Requer o nome do arquivo que contém as instruções
    VM(char *path);
    // Executa o clock
    void clock();
    // Transforma uma string em inteiro equivalente aos bits da intrução
    // Requer um vetor de caracteres formados por 1s e 0s
    // Retorna o inteiro formado por esses mesmos bits
    static unsigned int lerInstrucao(const char str[255]);
};

#endif //VM_HPP