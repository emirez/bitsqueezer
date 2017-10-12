#include "bitsqueezr.hpp"
#include <Arduino.h>

#undef qMain
#define INTEGER  0
#define BOOL  1
#define CHAR  2

bool BitSqueezr::add(uint64_t value)
{
    if (add(value, INTEGER))
        return true;
}

bool BitSqueezr::add(uint64_t value, uint8_t type)
{
    //todo: check size
    if(true)
    {
        if(encoder.encodeFib(value))
        {
            this->bitArray = encoder.bitArray;
            this->currentSize += encoder.totalBytes;
        }
        return false;
    }
    else
        return false;
}

bool BitSqueezr::unpack(uint64_t value)
{
  return true;
}
