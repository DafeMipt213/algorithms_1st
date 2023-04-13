#pragma once

#include <cstddef>
#include <functional>
#include <queue>
#include <vector>

class MinHeap {
public:
    MinHeap();
    int Size();
    void Push(int value);
    int Pop();
    int getLast();
    void Last();

private:
    std::vector<int> data_;
    int size;
    int left_child(int i);
    int right_child(int i);
    int parent(int i);
    void sift_up(int i);
    void sift_down(int i);
};