#include "bitsqueezr.hpp"
#include <bitset>
#include <Arduino.h>

/*! \brief Set maximum array size.
 *
 *  Sets the maximum array size and initializes the bitArray. Mandatory!
 */
bool BitSqueezr::setMaxSize(uint8_t size)
{
    this->maxSize = 12;
    bitArray.init(maxSize);
}

/*! \brief Returns the current bitArray.
 *
 *  Returns the current bitArray as uint8 pointer.
 */
uint8_t* BitSqueezr::getEncodedData() {
    return bitArray.getData();
}

/*! \brief Returns the current decoded data.
 *
 *  Returns the current decoded data.
 */
uint64_t BitSqueezr::getDecodedData() {
    Serial.printf("%d", decodedData);
    return decodedData;
}


/*! \brief Returns the current bitArray size.
 *
 *  Returns the current bitArray size as integer value.
 */
int BitSqueezr::getSize() {
    return bitArray.total_bytes();
}

/*! \brief Adds a new value for encoding
 *
 *  Adds a new uint64 value for encoding with fibonacci algorithm and uses bitArray to pack it bit-precise.
 */
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

/*! \brief Unpacks encoded bitArray
 *
 *  Unpacks an fibonacci encoded, bit-precise bitArray uint8 value
 */
bool BitSqueezr::unpack(uint8_t* value)
{
    std::string str;
    for (int i = 0; i < getSize(); i++)
    {
        std::string s = std::bitset<8>(value[i]).to_string(); // string conversion
        str.append(s.c_str());
    }
    str.erase ( str.find_last_not_of('0') + 1, std::string::npos );

    decodedData = encoder.decodeFib(str.c_str());

    return true;
}
