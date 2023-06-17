#pragma once

#include <cstddef>
#include <vector>


class MinHeap {
public:
    void Push(int value);
    int Pop();
    [[nodiscard]] size_t Size() const;
    void Upd_Heap(size_t i);

private:
    std::vector<int> h;
    size_t HeapSize = 0;
};
