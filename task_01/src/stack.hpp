#pragma once

#include <stack>
#include <cstddef>
#include <new>
#include <iostream>
#include <vector>


template <typename Elem_Type>
class Stack {
protected:
    std::size_t _size = 0;
    std::vector<Elem_Type> _stack;
public:
    explicit Stack(size_t maxSize) {
        _stack = std::vector<Elem_Type>(maxSize);
    }

    Stack(std::initializer_list<Elem_Type> list) {
        _size = list.size();
        for (auto i: list)
            _stack.push_back(i);
    }

    Stack() {
        _stack = std::vector<Elem_Type>(2);
    }

    Stack(const Stack<Elem_Type>& other) {
        _size = other._size;
        _stack = other._stack;
    };

    Stack<Elem_Type>& operator=(const Stack<Elem_Type>& other) {
        if (this == &other) {
            return *this;
        }
        _size = other._size;
        _stack = other._stack;
        return *this;
    };

    ~Stack() = default;

    virtual void push(Elem_Type newel) noexcept {
        _stack.push_back(newel);
    };

    virtual void pop() noexcept {
        if (_size != 0) {
            --_size;
        }
    };

    Elem_Type top() const noexcept {
        if (!_stack.empty())
            return *_stack.rbegin();
    }

    size_t size() const noexcept {
        return _size;
    }

    friend std::ostream& operator<<(std::ostream& os, const Stack<Elem_Type>& stack) {
        for (std::size_t i = 0; i < stack._size; ++i)
            os << stack._stack[i] << ' ';
        return os;
    }
};



class MinStack {
 public:
  void Push(int value);
  int Pop();
  int GetMin();

 private:
  std::vector<int> data_;
};