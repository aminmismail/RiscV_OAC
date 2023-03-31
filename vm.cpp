#include <iostream>
#include "vm.hpp"
#include "processador.hpp"

// Construtor da classe
VM::VM(char *path) {
    // Cria o processador
    processador = new Processador();

    // Abre o arquivo com as instruções
    FILE *f = fopen(path, "r");
    if (f == nullptr){ //Em caso de falha
        std::cout << "Falha ao ler arquivo !" << std::endl;
        exit(1);
    }

    int i;
    auto *instrucoes = (unsigned int *) (malloc(255 * sizeof(unsigned int)));
    char buff[255];

    // Lê as instrucoes
    for (i = 0; !feof(f); i++) {
        fgets(buff, 255, f);
        instrucoes[i] = lerInstrucao(buff);
    }

    // Passa as instruções para o processador
    processador->inicializa(instrucoes);
}

// Realiza o clock
void VM::clock() {
    processador->executa();
    std::cout << "                  Registradores                  \n";

    processador->printRegistradores();
    std::cout << "                     Memoria                     \n";

    processador->printMemoria();
    std::cout << std::endl << std::endl;
}

// Transforma uma string em inteiro equivalente aos bits da intrução
unsigned int VM::lerInstrucao(const char *str) {
    unsigned int res = 0, aux = 1u;
    int i;

    for (i = 31; i >= 0; --i, aux <<= 1u) {
        res |= (str[i] - '0') ? aux : 0;
    }

    return res;
}