#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}
// 1
TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> v(5);
	for (size_t i = 0; i < 5; i++)
		v[i] = i + 1;
	TDynamicVector<int> v1(v);
	EXPECT_EQ(v, v1);
}
// 2
TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> orig(3);
	orig[0] = 1;
	orig[1] = 2;
	orig[2] = 3;

	TDynamicVector<int> copy(orig);

	copy[0] = 8;

	EXPECT_EQ(1, orig[0]);
	EXPECT_EQ(8, copy[0]);
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}

//TEST(TDynamicVector, can_set_and_get_element)
//{
//  TDynamicVector<int> v(4);
//  v[0] = 4;
//
//  EXPECT_EQ(4, v[0]);
//}

// 3
TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> v(7);
	ASSERT_ANY_THROW(v.at(-1));

}
// 4
TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> v(7);
	ASSERT_ANY_THROW(v.at(7));
	ASSERT_ANY_THROW(v.at(10));
}
// 5
TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> v(3);
	v[0] = 1;
	v[1] = 2;
	v[2] = 3;

	ASSERT_ANY_THROW(v = v);

	EXPECT_EQ(1, v[0]);
	EXPECT_EQ(2, v[1]);
	EXPECT_EQ(3, v[2]);
}
// 6
TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);

	for (size_t i = 0; i < 3; i++)
		a[i] = 8 * i;

	for (size_t i = 0; i < 3; i++)
		b[i] = i;

	b = a;

	EXPECT_EQ(a, b);
	for (size_t i = 0; i < 3; i++)
		EXPECT_EQ(8 * i, b[i]);

}
// 7
TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(6);

	EXPECT_EQ(3, a.size());
	EXPECT_EQ(6, b.size());

	b = a;
	
	EXPECT_EQ(a.size(), b.size());
	EXPECT_EQ(3, b.size());

}
// 8
TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(6);

	for (size_t i = 0; i < 3; i++)
		a[i] = 2*i + 1;
	b = a;
	EXPECT_EQ(a, b);
	EXPECT_EQ(3, b.size());
	for (size_t i = 0; i < 3; i++)
		EXPECT_EQ(2 * i + 1, b[i]);
}
// 9
TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);

	for (size_t i = 0; i < 3; i++)
		a[i] = b[i] = 85 + i;
	EXPECT_TRUE(a == b);
	EXPECT_FALSE(a != b);
}	
// 10
TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> a(3);
	a[0] = 1;
	a[1] = 2;
	a[2] = 3;
	a[3] = 4;

	EXPECT_TRUE(a == a);
	EXPECT_FALSE(a != a);
}
// 11
TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(6);

	for (size_t i = 0; i < 3; i++)
		a[i] = b[i] = 5 * i;
	EXPECT_FALSE(a == b);
	EXPECT_TRUE(a != b);
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);
	for (size_t i = 0; i < 3; i++) {
		a[i] = i;
		b[i] = i * 3 + 5;
	}
	TDynamicVector<int> res = a * 3 + 5;
	EXPECT_EQ(b, res);

	EXPECT_EQ(0, a[0]);
	EXPECT_EQ(1, a[1]);
	EXPECT_EQ(2, a[2]);
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);

	for (size_t i = 0; i < 3; i++) {
		a[i] = i + 3;
		b[i] = i;
	}
	TDynamicVector<int> res = a - 3;
	EXPECT_EQ(b, res);
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);

	for (size_t i = 0; i < 3; i++) {
		a[i] = i + 3;
		b[i] = (i + 3) * 3;
	}
	TDynamicVector<int> res = a * 3;
	EXPECT_EQ(b, res);

}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);
	TDynamicVector<int> c(3);

	for (size_t i = 0; i < 3; i++) {
		a[i] = i;
		b[i] = i * 2;
		c[i] = i * 3;
	}
	TDynamicVector<int> res = a + b;
	EXPECT_EQ(c, res);

}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(6);

	ASSERT_ANY_THROW(a + b);
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);
	TDynamicVector<int> c(3);
	for (size_t i = 0; i < 3; i++) {
		a[i] = i * 3;
		a[i] = i;
		c[i] = i * 2;

		TDynamicVector<int> res = a - b;
		EXPECT_EQ(c, res);
	}
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(6);
	ASSERT_ANY_THROW(a - b);
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(3);

	for (size_t i = 0; i < 3; i++) {
		a[i] = i + 1;
		b[i] = i + 2;
	}
	int res = a * b;
	EXPECT_EQ(20, res);
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> a(3);
	TDynamicVector<int> b(6);

	ASSERT_ANY_THROW(a * b);
}

