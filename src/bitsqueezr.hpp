#include "fibonacci.hpp"
#include <stdio.h>
#include <stdint.h>
#include <Arduino.h>

class BitSqueezr
{
private:
    FibEncoder encoder;

public:
    uint8_t *bitArray;
    uint8_t maxSize = 0;
    uint8_t currentSize = 0;

    bool add(uint64_t value, uint8_t type);
    bool add(uint64_t value);
    bool unpack(uint64_t value);
};
