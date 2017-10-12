#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bitarray.hpp"

  /** @brief creates a BitArray with a new buffer of given size */
  BitArray::BitArray(uint8_t maxsz) {
    this->sz = maxsz; 
    this->p_buf = (uint8_t*)malloc(this->sz);
    memset(this->p_buf, 0, this->sz);
    reset();
  }

