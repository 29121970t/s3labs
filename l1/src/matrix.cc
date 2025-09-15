#include "matrix.hh"

#include <iostream>
#include <print>
#include <ranges>
#include <sstream>
#include <stdexcept>

using namespace mat;

matrix::matrix(size_t rows, size_t cols) : rows_{rows}, cols_{cols}, data_(new double[cols_ * rows_]){};

matrix::matrix() : matrix(2, 2){};

matrix::matrix(matrix &&other) noexcept :  rows_{other.rows_}, cols_{other.cols_}, data_{other.data_} {};

matrix::matrix(const matrix &other) : matrix(other.cols_, other.rows_) {
    std::copy(other.data_, other.data_ + cols_ * rows_, data_);

}

matrix::matrix(const initializer_matrix &mat) : matrix(mat.size(), mat.begin()->size()) { copyFromInitMat(mat); };

matrix::~matrix() { delete[] data_; }

void matrix::copyFromInitMat(const initializer_matrix &mat) {
    for (size_t i = 0; i < rows_; i++) {
        if ((mat.begin() + i)->size() != cols_) throw std::invalid_argument("Invalid initializer list");
        const initializer_list line = *(mat.begin() + i);
        std::ranges::copy(line, data_ + i * cols_);
    }
}

const matrix &matrix::insert(const initializer_matrix &mat) {
    resize(mat.size(), mat.begin()->size());
    copyFromInitMat(mat);
    return *this;
}

matrix &matrix::resize(size_t rows, size_t cols) {
    size_t oldLen = rows_ * cols_;
    rows_ = rows;
    cols_ = cols;
    if (oldLen < rows_ * cols_) {
        delete[] data_;
        data_ = new double[rows_ * cols_];
    }
    return *this;
}

size_t matrix::getRows() const { return rows_; }
size_t matrix::getCols() const { return cols_; }

void matrix::print() const {
    size_t maxWidth = 0;
    for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
            maxWidth = std::max(maxWidth, std::format("{}g", data_[i * cols_ + j]).size());
        }
    }
    maxWidth--;
    for (size_t i = 0; i < rows_; i++) {
        std::cout << '|';
        for (size_t j = 0; j < cols_ - 1; j++) {
            std::print("{:<{}} ", data_[i * cols_ + j], maxWidth);
        }
        std::print("{:<{}}|\n", data_[i * cols_ + cols_ - 1], maxWidth);
    }
}

int matrix::isElem(size_t i, size_t j) const { return i < rows_ && j < cols_; }

double &matrix::getElement(size_t i, size_t j) const {
    if (!isElem(i, j)) throw std::invalid_argument("Indexes out of range");
    return data_[i * cols_ + j];
}

const matrix &matrix::setElement(size_t i, size_t j, double el) const{
    getElement(i, j) = el;
    return *this;
}

const matrix &matrix::subtractFromElement(size_t i, size_t j, double val) const{
    getElement(i, j) -= val;
    return *this;
}

matrix &matrix::operator=(const initializer_matrix &mat) {
    copyFromInitMat(mat);
    return *this;
}

matrix &matrix::operator=(const matrix &other) {
    resize(other.rows_, other.cols_);
    std::ranges::copy(other.data_, other.data_ + cols_ * rows_, data_);
    return *this;
}

matrix &matrix::operator=(matrix &&other) noexcept {
    delete[] data_;
    cols_ = other.cols_;
    rows_ = other.rows_;
    data_ = other.data_;
    return *this;
}
