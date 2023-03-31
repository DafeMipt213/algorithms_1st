#pragma once

#include <cstddef>
#include <functional>
#include <queue>
#include <vector>
#include <stdexcept>
#include <cstddef>
#include <iostream>

template <typename T>
class MinHeap;

template <>
class MinHeap<int> {
public:
    void Push(int value) {
        data_.push_back(value);
        SiftUp(data_.size()-1);
    }

    int Pop() {
        if (data_.empty()) throw std::out_of_range("Empty heap");
        auto result = data_[0];
        data_[0] = data_[data_.size()-1];
        data_.pop_back();
        if (!data_.empty()) SiftDown(0);
        return result;
    }

    size_t Size() {return data_.size();}
    void Show() {
        for (size_t i = 0; i < data_.size(); i++)
            std::cout<<data_[i]<<' ';
    }

private:
    //Просеивания
    void SiftUp(int index) {
        if (!index) return;
        int child = data_[index];
        int parent = data_[(index-1)/2];
        if (child < parent){
            std::swap(data_[index], data_[(index-1)/2]);
            SiftUp((index-1)/2);
        }
    }

    void SiftDown(int index) {
        size_t left_child_index = 2*index + 1;
        size_t right_child_index = 2*index + 2;
        int parent = data_[index];
        if (left_child_index > data_.size()-1) return;
        if (right_child_index > data_.size()-1) {
            if (parent > data_[left_child_index]) {
                std::swap(data_[index], data_[left_child_index]);
            }
            return;
        }
        if (parent > std::min(data_[left_child_index], data_[right_child_index])) {
            if (data_[left_child_index] > data_[right_child_index]) {
                std::swap(data_[index], data_[right_child_index]);
                SiftDown(right_child_index);
            }
            else {
                std::swap(data_[index], data_[left_child_index]);
                SiftDown(left_child_index);
            }
        }
        return;
    }

    std::vector<int> data_;
    // std::priority_queue<int, std::vector<int>, std::greater<int>> data_;
};

template <>
class MinHeap<double> {
public:
    void Push(double value) {
        data_.push_back(value);
        SiftUp(data_.size()-1);
    }

    double Pop() {
        if (data_.empty()) throw std::out_of_range("Empty heap");
        auto result = data_[0];
        data_[0] = data_[data_.size()-1];
        data_.pop_back();
        if (!data_.empty()) SiftDown(0);
        return result;
    }

    size_t Size() {return data_.size();}

    void Show() {
        for (size_t i = 0; i < data_.size(); i++)
            std::cout<<data_[i]<<' ';
    }

private:
    //Просеивания
    void SiftUp(int index) {
        if (!index) return;
        double child = data_[index];
        double parent = data_[(index-1)/2];
        if (child < parent){
            std::swap(data_[index], data_[(index-1)/2]);
            SiftUp((index-1)/2);
        }
    }

    void SiftDown(int index) {
        size_t left_child_index = 2*index + 1;
        size_t right_child_index = 2*index + 2;
        double parent = data_[index];
        if (left_child_index > data_.size()-1) return;
        if (right_child_index > data_.size()-1) {
            if (parent > data_[left_child_index]) {
                std::swap(data_[index], data_[left_child_index]);
            }
            return;
        }
        if (parent > std::min(data_[left_child_index], data_[right_child_index])) {
            if (data_[left_child_index] > data_[right_child_index]) {
                std::swap(data_[index], data_[right_child_index]);
                SiftDown(right_child_index);
            }
            else {
                std::swap(data_[index], data_[left_child_index]);
                SiftDown(left_child_index);
            }
        }
        return;
    }

    std::vector<double> data_;
    // std::priority_queue<int, std::vector<int>, std::greater<int>> data_;
};