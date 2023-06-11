
#include <gtest/gtest.h>

#include <stack>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack stack;
  stack.Push(1);             // Stack [1]
  ASSERT_EQ(stack.Pop(), 1); // Stack []
  stack.Push(1);             // Stack [1]
  stack.Push(2);             // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2); // Stack [1]
  ASSERT_EQ(stack.Pop(), 1); // Stack []
  stack.Push(1);             // Stack [1]
  stack.Push(2);             // Stack [1, 2]
  ASSERT_EQ(stack.Pop(), 2); // Stack [1]
  stack.Push(3);             // Stack [1, 3]
  ASSERT_EQ(stack.Pop(), 3); // Stack [1]
  ASSERT_EQ(stack.Pop(), 1); // Stack []
}

TEST(MinStackTest, Simple) {
  MinStack stack;
  stack.Push(1); // Stack [1]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 1); // Stack []
  stack.Push(1);             // Stack [1]
  stack.Push(2);             // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2); // Stack [1]
  ASSERT_EQ(stack.Pop(), 1); // Stack []
  stack.Push(1);             // Stack [1]
  stack.Push(2);             // Stack [1, 2]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 2); // Stack [1]
  stack.Push(3);             // Stack [1, 3]
  ASSERT_EQ(stack.GetMin(), 1);
  ASSERT_EQ(stack.Pop(), 3); // Stack [1]
  ASSERT_EQ(stack.Pop(), 1); // Stack []
}

TEST(MinStackTest, Simple1) {
  MinStack stack;
  stack.Push(6); // Stack [6]
  stack.Push(5); // Stack [6,5]
  stack.Push(4); // Stack [6,5,4]
  stack.Push(3); // Stack [6,5,4,3]
  stack.Push(2); // Stack [6,5,4,3,2]
  stack.Push(1); // Stack [6,5,4,3,2,1]
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 2);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 3);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 4);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 5);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 6);
}

TEST(MinStackTest, Simple2) {
  MinStack stack;
  stack.Push(1); // Stack [1]
  stack.Push(2); // Stack [1,2]
  stack.Push(3); // Stack [1,2,3]
  stack.Push(4); // Stack [1,2,3,4]
  stack.Push(5); // Stack [1,2,3,4,5]
  stack.Push(6); // Stack [1,2,3,4,5,6]
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 1);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 1);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 1);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 1);
  stack.Pop();
  ASSERT_EQ(stack.GetMin(), 1);
}