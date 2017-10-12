#include "fibonacci.hpp"
#include "bitarray.hpp"
#include <stdio.h>
#include <stdint.h>
#include <Arduino.h>

class BitSqueezr
{
private:
    FibEncoder encoder;
    BitArray bitArray;
    uint8_t maxSize = 0;

public:
    uint8_t* getData();
    int getSize();
    bool setMaxSize(uint8_t size);
    bool add(uint64_t value);
    bool unpack(uint64_t value);
};
