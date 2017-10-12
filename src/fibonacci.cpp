#include "fibonacci.hpp"
#include <Arduino.h>

uint64_t FibEncoder::seriesFib(uint64_t n)
{
    fibSeries[0] = 1;
    fibSeries[1] = 2;

    uint64_t i;
    for (i=2; fibSeries[i-1]<=n; i++)
        fibSeries[i] = fibSeries[i-1] + fibSeries[i-2];

    return (i-2);
}

char * FibEncoder::encodeFib(uint64_t n)
{
  uint64_t index = seriesFib(n);
  char *codeword = (char*)malloc(sizeof(char)*(index+3));
  uint64_t i = index;
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

  return codeword;
}

uint64_t FibEncoder::decodeFib(const char *codeword)
{
  char *codeword_c = (char*) codeword;
  uint64_t len = strlen(codeword_c);
  uint64_t codeword_i[len];
  uint64_t decoded_nr = 0;

  for (int i = 0; i<len-1 ; i++)
  {
      codeword_i[i] = codeword_c[i] - '0';
      decoded_nr += codeword_i[i]*fibSeries[i];
  }

  return decoded_nr;
}

