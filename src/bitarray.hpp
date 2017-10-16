#ifndef __BITARRAY_HPP
#define __BITARRAY_HPP

#include <stdint.h>
#include <stdlib.h>

/**
 * \brief BitArray stores a buffer of bytes and makes them accessible as
 * linear bits with push/pull methods.
 */
class BitArray {
  /** \brief internal byte buffer, memory is managed */
  uint8_t   *p_buf;

  /** \brief size of buffer */
  uint8_t   sz;

  /** \brief points to current byte */
  uint8_t   *p;

  /** \brief current position of bit (from 7..0) */
  uint8_t   bitpos;

  /** \brief current position of byte */
  uint8_t   n;

  /** \brief flag is buffer is full */
  bool      b_full;

  /** \brief true if buffer is malloc'ed */
  bool      b_allocated;

public:

  /** \brief creates a BitArray with a new buffer of given size */
  BitArray(uint8_t maxsz = 64);

  /** \brief frees the buffer */
  ~BitArray();

  /** \brief initializes a buffer with a new size */
  void init(uint8_t maxsz);

  /** \brief rewinds positions */
  void reset();

  /** \brief pushes given bit into buffer, advances pointers etc. */
  bool push(uint8_t bit);

  /** \brief returns true if buffer is full and would overflow */
  bool is_full();

  /** \brief returns the buffer */
  operator const char*();

  /** \brief returns the buffer */
  uint8_t* getData();

  /** \brief returns the total number of bits written/read so far */
  int total_bits();

  /** \brief returns the total number of bytes written/read so far */
  int total_bytes();

  /** \brief dumps the buffer */
  void dump();
};

#endif
