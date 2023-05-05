#pragma once
#include <vector>
#include <iostream>

template<typename Elem_Type>
class Heap{
private:
    Elem_Type* array;
    std::size_t Heap_Size;
    size_t SIZE;
public:
    Heap(size_t size){
        array = new Elem_Type[size];
        Heap_Size = 0;
        SIZE = size;
    }

    void addelem(int n) {
        int i, parent;
        i = Heap_Size;
        array[i] = n;
        parent = (i-1)/2;
        while(parent >= 0 && i > 0)  {
            if(array[i] > array[parent]) {
                Elem_Type temp = array[i];
                array[i] = array[parent];
                array[parent] = temp;
            }
            i = parent;
            parent = (i-1)/2;
        }
        ++Heap_Size;
    }

    void outHeap() {
        int i = 0;
        int k = 1;
        while(i < Heap_Size) {
            while((i < k) && (i < Heap_Size)) {
                std::cout << array[i] << " ";
                i++;
            }
            std::cout << std::endl;
            k = k * 2 + 1;
        }
    }

    void out() {
        for(int i=0; i< Heap_Size; i++) {
            std::cout << array[i] << " "; }
        std::cout << std::endl;
    }

    void heapify(int i) {
        int left, right;
        Elem_Type temp;
        left = 2*i+1;
        right = 2*i+2;
        if(left < Heap_Size) {
            if(array[i] < array[left]) {
                temp = array[i];
                array[i] = array[left];
                array[left] = temp;
                heapify(left);
            }
        }
        if(right < Heap_Size) {
            if(array[i] < array[right]) {
                temp = array[i];
                array[i] = array[right];
                array[right] = temp;
                heapify(right);
            }
        }
    }

    int getmax() {
        Elem_Type x;
        x = array[0];
        array[0] = array[Heap_Size-1];
        --Heap_Size;
        heapify(0);
        return(x);
    }

};

