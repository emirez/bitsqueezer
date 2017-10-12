#ifndef __BITARRAY_HPP
#define __BITARRAY_HPP

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Arduino.h>

#define VERBOSE 1

/**
 * @brief BitArray stores a buffer of bytes and makes them accessible as
 * linear bits with push/pull methods.
 */
class BitArray {
  /** @brief internal byte buffer, memory is managed */
  uint8_t   *p_buf;
  /** @brief size of buffer */
  uint8_t   sz;

  /** @brief points to current byte */
  uint8_t   *p;
  /** @brief current position of bit&byte */
  uint8_t   bitpos;
  uint8_t   n;

public:

  /** @brief creates a BitArray with a new buffer of given size */
  BitArray(uint8_t maxsz = 64);

  operator const char*(){
    return (const char*) p_buf;
  }

  ~BitArray() {
    free(p_buf);
  }

  void init(uint8_t maxsz) {
      this->sz = maxsz;
      this->p_buf = (uint8_t*)malloc(this->sz);
      reset();
  }

  /** @brief rewinds positions */
  void reset() {
    memset(this->p_buf, 0, this->sz);
    this->p = this->p_buf;
    this->bitpos = 7;
    this->n = 0;
  }

  /** @brief pushes given bit into buffer, advances pointers etc. */
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

  /** @brief returns the buffer */
  uint8_t* getData() {
      return p_buf;
  }

  /** @brief returns the total number of bits written/read so far */
  int total_bits() {
    return this->n*8 + (7-this->bitpos);
  }

  /** @brief returns the total number of bytes written/read so far */
  int total_bytes() {
    return this->n + (this->bitpos != 7?1:0);
  }

  /** @brief dumps the buffer */
  void dump() {
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
};

#endif
