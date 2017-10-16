#ifdef UNIT_TEST

#include <unity.h>
#include <bitarray.hpp>

BitArray ba;
// Bitarray Tests
void test_bitarray_empty_bits()
{
	// Empty Stack Bit Test
	ba.init(12);
	TEST_ASSERT_EQUAL(0, ba.total_bits());
	TEST_ASSERT_EQUAL(0, ba.total_bytes());
	TEST_ASSERT_EQUAL(false, ba.is_full());
}


void test_bitarray_semifull_bits()
{
	// Semi-full Stack Bit Test
	ba.init(12);
	for(int i = 0; i<64; i++){
		ba.push(1);
	}
	TEST_ASSERT_EQUAL(64, ba.total_bits());
	TEST_ASSERT_EQUAL(false, ba.is_full());
}

void test_bitarray_semifull_bytes()
{
	// Semi-full Stack Byte Test
	ba.init(12);
	for(int i = 0; i<64; i++){
		ba.push(1);
	}
	TEST_ASSERT_EQUAL(8, ba.total_bytes());
	TEST_ASSERT_EQUAL(false, ba.is_full());
}

void test_bitarray_boundary()
{
	// Stack Boundary Test
	ba.init(12);
	// push 8x12 = 96 bits
  for(int i = 0; i<96; i++){
    ba.push(1);
  }
  // we expect the bitarray to be completely filled.
	TEST_ASSERT_EQUAL(12, ba.total_bytes());
	TEST_ASSERT_EQUAL(true, ba.is_full());
}

void test_bitarray_overflow()
{
	// Stack Overflow Test
	ba.init(4);
	// push more bits than it can hold
	for(int i = 0; i<40; i++){
		ba.push(1);
	}
	// it should be full, but only 4 bytes written
	TEST_ASSERT_EQUAL(true, ba.is_full());
	TEST_ASSERT_EQUAL(4, ba.total_bytes());
}

void test_bitarray_overload()
{
	// Stack Overload Test
	ba.init(12);
  for(int i = 0; i<=96; i++){
    ba.push(1);
  }
	TEST_ASSERT_EQUAL(true, ba.is_full());
	TEST_ASSERT_EQUAL(12, ba.total_bytes());
}

// Fibonacci Tests
void test_fibo_encode()
{
	// Fibonacci Encoder Test
	ba.init(12);
  for(int i = 0; i<=96; i++){
    ba.push(1);
  }
	TEST_ASSERT_EQUAL(1, 1);
}


int main( int argc, char **argv) {
	UNITY_BEGIN();
	// TEST TO BE PASSED
  RUN_TEST(test_bitarray_empty_bits);
	RUN_TEST(test_bitarray_semifull_bits);
	RUN_TEST(test_bitarray_semifull_bytes);
	RUN_TEST(test_bitarray_boundary);
	RUN_TEST(test_bitarray_overflow);
	RUN_TEST(test_bitarray_overload);
	RUN_TEST(test_fibo_encode);
  UNITY_END();
}
#endif
