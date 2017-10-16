#include "fibonacci.hpp"
#include "bitarray.hpp"
#include <stdint.h>

class BitSqueezr
{
private:
    FibEncoder encoder;
    BitArray bitArray;
    uint8_t maxSize;
    uint64_t decodedData;

public:
    BitSqueezr();
    uint8_t* getEncodedData();
    uint64_t getDecodedData();
    int getTotalBytes();
    int getTotalBits();
    void setMaxSize(uint8_t size);
    bool add(uint64_t value);
    bool add(char* value);
    bool unpack(uint8_t* value);
};
