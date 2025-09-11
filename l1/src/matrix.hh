#pragma once
#include <iomanip>
#include <iostream>
#include <memory>
#include <ranges>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace mat {

template <typename U>
using initializer_list = std::initializer_list<U>;

template <typename U>
using initializer_matrix = std::initializer_list<initializer_list<U>>;

template <typename T>
class matrix {
   private:
    size_t rows_;
    size_t cols_;
    T *data_;

   private:
    void copyFromInitMat(const initializer_matrix<T> &mat) {
        if (&mat != this) {
            for (size_t i = 0; i < rows_; i++) {
                if ((mat.begin() + i)->size() != cols_) throw std::invalid_argument("Invalid initializer list");
                const initializer_list<T> *line = mat.begin() + i;
                std::ranges::copy(line->begin(), line->end(), data_ + i * cols_);
            }
        }
    }

   public:
    matrix(size_t rows, size_t cols) : rows_{rows}, cols_{cols}, data_(new T[cols_ * rows_]){};
    explicit matrix(matrix &&other) noexcept : cols_{other.cols_}, rows_{other.rows_}, data_{other.data_} {};

    matrix() : matrix(2, 2){};
    explicit matrix(const matrix &other) : matrix(other.cols_, other.rows_) { std::copy(data_, data_ + cols_ * rows_); }
    matrix(const initializer_matrix<T> &mat) : matrix(mat.size(), mat.begin()->size()) { copyFromInitMat(mat); };

    ~matrix() { delete[] data_; }

    const matrix &insert(const initializer_matrix<T> &mat) {
        resize(mat.size(), mat.begin()->size());
        copyFromInitMat(mat);
        return *this;
    }

    matrix &resize(size_t rows, size_t cols) {
        size_t oldLen = rows_ * cols_;
        rows_ = rows;
        cols_ = cols;
        if (oldLen < rows_ * cols_) {
            delete[] data_;
            data_ = new T[rows_ * cols_];
        }
        return *this;
    }

    size_t getRows() const { return rows_; }
    size_t getCols() const { return cols_; }

    void print() const {
        size_t maxWidth = 0;
        for (int i = 0; i < rows_; i++) {
            for (int j = 0; j < cols_; j++) {
                std::stringstream strNumStream;
                strNumStream << std::defaultfloat << data_[i * cols_ + j];
                maxWidth = std::max(maxWidth, strNumStream.str().size());
            }
        }
        for (size_t i = 0; i < rows_; i++) {
            std::cout << '|';
            for (size_t j = 0; j < cols_ - 1; j++) {
                std::cout << std::left << std::setw(maxWidth) << data_[i * cols_ + j] << " ";
            }
            std::cout << std::setw(maxWidth) << data_[i * cols_ + cols_ - 1] << '|' << std::endl;
        }
    }
    int isElem(size_t i, size_t j) const { return i < rows_ && j < cols_; }
    T &getElement(size_t i, size_t j) const {
        if (!isElem(i, j)) throw std::invalid_argument("Indexes out of range");
        return data_[i * cols_ + j];
    }
    const matrix &setElement(size_t i, size_t j, T &el) {
        getElement(i, j) = el;
        return *this;
    }
    const matrix &subtractFromElement(size_t i, size_t j, T val) {
        getElement(i, j) -= val;
        return *this;
    }

    matrix &operator=(const initializer_matrix<T> &mat) {
        copyFromInitMat(mat);
        return *this;
    }
    matrix &operator=(const matrix &other) {
        resize(other.rows_, other.cols_);
        std::ranges::copy(other.data_, other.data_ + cols_ * rows_, data_);
    }
    matrix &operator=(matrix &&other) noexcept {
        delete[] data_;
        cols_ = other.cols_;
        rows_ = other.rows_;
        data_ = other.data_;
        return *this;
    }
};

}  // namespace mat
