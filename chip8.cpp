#include "chip8.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

void Chip8::PrintMemory(){

    std::cout << '\n';

    for(int i{0}; i < MEMORY_SIZE; i++){
        std::cout   << std::hex
                    << std::setw(2) 
                    << std::setfill('0') 
                    << static_cast<int>(memory[i]);

        if((i+1) % 2 == 0){ std:: cout << " "; }
        if((i+1) % 16 == 0 ){ std:: cout << '\n'; }
    }

    std::cout << '\n';

}


bool Chip8::LoadRom(const std::string& filename){

    //opening the file, readign it as binary, and going to the end of it
    std::ifstream romFile{};
    romFile.open(filename, std::ios::binary | std::ios::ate);


    if(!romFile.is_open()){
        return false;
    }

    //getting file size and moving file pointer to the beginning    
    std::streamsize filesize = romFile.tellg();
    romFile.seekg(0, std::ios::beg);   
    
    //allocating memory to hold file infomation
    char* fileBuffer = new char[filesize];

    //copy over file content and closing file
    if(!romFile.read(fileBuffer, filesize)){
        romFile.close();
        return false;
    }
    romFile.close();

    //copy content of file to memory start at 0x200
    for(int i{0}; i < filesize; i++){
        memory[START_ADDRESS+i]= fileBuffer[i];
    }

    //deallocating memory
    delete[] fileBuffer;

    return true;
}