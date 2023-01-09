
#include <gtest/gtest.h>

#include "heap.hpp"

TEST(HeapTest, Simple) {
  MinHeap heap;
  heap.Push(1);
  heap.Push(2);
  heap.Push(3);
  ASSERT_EQ(heap.Pop(), 1);
  ASSERT_EQ(heap.Pop(), 2);
  ASSERT_EQ(heap.Pop(), 3);
  heap.Push(6);
  heap.Push(1);
  heap.Push(2);
  heap.Push(3);
  heap.Push(5);
  heap.Push(4);
  ASSERT_EQ(heap.Pop(), 1);
  ASSERT_EQ(heap.Pop(), 2);
  ASSERT_EQ(heap.Pop(), 3);
  ASSERT_EQ(heap.Pop(), 4);
  ASSERT_EQ(heap.Pop(), 5);
  ASSERT_EQ(heap.Pop(), 6);
  heap.Push(6);
  heap.Push(1);
  heap.Push(2);
  ASSERT_EQ(heap.Pop(), 1);
  heap.Push(3);
  heap.Push(5);
  heap.Push(4);
  ASSERT_EQ(heap.Pop(), 2);
  ASSERT_EQ(heap.Pop(), 3);
  ASSERT_EQ(heap.Pop(), 4);
  ASSERT_EQ(heap.Pop(), 5);
  ASSERT_EQ(heap.Pop(), 6);
}