#include <stdint.h>
#include <stdio.h>

uint16_t count_leading_zeros(uint64_t x)
{
    x |= (x >> 1);
    x |= (x >> 2);
    x |= (x >> 4);
    x |= (x >> 8);
    x |= (x >> 16);
    x |= (x >> 32);

    x -= ((x >> 1) & 0x5555555555555555);
    x = ((x >> 2) & 0x3333333333333333) + (x & 0x3333333333333333);
    x = ((x >> 4) + x) & 0x0f0f0f0f0f0f0f0f;
    x += (x >> 8);
    x += (x >> 16);
    x += (x >> 32);

    return (64 - (x & 0x7f));
}

int find_string(uint64_t x, int n){
    int clz;    // leading zeros of x
    
    int pos = 0;    // position of fist '1' bit from significant bit
    
    while(x != 0){
        clz = count_leading_zeros(x);
        x = x << clz;
        pos = pos + clz;
        clz = count_leading_zeros(~x);
        if (clz >= n)
            return pos;
        x = x << clz;
        pos = pos + clz;
    }

    return -1;
}
