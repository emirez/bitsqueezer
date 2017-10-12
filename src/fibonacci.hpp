#include <stdio.h>
#include <stdint.h>
#include "bitarray.hpp"

class FibEncoder
{
private:
    int fibSeries[60];
    uint64_t seriesFib(uint64_t);

public:
    uint8_t *bitArray;
    int totalBytes;
    bool encodeFib(uint64_t);
    uint64_t decodeFib(const char *);
};
