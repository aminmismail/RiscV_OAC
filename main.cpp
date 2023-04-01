#include <iostream>
#include "vm.hpp"


int main() {
    char path[50];
    std::cout << "\nTrabalho II de OAC - RISC-V Monociclo" << std::endl;
    std::cout << "Insira o arquivo a ser carregado: ";
    std::cin >> path;


    // Cria a máquina virtual
    VM *vm = new VM(path);
    //vm->processador->PC
	std::string str;

	std::cout << "Digite 'next' para proxima instrucao ou 'quit' para sair do programa" << std::endl << ">>";
	std::cin >> str;

    // Encerra o programa caso digite 'quit', ou executa as instruções enquanto o usuário inserir 'next' até que o arquivo acabe
	while(str != "quit") {
		if(str == "next") vm->clock();
        else std::cout << "Entrada não reconhecida!" << std::endl;
        std::cout << ">>";
		std::cin >> str;
	}

  return 0;
}
