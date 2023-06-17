
#include <gtest/gtest.h>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack stack;
  stack.Push(1);              // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}

TEST(StackTest, Exceptions) {
  Stack stack;
  EXPECT_THROW(stack.Pop(), std::out_of_range);
  EXPECT_THROW(stack.GetLast(), std::out_of_range);
}

TEST(MinStackTest, Simple) {
  MinStack stack;
  stack.Push(1);  // Stack [1]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
  stack.Push(1);              // Stack [1]
  stack.Push(2);              // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2);  // Stack [1]
  stack.Push(3);              // Stack [1, 3]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 3);  // Stack [1]
  ASSERT_EQ(stack.Pop(), 1);  // Stack []
}

TEST(MinStackTest, Exceptions) {
  MinStack stack;
  EXPECT_THROW(stack.Pop(), std::out_of_range);
  EXPECT_THROW(stack.GetMin(), std::out_of_range);
}

TEST(StackTest, Complex) {
  Stack stack;  // []
  EXPECT_THROW(stack.Pop(), std::out_of_range);
  EXPECT_THROW(stack.GetLast(), std::out_of_range);
  stack.Push(5);  // [5]
  ASSERT_EQ(stack.GetLast(), 5);
  stack.Push(4);  // [5, 4]
  stack.Push(7);  // [5, 4, 7]
  ASSERT_EQ(stack.GetLast(), 7);
  stack.Push(-10);  // [5, 4, 7, -10]
  stack.Push(1);    // [5, 4, 7, -10, 1]
  ASSERT_EQ(stack.GetLast(), 1);
  stack.Push(-4);               // [5, 4, 7, -10, 1, -4]
  ASSERT_EQ(stack.Pop(), -4);   // [5, 4, 7, -10, 1] -> -4
  ASSERT_EQ(stack.Pop(), 1);    // [5, 4, 7, -10] -> 1
  ASSERT_EQ(stack.Pop(), -10);  // [5, 4, 7] -> -10
  ASSERT_EQ(stack.Pop(), 7);    // [5, 4] -> 7
  ASSERT_EQ(stack.GetLast(), 4);
  stack.Push(-3);  // [5, 4, -3]
  ASSERT_EQ(stack.GetLast(), -3);
  ASSERT_EQ(stack.Pop(), -3);  // [5, 4] -> -3
  ASSERT_EQ(stack.Pop(), 4);   // [5] -> 4
  ASSERT_EQ(stack.GetLast(), 5);
  ASSERT_EQ(stack.Pop(), 5);  // [] -> 5
  EXPECT_THROW(stack.Pop(), std::out_of_range);
  EXPECT_THROW(stack.GetLast(), std::out_of_range);
}

TEST(MinStackTest, Complex) {
  MinStack stack;  // []
  EXPECT_THROW(stack.Pop(), std::out_of_range);
  EXPECT_THROW(stack.GetMin(), std::out_of_range);
  stack.Push(3);  // [3]
  ASSERT_EQ(stack.GetMin(), 3);
  stack.Push(10);  // [3, 10]
  ASSERT_EQ(stack.GetMin(), 3);
  stack.Push(-7);  // [3, 10, -7]
  ASSERT_EQ(stack.GetMin(), -7);
  ASSERT_EQ(stack.Pop(), -7);  // [3, 10] -> -7
  ASSERT_EQ(stack.GetMin(), 3);
  stack.Push(100);  // [3, 10, 100]
  ASSERT_EQ(stack.GetMin(), 3);
  stack.Push(-1);  // [3, 10, 100, -1]
  ASSERT_EQ(stack.GetMin(), -1);
  stack.Push(-17);  // [3, 10, 100, -1, -17]
  ASSERT_EQ(stack.GetMin(), -17);
  ASSERT_EQ(stack.Pop(), -17);  // [3, 10, 100, -1] -> -17
  ASSERT_EQ(stack.GetMin(), -1);
  stack.Push(200);  // [3, 10, 100, -1, 200]
  ASSERT_EQ(stack.GetMin(), -1);
  ASSERT_EQ(stack.Pop(), 200);  // [3, 10, 100, -1] -> 200
  ASSERT_EQ(stack.GetMin(), -1);
  ASSERT_EQ(stack.Pop(), -1);  // [3, 10, 100] -> -1
  ASSERT_EQ(stack.GetMin(), 3);
  ASSERT_EQ(stack.Pop(), 100);  // [3, 10] -> 100
  ASSERT_EQ(stack.GetMin(), 3);
  ASSERT_EQ(stack.Pop(), 10);  // [3] -> 10
  ASSERT_EQ(stack.GetMin(), 3);
  ASSERT_EQ(stack.Pop(), 3);  // [] -> 3
  EXPECT_THROW(stack.Pop(), std::out_of_range);
  EXPECT_THROW(stack.GetMin(), std::out_of_range);
}