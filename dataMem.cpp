#include "dataMem.hpp"

// Construtor padrão da classe
DataMem::DataMem(): readData(0){}

// Executa a leitura e escrita na memória
void DataMem::executa(int address, int writeData, int memRead, int memWrite){
	if(memRead != 0) readData = memory[address];
	if(memWrite != 0) memory[address] = writeData;
}

// Retorna toda a memória do programa
const unsigned char *DataMem::getMemory() const {
    return memory;
}

// Retorna o valor de ReadData
int DataMem::getReadData() {
    return readData;
}