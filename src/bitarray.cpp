#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitarray.hpp"

#define VERBOSE 1

BitArray::BitArray(uint8_t maxsz) : b_full(false), b_allocated(false) {
  init(maxsz);
}

BitArray::operator const char*(){
  return (const char*) p_buf;
}

BitArray::~BitArray() {
  free(p_buf);
}

bool BitArray::is_full() {
  return b_full;
}

void BitArray::init(uint8_t maxsz) {
  if (this->b_allocated) {
    free(p_buf);
  }
  this->sz = maxsz;
  this->p_buf = (uint8_t*)malloc(this->sz);
  this->b_allocated = true;
  memset(this->p_buf, 0, this->sz);
  reset();
}

void BitArray::reset() {
  memset(this->p_buf, 0, this->sz);
  this->p = this->p_buf;
  this->bitpos = 7;
  this->n = 0;
  this->b_full = false;
}

bool BitArray::push(uint8_t bit) {
  if (this->b_full) {
    return false;
  }

  *p |= ((bit != 0)?1:0) << this->bitpos;

  // advance
  if( this->bitpos == 0) {
    // still space left?
    if ( this->n < this->sz-1) {
      this->bitpos = 7;
      this->p++;
      this->n += 1;
    } else {
      b_full = true;
    }
  } else {
    this->bitpos--;
  }

  return true;
}

uint8_t* BitArray::getData() {
  return p_buf;
}

int BitArray::total_bits() {
  return this->n*8 + (7-this->bitpos);
}

int BitArray::total_bytes() {
  return this->n + (this->bitpos != 7?1:0);
}

void BitArray::dump() {
  uint8_t *p_cur = p_buf;
  for (int i = 0; i < sz; i++, p_cur++) {
    uint8_t v = *p_cur;
    char bits[9];
    for (int j = 0; j < 8; j++) {
      bits[j] = (( v & (1<<(7-j)))?'1':'0');
    }
    bits[8] = 0;
    if(VERBOSE)
      printf("%-2X %s\n", v, bits);

  }
  if(VERBOSE)
  {
    printf("bitpos=%d\n", this->bitpos);
    printf("n=%d\n", this->n);
  }
}
