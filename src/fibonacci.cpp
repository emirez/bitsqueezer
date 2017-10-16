#include "fibonacci.hpp"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    Serial.printf("Encoding: %d\n", n);
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

    Serial.printf("Original fib: %s\n", codeword);

    return codeword;
}

/*! \brief Decodes with fibonacci algorithm
 *
 *  Decodes given char array with fibonacci algorithm
 */
uint64_t FibEncoder::decodeFib(const char *codeword)
{
    Serial.printf("\nTrying to decode: %s", codeword);

    size_t len = strlen(codeword);
    uint64_t decoded_nr = 0;
    for (int i = 0; i<len-1 ; i++)
    {
        decoded_nr += (codeword[i] - '0')*fibSeries[i];
    }

    Serial.printf("\nNum: %d", decoded_nr);
    return decoded_nr;
}

