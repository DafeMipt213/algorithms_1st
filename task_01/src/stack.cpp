#include "stack.hpp"

bool Stack::isEmpty() { return top == -1; }

bool Stack::isFull() { return top == MAX_SIZE - 1; }

void Stack::Push(int value) {
  if (Stack::isFull()) {
    return;
  }
  top++;
  data[top] = value;
}

int Stack::Top(){
  return data[top];
}

int Stack::Pop() {
  if (Stack::isEmpty()) {
    return -1;
  }
  int value = data[top];
  top--;
  return value;
}

void MinStack::Push(int x) {
        // добавляем элемент в стек
        stack_.Push(x);

        // обновляем минимальное значение
        if (min_stack_.isEmpty() || x <= min_stack_.Top()) {
            min_stack_.Push(x);

        }
    }

    int MinStack::Pop() {
        // удаляем элемент из стека
        if (stack_.Top() == min_stack_.Top()) {
            min_stack_.Pop();
        }
        return stack_.Pop();
    }

    int MinStack::Top() {
        return stack_.Top();
    }

    int MinStack::GetMin() {
        return min_stack_.Top();
    }