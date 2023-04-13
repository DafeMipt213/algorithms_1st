#include "stack.hpp"

bool Stack::isEmpty() {return top == -1;}

bool Stack::isFull() {
    return top == MAX_SIZE - 1;
}

void Stack::Push(int value) {
    if (Stack::isFull()) {
        return;
    }
    top++;
    data[top] = value;
}

int Stack::Pop() {
    if (Stack::isEmpty()) {
        return -1;
    }
    int value = data[top];
    top--;
    return value;
}

bool MinStack::isEmpty() {
    return top == -1;
}

bool MinStack::isFull() {
    return top == MAX_SIZE - 1;
}

void MinStack::Push(int value) {
    if (MinStack::isEmpty()) {
        min = value;
    }
    if (MinStack::isFull()) {
        return;
    }
    top++;
    data[(int)top] = value;
}

int MinStack::Pop() { 
    if (MinStack::isEmpty()) { 
        return -1; 
    } 
    int value = data[top]; 
    top--; 
    return value; 
}
int MinStack::GetMin() { return min; }