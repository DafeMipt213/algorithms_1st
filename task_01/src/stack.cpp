#include "stack.hpp"

#include <algorithm>
#include <cstring>
#include <stdexcept>

void Stack::Push(int value) {
  if (size == capacity) {
    int *new_data = new int[static_cast<unsigned long>(capacity) * 2];

    memcpy(new_data, data_, size * sizeof(int));
    delete[] data_;
    data_ = new_data;
    capacity *= 2;
  }
  data_[size] = value;
  size++;
}

Stack::Stack() : size(0), capacity(2) { data_ = new int[capacity]; }

int Stack::Pop() {
  if (size == 0)
    throw std::runtime_error("Empty stack error");
  size--;
  return data_[size];
}

MinStack::MinStack() : min_size(0), min_capacity(2), size(0), capacity(2) {
  data_ = new int[capacity];
  data_min = new int[min_capacity];
}

int MinStack::Top() {
  if (size == 0)
    throw std::runtime_error("Empty stack error");

  return data_[size];
}

void MinStack::Push(int value) {
  if (size == capacity) {
    int *new_data = new int[static_cast<int>(capacity) * 2];
    memcpy(new_data, data_, size * sizeof(int));

    delete[] data_;
    data_ = new_data;
    capacity *= 2;
  }
  ++size;
  data_[size] = value;

  if (min_size == 0) {
    data_min[min_size++] = value;
  } else {
    if (value <= data_min[min_size - 1]) {
      if (min_size == min_capacity) {
        int *new_min_data = new int[capacity * 2];
        memcpy(new_min_data, data_min, size * sizeof(*data_min));
        delete[] data_min;
        data_min = new_min_data;
        min_capacity *= 2;
      }
      data_min[min_size++] = value;
    }
  }
}

int MinStack::Pop() {
  if (size == 0)
    throw std::runtime_error("Empty stack error");
  if (data_[size - 1] == data_min[min_size]) {
    min_size--;
  }
  size--;
  return data_[size + 1];
}

int MinStack::GetMin() {
  if (min_size == 0)
    throw std::runtime_error("No minimum error");
  return data_min[min_size - 1];
}