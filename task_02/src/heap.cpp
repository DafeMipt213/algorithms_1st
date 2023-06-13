#include <algorithm>
#include <heap.hpp>
#include <iostream>
#include <vector>
#include <cstddef>

void MinHeap::Push(int value) {
  heap.push_back(value);  // добавляем элемент в конец вектора
  Sift_up(heap.size() - 1);  // восстанавливаем свойство кучи
}

int MinHeap::Pop() {
  if(heap.empty()) throw std::out_of_range("heap empty");
  int min_value = heap[0];  // сохраняем минимальный элемент
  heap[0] = heap.back();  // заменяем корень на последний элемент вектора
  heap.pop_back();  // удаляем последний элемент вектора
  Sift_down(0);      // восстанавливаем свойство кучи
  return min_value;  // возвращаем минимальный элемент
}

bool MinHeap::Empty() const {
  return heap.empty();  // проверяем, пуста ли куча
}

void MinHeap::Sift_up(int index) {
  int parent_index = (index - 1) / 2;
  while (index > 0 && heap[parent_index] > heap[index]) {
    std::swap(heap[parent_index], heap[index]);
    index = parent_index;
    parent_index = (index - 1) / 2;
  }
}

void MinHeap::Sift_down(int index) {
  int left_child_index = index * 2 + 1;
  int right_child_index = index * 2 + 2;
  int min_index = index;
  if (left_child_index < heap.size() &&
      heap[left_child_index] < heap[min_index]) {
    min_index = left_child_index;
  }
  if (right_child_index < heap.size() &&
      heap[right_child_index] < heap[min_index]) {
    min_index = right_child_index;
  }
  if (min_index != index) {
    std::swap(heap[index], heap[min_index]);
    Sift_down(min_index);
  }
}
