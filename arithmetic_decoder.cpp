#include <iostream>
#include <fstream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <stdexcept>

// Number of bits in a code value
#define code_value_bits 16

// Input a bit
int input_bit(unsigned char* read_bit, unsigned int* bit_len, FILE* input_file, unsigned int* garbage_bit)
{
    if ( (*bit_len) == 0 )
    {
        (*read_bit) = fgetc(input_file);
        if (feof(input_file))
        {
            (*garbage_bit)++;
            if ( (*garbage_bit) > 14 )
            {
                throw std::invalid_argument("Can't decompress");
            }
        }
        (*bit_len) = 8;
    }
    int t = (*read_bit) & 1;
    (*read_bit) >>= 1;
    (*bit_len)--;
    return t;
}

int main()
{}
