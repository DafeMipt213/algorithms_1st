
#include <gtest/gtest.h>

#include <stack>

#include "stack.hpp"

TEST(StackTest, Simple) {
  Stack<int> stack;
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
  Stack<std::string> Txtstack{"bruh", "code"};
  ASSERT_EQ(Txtstack.Get(), "code");
  Txtstack.Pop();
  ASSERT_EQ(Txtstack.Pop(), "bruh");
}

TEST(MinStackTest, Simple) {
  MinStack<int> stack;
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

TEST(StackTest, Exceptions) {
  Stack<int> stack;
  ASSERT_ANY_THROW(stack.Pop());
  ASSERT_ANY_THROW(stack.Get());
}

TEST(MinStackTest, Exceptions) {
  MinStack<int> stack;
  ASSERT_ANY_THROW(stack.Pop());
  ASSERT_ANY_THROW(stack.GetMin());
}