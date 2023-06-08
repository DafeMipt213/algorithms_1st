#pragma once

#include <stack>
#include <vector>

class Stack {
public:
    Stack();
    void Push(int value);
    int Pop();
    int Top();

    ~Stack() {
        delete[] data_;
    }

private:
    int* data_;
    std::size_t size;
    std::size_t capacity;
};

class MinStack {
public:
    MinStack();
    void Push(int value);
    int Pop();
    int GetMin();
    int Top();

    ~MinStack() {
        delete[] data_;
        delete[] data_min;
    }

private:
    int* data_;
    int* data_min;
    std::size_t min_size;
    std::size_t size;
    std::size_t min_capacity;
    std::size_t capacity;
};
