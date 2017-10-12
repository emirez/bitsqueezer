#include <stdio.h>
#include <stdint.h>

class FibEncoder
{
private:
    int fibSeries[60];
    uint64_t seriesFib(uint64_t);

public:
    int totalBytes;
    char * encodeFib(uint64_t);
    uint64_t decodeFib(const char *);
};
