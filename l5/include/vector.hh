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
    size_t used_;
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
    Vector() : size_{0}, used_{0}, data_{nullptr} {};
    Vector(size_t length) : size_{length}, used_{0}, data_{std::make_unique<T[]>(size_)} {}
    Vector(const std::initializer_list<T> &&list)
        : size_{list.size()}, used_{size_}, data_{std::make_unique_for_overwrite<T[]>(size_)} {
        if (size_ == 0) throw std::invalid_argument("empty initializer_list");
        std::ranges::copy(list, data_.get());
    }
    Vector(const Vector &other) : size_{other.size_}, used_{size_}, data_{std::make_unique<T[]>(size_)} {
        copy(other.data_.get(), other.data_.get() + size_, data_.get());
    }
    Vector(Vector &&other) noexcept : size_{other.size_}, used_{size_}, data_{std::move(other.data_)} {};
    ~Vector() = default;

    Vector &operator=(const Vector &other) {
        size_ = other.size_;
        used_ = other.used_;
        data_ = std::move(std::make_unique_for_overwrite<T[]>(size_));
        std::copy(other.data_.get(), other.data_.get() + size_, data_.get());
        return *this;
    };

    Vector &operator=(Vector &&other) noexcept {
        size_ = other.size_;
        used_ = other.used_;
        data_ = std::move(other.data_);
        return *this;
    };

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
    Vector operator+(const Vector &other) {
        if(used_ != other.used_) throw std::invalid_argument("Vector lengths mismatch");
        Vector res(used_);
        for (size_t i = 0; i < used_; i++)
        {
            res.pushBack(data_[i] + other.data_[i]);
        }
        return res;        
    }
};

}  // namespace vector
