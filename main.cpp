#include <iostream>
#include "vm.hpp"


int main(int argc, char *argv[]) {
    std::cout << "\n Trabalho II de OAC - Máquina Virtual RISC-V Monociclo" << std::endl;

    // Caso não tenha sido passado o arquivo de instruções
	if(argc < 1) {
		std::cout << "Como usar: \"./riscv instrucoes.txt\"\n";
		return 1;
	}

    // Cria a máquina virtual
    VM *vm = new VM(argv[1]);
	std::string str;

	std::cout << "Digite 'next' para próximo ciclo ou 'quit' para sair" << std::endl;
	std::cin >> str;

    // Encerra o programa caso digite 'quit', ou executa as instruções enquanto o usuário inserir 'next' até que o arquivo acabe
	while(str != "quit") {
		if(str == "next") vm->clock();
        else std::cout << "Entrada não reconhecida!" << std::endl;
		std::cin >> str;
	}

  return 0;
}
