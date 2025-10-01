#pragma once
#include <exception>
#include <format>
#include <initializer_list>
#include <iostream>
#include <memory>
#include <ranges>
namespace vec {
template <class T>
class Vector {
   private:
    constexpr static const size_t kGrowthFacror = 2;
    size_t size_;
    size_t used_ = 0;
    std::unique_ptr<T[]> data_;

   private:
    friend std::ostream &operator<<(std::ostream &os, const Vector &vec) {
        os << '[';
        for (size_t i = 0; i < vec.used_; i++) {
            os << vec.data_[i] << ' ';
        }
        os << "]";
        return os;
    }
    friend Vector operator+(const Vector &vec1, const Vector &vec2) {
        if (vec1.used_ != vec2.used_) throw std::invalid_argument("Vector lengths mismatch");
        Vector res(vec1.used_);
        for (size_t i = 0; i < vec1.used_; i++) {
            res.pushBack(vec1.data_[i] + vec2.data_[i]);
        }
        return res;
    }

    void shift() {
        auto tmpList = std::make_unique_for_overwrite<T[]>(size_);
        std::copy(data_.get(), data_.get() + used_, tmpList.get() + 1);
        data_ = std::move(tmpList);
    }
    void expand(size_t offset = 0) {
        size_ = size_ * kGrowthFacror;
        if (size_ == 0) size_ = 1;
        auto tmpList = std::make_unique_for_overwrite<T[]>(size_);
        std::copy(data_.get(), data_.get() + used_, tmpList.get() + offset);
        data_ = std::move(tmpList);
    }

   public:
    Vector() : size_{0}, data_{nullptr} {};
    explicit Vector(size_t length) : size_{length}, data_{std::make_unique<T[]>(size_)} {}
    Vector(const std::initializer_list<T> &&list)
        : size_{list.size()}, used_{size_}, data_{std::make_unique_for_overwrite<T[]>(size_)} {
        if (size_ == 0) throw std::invalid_argument("empty initializer_list");
        std::ranges::copy(list, data_.get());
    }

    Vector &operator=(const std::initializer_list<T> &&list) {
        if (list.size() == 0) throw std::invalid_argument("empty initializer_list");
        size_ = list.size();
        data_ = std::move(std::make_unique_for_overwrite<T[]>(size_));
        std::ranges::copy(list, data_.get());
        return *this;
    };

    T &operator[](size_t i) { return data_[i]; }
    const T &operator[](size_t i) const { return data_[i]; }

    Vector &pushBack(const T &el) {
        if (used_ == size_) expand();
        data_[used_] = el;
        used_++;
        return *this;
    }
    Vector &pushFront(const T &el) {
        if (used_ == size_)
            expand(1);
        else
            shift();
        data_[0] = el;
        used_++;
        return *this;
    }
    void erase(size_t index) {
        if(index >= used_) throw std::invalid_argument("Index out of range");
        T *data = data_.get();
        std::copy(data + index + 1, data + used_, data + index);
        used_--;
    }
    size_t count(){
        return used_;
    }
};

}  // namespace vec
