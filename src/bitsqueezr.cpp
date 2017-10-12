#include "bitsqueezr.hpp"
#include <Arduino.h>

bool BitSqueezr::setMaxSize(uint8_t size)
{
    this->maxSize = 12;
    bitArray.init(maxSize);
}

uint8_t* BitSqueezr::getData() {
    return bitArray.getData();
}

int BitSqueezr::getSize() {
    return bitArray.total_bytes();
}

bool BitSqueezr::add(uint64_t value)
{
    //todo: add better size checks
    if(getSize() < maxSize)
    {
        char* codeword = encoder.encodeFib(value);

        size_t i;
        for (i=0; codeword[i]; i++)
        {
            int d = codeword[i] - '0';
                bitArray.push(d);
        }

        bitArray.dump();
        return true;
    }
    else
        return false;
}

bool BitSqueezr::unpack(uint64_t value)
{
  return true;
}
