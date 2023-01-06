#include <sys/stat.h>
#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Number of bits in a code value
#define code_value_bits 16

// Get the index of a symbol
int indexForSymbol(char c, std::vector<std::pair<char, unsigned int>> arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (c == arr[i].first)
        {
            return i+2;
        }
    }

    return -1;
}

// Writing a bit to a file
void output_bit(unsigned int bit, unsigned int* bit_len, unsigned char* write_bit, FILE* output_file)
{
    (*write_bit) >>= 1;
    if (bit) (*write_bit) |= 0x80;
    (*bit_len)--;
    if ( (*bit_len) == 0 )
    {
        fputc((*write_bit), output_file);
        (*bit_len) = 8;
    }
}

// Write a sequence of bits to a file
void bitsPlusFollow(unsigned int bit, unsigned int* bits_to_follow, unsigned int* bit_len, unsigned char* write_bit, FILE* output_file)
{
    output_bit(bit, bit_len, write_bit, output_file);

    for (; *bits_to_follow > 0; (*bits_to_follow)--)
    {
        output_bit(!bit, bit_len, write_bit, output_file);
    }
}

int main{}
