#include <algorithm>
#include <cassert>
#include <cstddef>
#include <memory>

template <typename T> struct dynqueue {
    using value_type = T;

    explicit dynqueue(const std::size_t capacity = 32)
        : data_{std::make_unique<value_type[]>(capacity)},
          data_end_{data_.get() + capacity}, head_{data_.get()},
          tail_{data_.get()} {}

    std::size_t capacity() const { return data_end_ - data_.get(); }

    std::size_t size() const { return tail_ - head_; }

    bool empty() const { return size() == 0; }

    void enqueue(value_type key) {
        if (size() == capacity()) {
            grow();
        } else if (tail_ >= data_end_) {
            shift_to_start();
        }
        assert(head_ <= tail_);
        assert(tail_ < data_end_);
        assert(tail_ >= data_.get());
        *tail_ = key;
        ++tail_;
    }

    value_type dequeue() {
        assert(head_ < tail_);
        assert(head_ < data_end_);
        return *head_++;
    }

  private:
    void grow() {
        const auto sz = size();
        const auto new_capacity = capacity() * 2;
        auto new_data = std::make_unique<value_type[]>(new_capacity);
        std::copy(head_, data_end_, new_data.get());
        head_ = new_data.get();
        tail_ = head_ + sz;
        data_ = std::move(new_data);
        data_end_ = data_.get() + new_capacity;
    }

    void shift_to_start() {
        const auto sz = size();
        std::move(head_, tail_, data_.get());
        head_ = data_.get();
        tail_ = head_ + sz;
    }

    std::unique_ptr<value_type[]> data_;
    value_type* data_end_;
    value_type* head_;
    value_type* tail_;
};
