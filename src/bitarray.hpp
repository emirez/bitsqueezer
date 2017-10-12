#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Arduino.h>

class BitArray {
  uint8_t   *p_buf;
  uint8_t   sz;

  uint8_t   *p;
  uint8_t   bitpos;
  uint8_t   n;

  uint8_t   *b;

public:

  operator const char*(){

    return (const char*) p_buf;
  }


  BitArray(uint8_t maxsz) {
    this->sz = maxsz;
    this->p_buf = (uint8_t*)malloc(this->sz);
    this->b = (uint8_t*)malloc(this->sz);
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

  uint8_t* getData() {
      return b;
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
      this->b[i] = v;
    }
    printf("bitpos=%d\n", this->bitpos);
    printf("n=%d\n", this->n);
  }
};

