#include "fibonacci.hpp"
#include "bitarray.hpp"
#include <stdint.h>

class BitSqueezr
{
private:
    FibEncoder encoder;
    BitArray bitArray;
    uint8_t maxSize = 0;
    uint64_t decodedData = 0;

public:
    BitSqueezr();

    uint8_t* getEncodedData();
    uint64_t getDecodedData();
    int getSize();
    bool setMaxSize(uint8_t size);
    bool add(uint64_t value);
    bool unpack(uint8_t* value);
};
