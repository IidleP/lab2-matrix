#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}
// 1
TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;

	TDynamicMatrix<int> copy(a);

	EXPECT_EQ(1, copy[0][0]);
	EXPECT_EQ(2, copy[0][1]);
	EXPECT_EQ(3, copy[1][0]);
	EXPECT_EQ(4, copy[1][1]);
}
// 2
TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	
	TDynamicMatrix<int> copy(a);
	copy[0][0] = 6;
	EXPECT_EQ(1, a[0][0]);
	EXPECT_EQ(6, copy[0][0]);
}
// 3
TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> a(4);
	EXPECT_EQ(4, a.size());
	TDynamicMatrix<int> b(7);
	EXPECT_EQ(7, b.size());

}
// 4
TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> a(3);

	a[0][0] = 11;
	a[1][1] = 22;
	a[2][2] = 33;
	a[0][2] = 44;

	EXPECT_EQ(11, a[0][0]);
	EXPECT_EQ(22, a[1][1]);
	EXPECT_EQ(33, a[2][2]);
	EXPECT_EQ(44, a[0][2]);

	EXPECT_EQ(0, a[1][0]);
	EXPECT_EQ(0, a[2][1]);
}
// 5
TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> a(3);
	ASSERT_ANY_THROW(a.at(-1));
	ASSERT_ANY_THROW(a.at(0).at(-1));

}
// 6
TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> a(3);

	ASSERT_ANY_THROW(a.at(3));
	ASSERT_ANY_THROW(a.at(11));
}
// 7
TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	ASSERT_NO_THROW(a = a);
	EXPECT_EQ(1, a[0][0]);
	EXPECT_EQ(2, a[0][1]);
	EXPECT_EQ(3, a[1][0]);
	EXPECT_EQ(4, a[1][1]);
}
// 8
TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> b(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	b[0][0] = 5;
	b[0][1] = 6;
	b[1][0] = 7;
	b[1][1] = 8;
	b = a;
	EXPECT_EQ(a, b);
	EXPECT_EQ(1, b[0][0]);
	EXPECT_EQ(2, b[0][1]);
	EXPECT_EQ(3, b[1][0]);
	EXPECT_EQ(4, b[1][1]);
}
// 9
TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> b(4);

	EXPECT_EQ(2, a.size());
	EXPECT_EQ(4, b.size());

	b = a;
	EXPECT_EQ(a.size(), b.size());
	EXPECT_EQ(2, b.size());
}
// 10
TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> b(3);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	b = a;
	EXPECT_EQ(a, b);
	EXPECT_EQ(2, b.size());
	EXPECT_EQ(1, b[0][0]);
	EXPECT_EQ(2, b[0][1]);
	EXPECT_EQ(3, b[1][0]);
	EXPECT_EQ(4, b[1][1]);
}
// 11
TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> b(2);
	a[0][0] = b[0][0] = 1;
	a[0][1] = b[0][1] = 2;
	a[1][0] = b[1][0] = 3;
	a[1][1] = b[1][1] = 4;
	EXPECT_TRUE(a == b);
	EXPECT_FALSE(a != b);
}
// 12
TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> a(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	EXPECT_TRUE(a == a);
	EXPECT_FALSE(a != a);
}
// 13
TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> b(3);
	a[0][0] = b[0][0] = 1;
	a[0][1] = b[0][1] = 2;
	a[1][0] = b[1][0] = 3;
	a[1][1] = b[1][1] = 4;

	EXPECT_FALSE(a == b);
	EXPECT_TRUE(a != b);
}
// 14
TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> b(2);
	TDynamicMatrix<int> c(2);
	a[0][0] = 1;
	a[0][1] = 2;
	a[1][0] = 3;
	a[1][1] = 4;
	b[0][0] = 5;
	b[0][1] = 6;
	b[1][0] = 7;
	b[1][1] = 8;
	c[0][0] = 6;
	c[0][1] = 8;
	c[1][0] = 10;
	c[1][1] = 12;
	TDynamicMatrix<int> res = a + b;
	EXPECT_EQ(c, res);
	EXPECT_EQ(6, res[0][0]);
	EXPECT_EQ(8, res[0][1]);
	EXPECT_EQ(10, res[1][0]);
	EXPECT_EQ(12, res[1][1]);
}
// 15
TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> b(3);
	ASSERT_ANY_THROW(a + b);
}
// 16
TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> b(2);
	TDynamicMatrix<int> c(2);

	a[0][0] = 10;
	a[0][1] = 9;
	a[1][0] = 8;
	a[1][1] = 7;

	b[0][0] = 6;
	b[0][1] = 5;
	b[1][0] = 4;
	b[1][1] = 3;

	c[0][0] = 4;
	c[0][1] = 4;
	c[1][0] = 4;
	c[1][1] = 4;

	TDynamicMatrix<int> res = a - b;

	EXPECT_EQ(c, res);
}
// 17
TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> a(2);
	TDynamicMatrix<int> b(3);

	ASSERT_ANY_THROW(a - b);
}

