#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstddef>

struct dynqueue
{
    explicit dynqueue(std::size_t capacity) : capacity_{capacity}
    {
        head_ = tail_ = data_ = new int[capacity];
    }

    void enqueue(int key)
    {
        const int *data_end = data_ + capacity_;
        if (tail_ >= data_end)
        {
            grow();
        }
        *tail_ = key;
        ++tail_;
    }

private:
    void grow()
    {
        std::size_t new_capacity = capacity_ * 2;
        int *new_data = new int[capacity_];
        int * const data_end = data_ + capacity_;
        std::copy(head_, data_end, new_data);

        delete[] data_;
        data_ = new_data;
        capacity_ = new_capacity;
    }

    std::size_t capacity_;
    int *data_ = nullptr;
    int *head_ = nullptr;
    int *tail_ = nullptr;
};
