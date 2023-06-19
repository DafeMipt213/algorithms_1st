#include "stack.hpp"

bool Stack::IsEmpty() { return top == -1; }

bool Stack::IsFull() { return top == MAX_SIZE - 1; }

void Stack::Push(int value) {
  if (Stack::IsFull()) {
    throw std::out_of_range("Stack full item not push");
  }
  top++;
  data[top] = value;
}

int Stack::Top() { return data[top]; }

int Stack::Pop() {
  if (Stack::IsEmpty()) {
    throw std::out_of_range("Empty stack");
  }
  int value = data[top];
  top--;
  return value;
}

void MinStack::Push(int x) {
  stack_.Push(x);

  // обновляем минимальное значение
  if (min_stack_.IsEmpty() || x <= min_stack_.Top()) {
    min_stack_.Push(x);
  }
}

int MinStack::Pop() {
  if (stack_.IsEmpty()) {
    throw std::out_of_range("Empty stack");
  }
  if (stack_.Top() == min_stack_.Top()) {
    min_stack_.Pop();
  }
  return stack_.Pop();
}

int MinStack::Top() { return stack_.Top(); }

int MinStack::GetMin() { return min_stack_.Top(); }