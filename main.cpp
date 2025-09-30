#include <iostream>
#include "chip8.hpp"

// xxd test_opcode.ch8 | less


int main(){

    Chip8 chip8{};

    const std::string filename{"test_opcode.ch8"};

    chip8.PrintMemory();


    std::cout <<"Loading " << filename << " into memory \n";

    if(!chip8.LoadRom(filename)){
        std::cerr << "Could not load rom correcly. Try again. \n";
    }

    std::cout << "Rom loaded correctly \n";

    chip8.PrintMemory();

    return 0;

}