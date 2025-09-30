#pragma once

#include <cstdint>
#include <string_view>

constexpr unsigned int MEMORY_SIZE {4096};
constexpr unsigned int START_ADDRESS = 0x200;


class Chip8{
    public:
    // Chip8();
    void PrintMemory();
    bool LoadRom(const std::string& filename);


    private:
        uint8_t V[16]{};
        uint8_t memory[MEMORY_SIZE]{};
        uint16_t index{};
        uint16_t pc{};
        uint16_t stack[16]{};
        uint8_t sp{};
        uint8_t delayTimer{};
        uint8_t soundTimer{};
        uint8_t keypad[16]{};
        bool frameBuffer[64*32]{};
        uint16_t opcode{};

};