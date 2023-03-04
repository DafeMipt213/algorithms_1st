
#include <gtest/gtest.h>

#include "heap.hpp"

TEST(HeapTest, SimpleInt) {
  MinHeap<int> heap;
  heap.Push(1);
  ASSERT_EQ(heap.Pop(), 1);
}

TEST(HeapTest, BasicInt) {
  MinHeap<int> heap;
  heap.Push(1);
  heap.Push(2);
  heap.Push(3);              // [1, 2, 3]
  ASSERT_EQ(heap.Pop(), 1);  // [2, 3] -> 1
  ASSERT_EQ(heap.Pop(), 2);  // [3] -> 2
  ASSERT_EQ(heap.Pop(), 3);  // [] -> 3
}

TEST(HeapTest, EqualInt) {
  MinHeap<int> heap;
  for (int i = 0; i < 3; ++i) {
    heap.Push(1);
    heap.Push(2);
  }
  ASSERT_EQ(heap.Pop(), 1);
  ASSERT_EQ(heap.Pop(), 1);
  ASSERT_EQ(heap.Pop(), 1);
  ASSERT_EQ(heap.Pop(), 2);
}

TEST(HeapTest, EmptyInt) {
  MinHeap<int> heap;
  ASSERT_ANY_THROW(heap.Pop());
  heap.Push(1);
  ASSERT_EQ(heap.Pop(), 1);  // [(1), 2, 3]
  ASSERT_ANY_THROW(heap.Pop());
}

TEST(HeapTest, ComplexInt) {
  MinHeap<int> heap;
  heap.Push(6);              // [6]
  heap.Push(1);              // [1, 6]
  heap.Push(2);              // [1, 2, 6]
  heap.Push(3);              // [1, 2, 3, 6]
  heap.Push(5);              // [1, 2, 3, 5, 6]
  heap.Push(4);              // [1, 2, 3, 4, 5, 6]
  ASSERT_EQ(heap.Pop(), 1);  // [2, 3, 4, 5, 6] -> 1
  ASSERT_EQ(heap.Pop(), 2);  // [3, 4, 5, 6] -> 2
  ASSERT_EQ(heap.Pop(), 3);  // [4, 5, 6] -> 3
  ASSERT_EQ(heap.Pop(), 4);  // [5, 6] -> 4
  ASSERT_EQ(heap.Pop(), 5);  // [6] -> 5
  heap.Push(7);              // [6, 7]
  heap.Push(1);              // [1, 6, 7]
  heap.Push(2);              // [1, 2, 6, 7]
  ASSERT_EQ(heap.Pop(), 1);  // [2, 6, 7] -> 1
  heap.Push(3);              // [2, 3, 6, 7]
  heap.Push(5);              // [2, 3, 5, 6, 7]
  heap.Push(4);              // [2, 3, 4, 5, 6, 7]
  ASSERT_EQ(heap.Pop(), 2);  // [3, 4, 5, 6, 7] -> 2
  ASSERT_EQ(heap.Pop(), 3);  // [4, 5, 6, 7] -> 3
  ASSERT_EQ(heap.Pop(), 4);  // [5, 6, 7] -> 4
  ASSERT_EQ(heap.Pop(), 5);  // [6, 7] -> 5
  ASSERT_EQ(heap.Pop(), 6);  // [7] -> 6
  ASSERT_EQ(heap.Pop(), 7);  // [] -> 7
}

TEST(HeapTest, SimpleDouble) {
  MinHeap<double> heap;
  heap.Push(1.1);
  ASSERT_EQ(heap.Pop(), 1.1);
}

TEST(HeapTest, BasicDouble) {
  MinHeap<double> heap;
  heap.Push(1.9);
  heap.Push(2.0);
  heap.Push(3.4);              // [1.9, 2.0, 3.4]
  ASSERT_EQ(heap.Pop(), 1.9);  // [2.0, 3.4] -> 1.9
  ASSERT_EQ(heap.Pop(), 2.0);  // [3.4] -> 2.0
  ASSERT_EQ(heap.Pop(), 3.4);  // [] -> 3.4
}

TEST(HeapTest, EqualDouble) {
  MinHeap<double> heap;
  for (int i = 0; i < 3; ++i) {
    heap.Push(1.1);
    heap.Push(2.2);
  }
  ASSERT_EQ(heap.Pop(), 1.1);
  ASSERT_EQ(heap.Pop(), 1.1);
  ASSERT_EQ(heap.Pop(), 1.1);
  ASSERT_EQ(heap.Pop(), 2.2);
}


TEST(HeapTest, EmptyDouble) {
  MinHeap<double> heap;
  ASSERT_ANY_THROW(heap.Pop());
  heap.Push(1.8);
  ASSERT_EQ(heap.Pop(), 1.8);  // [(1.8), 2, 3]
  ASSERT_ANY_THROW(heap.Pop());
}

TEST(HeapTest, ComplexDouble) {
  MinHeap<double> heap;
  heap.Push(6.7);              // [6.7]
  heap.Push(1.5);              // [1.5, 6.7]
  heap.Push(2.4);              // [1.5, 2.4, 6.7]
  heap.Push(3.2);              // [1.5, 2.4, 3.2, 6.7]
  heap.Push(5.7);              // [1.5, 2.4, 3.2, 5.7, 6.7]
  heap.Push(4.8);              // [1.5, 2.4, 3.2, 4.8, 5.7, 6.7]
  ASSERT_EQ(heap.Pop(), 1.5);  // [2.4, 3.2, 4.8, 5.7, 6.7] -> 1.5
  ASSERT_EQ(heap.Pop(), 2.4);  // [3.2, 4.8, 5.7, 6.7] -> 2.4
  ASSERT_EQ(heap.Pop(), 3.2);  // [4.8, 5.7, 6.7] -> 3.2
  ASSERT_EQ(heap.Pop(), 4.8);  // [5.7, 6.7] -> 4.8
  ASSERT_EQ(heap.Pop(), 5.7);  // [6.7] -> 5.7
  heap.Push(7.4);              // [6.7, 7.4]
  heap.Push(1.8);              // [1.8, 6.7, 7.4]
  heap.Push(2.4);              // [1.8, 2.4, 6.7, 7.4]
  ASSERT_EQ(heap.Pop(), 1.8);  // [2.4, 6.7, 7.4] -> 1.8
  heap.Push(3.5);              // [2.4, 3.5, 6.7, 7.4]
  heap.Push(5.8);              // [2.4, 3.5, 5.8, 6.7, 7.4]
  heap.Push(4.9);              // [2.4, 3.5, 4.9, 5.8, 6.7, 7.4]
  ASSERT_EQ(heap.Pop(), 2.4);  // [3.5, 4.9, 5.8, 6.7, 7.4] -> 2.4
  ASSERT_EQ(heap.Pop(), 3.5);  // [4.9, 5.8, 6.7, 7.4] -> 3.5
  ASSERT_EQ(heap.Pop(), 4.9);  // [5.8, 6.7, 7.4] -> 4.9
  ASSERT_EQ(heap.Pop(), 5.8);  // [6.7, 7.4] -> 5.8
  ASSERT_EQ(heap.Pop(), 6.7);  // [7.4] -> 6.7
  ASSERT_EQ(heap.Pop(), 7.4);  // [] -> 7.4
}