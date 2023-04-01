
#include <gtest/gtest.h>

#include "heap.hpp"

TEST(HeapTest, Simple) {
  MinHeap<int> heap;
  heap.Push(1);
  ASSERT_EQ(heap.Pop(), 1);
}

TEST(HeapTest, Basic) {
  MinHeap<int> heap;
  heap.Push(1);
  heap.Push(2);
  heap.Push(3);              // [1, 2, 3]
  ASSERT_EQ(heap.Pop(), 1);  // [2, 3] -> 1
  ASSERT_EQ(heap.Pop(), 2);  // [3] -> 2
  ASSERT_EQ(heap.Pop(), 3);  // [] -> 3
}

TEST(HeapTest, Empty) {
  MinHeap<int> heap;
  ASSERT_ANY_THROW(heap.Pop());
  heap.Push(1);
  ASSERT_EQ(heap.Pop(), 1);  // [(1), 2, 3]
  ASSERT_ANY_THROW(heap.Pop());
}

TEST(HeapTest, minElement) {
  MinHeap<int> heap;
  ASSERT_ANY_THROW(heap.getMin());
  heap.Push(6);              // [6]
  heap.Push(2);              // [2, 6]
  heap.Push(3);              // [2, 3, 6]
  heap.Push(5);              // [2, 3, 5, 6]
  heap.Push(4);              // [2, 3, 4, 5, 6]
  ASSERT_EQ(heap.getMin(), 2); 
  heap.Clear();
  ASSERT_EQ(heap.Size(), 0);  
}

TEST(HeapTest, maxElement) {
  MinHeap<int> heap;
  ASSERT_ANY_THROW(heap.getMax());
  heap.Push(6);              // [6]
  heap.Push(2);              // [2, 6]
  heap.Push(3);              // [2, 3, 6]
  heap.Push(5);              // [2, 3, 5, 6]
  heap.Push(4);              // [2, 3, 4, 5, 6]
  ASSERT_EQ(heap.getMax(), 6); 
  heap.Clear();
  ASSERT_EQ(heap.Size(), 0);  
}

TEST(HeapTest, minElementChar) {
  MinHeap<char> heap;
  ASSERT_ANY_THROW(heap.getMin());
  heap.Push('k');              // ['k']
  heap.Push('l');              // ['k', 'l']
  heap.Push('h');              // ['k', 'l', 'h']
  heap.Push('b');              // ['k', 'l', 'h', 'b']
  heap.Push('p');              // ['k', 'l', 'h', 'b', 'p']
  ASSERT_EQ(heap.getMin(), 'b'); 
  heap.Clear();
  ASSERT_EQ(heap.Size(), 0);  
}

TEST(HeapTest, maxElementChar) {
  MinHeap<char> heap;
  ASSERT_ANY_THROW(heap.getMax());
  heap.Push('k');              // ['k']
  heap.Push('l');              // ['k', 'l']
  heap.Push('h');              // ['k', 'l', 'h']
  heap.Push('p');              // ['k', 'l', 'h', 'p']
  heap.Push('b');              // ['k', 'l', 'h', 'p', 'b']
  ASSERT_EQ(heap.getMax(), 'p'); 
  heap.Clear();
  ASSERT_EQ(heap.Size(), 0);  
}

TEST(HeapTest, Complex) {
  MinHeap<int> heap;
  heap.Push(6);              // [6]
  heap.Push(1);              // [1, 6]
  heap.Push(2);              // [1, 2, 6]
  heap.Push(3);              // [1, 2, 3, 6]
  heap.Push(5);              // [1, 2, 3, 5, 6]
  heap.Push(4);              // [1, 2, 3, 4, 5, 6]
  ASSERT_EQ(heap.Pop(), 1);  // [2, 3, 4, 5, 6] -> 1
  ASSERT_EQ(heap.Pop(), 2);  // [3, 4, 5, 6] -> 2
  ASSERT_EQ(heap.getMin(), 3);
  ASSERT_EQ(heap.Pop(), 3);  // [4, 5, 6] -> 3
  ASSERT_EQ(heap.Pop(), 4);  // [5, 6] -> 4
  ASSERT_EQ(heap.Pop(), 5);  // [6] -> 5
  heap.Push(7);              // [6, 7]
  heap.Push(1);              // [1, 6, 7]
  ASSERT_EQ(heap.getMax(), 7);
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