#include "fibonacci.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#ifndef UNIT_TEST
#include <Arduino.h>
#endif

/*! \brief Returns fibonacci series
 *
 *  Returns a fibonacci series up to given value
 */
uint64_t FibEncoder::seriesFib(uint64_t n)
{
    fibSeries[0] = 1;
    fibSeries[1] = 2;

    uint64_t i;
    for (i=2; fibSeries[i-1]<=n; i++)
        fibSeries[i] = fibSeries[i-1] + fibSeries[i-2];

    return (i-2);
}

/*! \brief Encodes with fibonacci algorithm
 *
 *  Encodes given uint64 value with fibonacci algorithm
 */
char * FibEncoder::encodeFib(uint64_t n)
{
#ifndef UNIT_TEST
    Serial.printf("Encoding: %d\n", n);
#endif
    int64_t index = seriesFib(n);
    char *codeword = (char*)malloc(sizeof(char)*(index+3));
    int64_t i = index;
    while (n)
    {
        codeword[i] = '1';
        n = n - fibSeries[i];
        i = i - 1;
        while (i>=0 && fibSeries[i]>n)
        {
            codeword[i] = '0';
            i = i - 1;
        }
    }
    codeword[index+1] = '1';
    codeword[index+2] = '\0';

#ifndef UNIT_TEST
    Serial.printf("Original fib: %s\n", codeword);
#endif

    return codeword;
}

/*! \brief Decodes with fibonacci algorithm
 *
 *  Decodes given char array with fibonacci algorithm
 */
uint64_t FibEncoder::decodeFib(const char *codeword)
{
#ifndef UNIT_TEST
    Serial.printf("\nTrying to decode: %s", codeword);
#endif

    size_t len = strlen(codeword);
    uint64_t decoded_nr = 0;
    for (int i = 0; i<len-1 ; i++)
    {
        decoded_nr += (codeword[i] - '0')*fibSeries[i];
    }

#ifndef UNIT_TEST
    Serial.printf("\nNum: %d", decoded_nr);
#endif
    return decoded_nr;
}

