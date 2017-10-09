#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

class BitArray {
  uint8_t   *p_buf;
  uint8_t   sz;

  uint8_t   *p;
  uint8_t   bitpos;
  uint8_t   n;

public:

  BitArray(uint8_t maxsz) {
    this->sz = maxsz; 
    this->p_buf = (uint8_t*)malloc(this->sz);
    reset();
  }

  void reset() {
    memset(this->p_buf, 0, this->sz);
    this->p = this->p_buf;
    this->bitpos = 7;
    this->n = 0;
  }

  void push(uint8_t bit) {
    *p |= ((bit != 0)?1:0) << this->bitpos;

    // advance
    if( this->bitpos == 0) {
      this->bitpos = 7;
      this->p++;
      this->n += 1;
    } else {
      this->bitpos--;
    }
  }

  int total_bits() {
    return this->n*8 + (7-this->bitpos); 
  }

  int total_bytes() {
    return this->n + (this->bitpos != 7?1:0);
  }

  void dump() {
    uint8_t *p_cur = p_buf;
    for (int i = 0; i < sz; i++, p_cur++) {
      uint8_t v = *p_cur;
      char bits[9];
      for (int j = 0; j < 8; j++) {
        bits[j] = (( v & (1<<(7-j)))?'1':'0'); 
      }
      bits[8] = 0;
      printf("%-2X %s\n", v, bits);
    }
    printf("bitpos=%i\n", this->bitpos);
    printf("n=%i\n", this->n);
  }
};

int main() {
  BitArray  ba(12);
  ba.push(1);
  ba.push(0);
  ba.push(1);
  ba.push(0);
  ba.push(1);
  ba.push(0);
  ba.push(1);
  ba.push(0);
  ba.push(1);
  ba.push(0);
  ba.push(0);
  ba.push(0);
  ba.push(1);
  ba.push(0);
  ba.push(0);
  ba.push(0);
  ba.push(1);
  ba.push(1);
  ba.push(0);
  ba.dump();

  printf("total_bits=%i\n", ba.total_bits());
  printf("total_bytes=%i\n", ba.total_bytes());
}
