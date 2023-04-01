#ifndef DATAMEM_HPP
#define DATAMEM_HPP

// Armazena os dados
class DataMem {
private:
    // Vetor onde são armazenados os dados
    unsigned char memory[65536] = {0};

    //armazena o valor da memória que foi lido
    int readData;

public:
    // Construtor da classe
    DataMem();

    // Executa a leitura e escrita na memória
    void executa(int address, int writeData, int memRead, int memWrite);

    // Retorna o valor de ReadData
    int getReadData();

    // Retorna toda a memória
    const unsigned char *getMemory() const;
};

#endif //DATAMEM_HPP