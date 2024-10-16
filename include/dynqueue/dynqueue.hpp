#include <algorithm>
#include <cstddef>

struct dynqueue
{
    explicit dynqueue(const std::size_t capacity = 32) : data_{new int[capacity]}, data_end_{data_ + capacity}, head_{data_}, tail_{data_}
    {
    }

    std::size_t capacity() const
    {
        return data_end_ - data_;
    }

    std::size_t size() const
    {
        return tail_ - head_;
    }

    void enqueue(int key)
    {
        if (tail_ >= data_end_)
        {
            grow();
        }
        *tail_ = key;
        ++tail_;
    }

private:
    void grow()
    {
        const auto sz = size();
        const auto new_capacity = capacity() * 2;
        auto new_data = new int[new_capacity];
        auto new_data_end = data_ + new_capacity;
        std::copy(head_, data_end_, new_data);
        head_ = new_data;
        tail_ = head_ + sz;

        delete[] data_;
        data_ = new_data;
        data_end_ = data_ + new_capacity;
    }

    int *data_ = nullptr;
    int *data_end_ = nullptr;
    int *head_ = nullptr;
    int *tail_ = nullptr;
};
