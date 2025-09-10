#pragma once
#include <iostream>
#include <memory>
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
    matrix &resizeDel_(size_t rows, size_t cols) {
        size_t oldLen = rows_ * cols_;
        rows_ = rows;
        cols_ = cols;
        if (oldLen < rows_ * cols_) {
            delete[] data_;
            data_ = new T[rows_ * cols_];
        }
        return *this;
    }
    void copyFromInitMat(const initializer_matrix<T> &mat) {
        for (size_t i = 0; i < rows_; i++) {
            if ((mat.begin() + i)->size() != cols_) throw std::invalid_argument("Invalid initializer list");
            const initializer_list<T> *line = mat.begin() + i;
            std::copy(line->begin(), line->end(), data_ + i * cols_);
        }
    }

   public:
    matrix(size_t rows, size_t cols) : rows_{rows}, cols_{cols}, data_(new T[cols_ * rows_]){};
    explicit matrix(matrix &&other) : cols_{other.cols_}, rows_{other.rows_}, data_{other.data_} {}

    matrix() : matrix(2, 2){};
    explicit matrix(const matrix &other) : matrix(other.cols_, other.rows_) { std::copy(data_, data_ + cols_ * rows_); }
    matrix(const initializer_matrix<T> &mat) : matrix(mat.size(), mat.begin()->size()) { copyFromInitMat(mat); };

    ~matrix() { delete[] data_; }

    const matrix &insert(const initializer_matrix<T> &mat) {
        resizeDel_(mat.size(), mat.begin()->size());
        copyFromInitMat(mat);
        return *this;
    }

    size_t getRows() const { return rows_; }
    size_t getCols() const { return cols_; }

    void print() const {
        for (size_t i = 0; i < rows_; i++) {
            for (size_t j = 0; j < cols_; j++) {
                std::cout << data_[i * cols_ + j] << " ";
            }
            std::cout << std::endl;
        }
    }
    int isElem(size_t i, size_t j) const { return i < rows_ && j < cols_; }
    T &getElement(size_t i, size_t j) const{
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
        resizeDel_(other.size(), other.begin()->size());
        std::copy(data_, data_ + cols_ * rows_);
    }
    matrix &operator=(matrix &&other) {
        delete[] data_;
        cols_ = other.cols_;
        rows_ = other.rows_;
        data_ = other.data_;
        return *this;
    }
};

}  // namespace mat
