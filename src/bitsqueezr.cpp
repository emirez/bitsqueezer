#include "bitsqueezr.hpp"
#include <bitset>
#include <stdio.h>
#include <Arduino.h>

BitSqueezr::BitSqueezr() : maxSize(0), decodedData(0) {
}

/*! \brief Set maximum array size.
 *
 *  Sets the maximum array size and initializes the bitArray. Mandatory!
 */
void BitSqueezr::setMaxSize(uint8_t size)
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
    Serial.printf("getDec: %d", decodedData);
    return decodedData;
}


/*! \brief Returns the current bitArray byte size.
 *
 *  Returns the current bitArray size as integer value.
 */
int BitSqueezr::getTotalBytes() {
    return bitArray.total_bytes();
}

/*! \brief Returns the current bitArray bit size.
 *
 *  Returns the current bitArray size as integer value.
 */
int BitSqueezr::getTotalBits() {
    return bitArray.total_bits();
}

/*! \brief Adds a new value for encoding
 *
 *  Adds a new char array for encoding with fibonacci algorithm and uses bitArray to pack it bit-precise.
 */
bool BitSqueezr::add(char* value)
{
    for (int i=0; i < value[i]; i++)
    {
        Serial.printf("Trying to add char: %d", value[i]);
        if(!add((u_int64_t)value[i]))
            return false;
    }

    return true;
}

/*! \brief Adds a new value for encoding
 *
 *  Adds a new uint64 value for encoding with fibonacci algorithm and uses bitArray to pack it bit-precise.
 */
bool BitSqueezr::add(uint64_t value)
{
    if(getTotalBytes() < maxSize)
    {
        char* codeword = encoder.encodeFib(value);
        if(((getTotalBits()+strlen(codeword))/8) < maxSize)
        {
            size_t i;
            for (i=0; codeword[i]; i++)
            {
                int d = codeword[i] - '0';
                    bitArray.push(d);
            }
        }
        else
        {
            Serial.printf("Can not fit %d bytes\n", maxSize);
            return false;
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
    for (int i = 0; i < getTotalBytes(); i++)
    {
        std::string s = std::bitset<8>(value[i]).to_string(); // string conversion
        str.append(s.c_str());
    }
    str.erase ( str.find_last_not_of('0') + 1, std::string::npos );

    Serial.printf("%s", str.c_str());

    decodedData = encoder.decodeFib(str.c_str());

    return true;
}
