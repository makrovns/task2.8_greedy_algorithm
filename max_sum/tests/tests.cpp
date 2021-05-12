#include "max_sum_in_matrix_library.hpp"
#include <gtest/gtest.h>

TEST(max_sum_matrix_test, example_one_from_task)
{
    mymatrix::Matrix arr = { {0,6,0},{5,8,7},{0,9,0} };

    // 0 6 0
    // 5 8 7    9 -> 8 -> 7
    // 0 9 0

    ASSERT_EQ(24, arr.max_sum());
}

TEST(max_sum_matrix_test, example_two_from_task)
{
    mymatrix::Matrix arr = { { 1, 0, 7},{2, 0, 6},{3, 4, 5}, {0, 3, 0}, {9, 0, 20}};

    // 1 0 7
    // 2 0 6
    // 3 4 5     1 -> 2 -> 3 -> 4 -> 5 -> 6 ->7
    // 0 3 0
    // 9 0 20
    
    ASSERT_EQ(28, arr.max_sum());
}

TEST(max_sum_matrix_test, for_zero_input)
{
    mymatrix::Matrix arr;

    ASSERT_EQ(0, arr.max_sum());
}

TEST(max_sum_matrix_test, two_element_input)
{
    mymatrix::Matrix arr = {{1, 0, 2}};

    ASSERT_EQ(2, arr.max_sum());
}

TEST(max_sum_matrix_test, four_non_zero_in)
{
    mymatrix::Matrix arr = {{5,1,0}, {4,0,0}, {3,0,9}};

    // 5 1 0
    // 4 0 0    1 -> 5 -> 4 -> 3
    // 3 0 9

    ASSERT_EQ(13, arr.max_sum());
}

TEST(max_sum_matrix_test, some_input_mat)
{
    mymatrix::Matrix arr = {{0,0,1,4}, {8,3,0,6}, {5,0,3,8}, {0,12,2,7}, {5,0,1,3}};

    // 0  0  1  4
    // 8  3  0  6
    // 5  0  3  8   1 -> 4 -> 6 -> 8 -> 7 -> 3 -> 1 -> 2 -> 12
    // 0  12 2  7
    // 5  0  1  3

    ASSERT_EQ(44, arr.max_sum());
}

TEST(max_sum_matrix_test, only_coloms)
{
    mymatrix::Matrix arr = {{2},{6},{2},{0},{0},{4},{5}};

    // 2 -> 6 -> 2

    ASSERT_EQ(10, arr.max_sum());
}

TEST(max_sum_matrix_test, test_only_rows)
{
    mymatrix::Matrix arr = {{1,5,7,2,0,6,4,8}};

    //8 -> 4 -> 6

    ASSERT_EQ(18, arr.max_sum());
}

TEST(max_sum_matrix_test, test_for_assign)
{
    mymatrix::Matrix arr = {{4,8,0,6,3}, {5,7,0,0,2}, {1,0,5,4,1}, {4,0,6,0,0}};

    // 4 8 0 6 3
    // 5 7 0 0 2     4 -> 1 -> 5 -> 7 -> 8 -> 4
    // 1 0 5 4 1
    // 4 0 6 0 0

    ASSERT_EQ(29, arr.max_sum());

    arr = {{3,5,0,6}, {1,8,0,4}, {2,4,0,5}};

    // 3 5 0 6
    // 1 8 0 4  2 -> 4 -> 8 -> 5 -> 3 -> 1
    // 2 4 0 5

    ASSERT_EQ(23, arr.max_sum());
}

TEST(max_sum_matrix_test, test_get_Sum)
{
    mymatrix::Matrix arr = {{4,8,0,6,3}, {5,7,0,0,2}, {1,0,5,4,1}, {4,0,6,0,0}};

    arr.max_sum();

    // 4 8 0 6 3
    // 5 7 0 0 2     4 -> 1 -> 5 -> 7 -> 8 -> 4
    // 1 0 5 4 1
    // 4 0 6 0 0

    ASSERT_EQ(29, arr.getSum());

    arr = {{3,5,0,6}, {1,8,0,4}, {2,4,0,5}};

    arr.max_sum();

    // 3 5 0 6
    // 1 8 0 4  2 -> 4 -> 8 -> 5 -> 3 -> 1
    // 2 4 0 5

    ASSERT_EQ(23, arr.getSum());
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);

    return RUN_ALL_TESTS();
}
