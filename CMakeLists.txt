cmake_minimum_required(VERSION 3.21.1)
project(RiscV_OAC)

set(CMAKE_CXX_STANDARD 17)

add_executable(RiscV_OAC main.cpp adder.cpp adder.hpp immGen.cpp dataMem.cpp control.hpp instructionMem.cpp aluControl.cpp aluControl.hpp alu.cpp vm.cpp alu.hpp immGen.hpp instructionMem.hpp control.cpp dataMem.hpp mux.cpp mux.hpp processador.cpp processador.hpp PC.cpp PC.hpp registers.cpp registers.hpp)
