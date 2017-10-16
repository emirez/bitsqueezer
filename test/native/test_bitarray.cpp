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
}

void test_bitarray_empty_bytes()
{
	// Empty Stack Byte Test
	ba.init(12);
	TEST_ASSERT_EQUAL(0, ba.total_bytes());
}

void test_bitarray_semifull_bits()
{
	// Semi-full Stack Bit Test
	ba.init(12);
	for(int i = 0; i<64; i++){
		ba.push(1);
	}
	TEST_ASSERT_EQUAL(64, ba.total_bits());
}

void test_bitarray_semifull_bytes()
{
	// Semi-full Stack Byte Test
	ba.init(12);
	for(int i = 0; i<64; i++){
		ba.push(1);
	}
	TEST_ASSERT_EQUAL(8, ba.total_bytes());
}

void test_bitarray_boundary()
{
	// Stack Boundary Test
	ba.init(12);
		for(int i = 0; i<96; i++){
			ba.push(1);
		}
	TEST_ASSERT_EQUAL(12, ba.total_bytes());
}

void test_bitarray_overflow()
{
	// Stack Overflow Test
	ba.init(4);
	for(int i = 0; i<64; i++){
		ba.push(1);
	}
	TEST_ASSERT_EQUAL(4, ba.total_bytes());
}

void test_bitarray_overload()
{
	// Stack Overload Test
	ba.init(12);
		for(int i = 0; i<=96; i++){
			ba.push(1);
		}
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
	RUN_TEST(test_bitarray_empty_bytes);
	RUN_TEST(test_bitarray_semifull_bits);
	RUN_TEST(test_bitarray_semifull_bytes);
	RUN_TEST(test_bitarray_boundary);
	// TEST TO BE FAILED
	RUN_TEST(test_bitarray_overflow);
	RUN_TEST(test_bitarray_overload);
	RUN_TEST(test_fibo_encode);
  UNITY_END();
}
#endif
