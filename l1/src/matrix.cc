#include "matrix.hh"

#include <iostream>
#include <print>
#include <ranges>
#include <sstream>
#include <stdexcept>

using namespace mat;

Matrix::Matrix(size_t rows, size_t cols) : rows_{rows}, cols_{cols}, data_(new double[cols_ * rows_]){};

Matrix::Matrix() : Matrix(2, 2){};

Matrix::Matrix(Matrix &&other) noexcept :  rows_{other.rows_}, cols_{other.cols_}, data_{other.data_} {};

Matrix::Matrix(const Matrix &other) : Matrix(other.cols_, other.rows_) {
    std::copy(other.data_, other.data_ + cols_ * rows_, data_);

}

Matrix::Matrix(const initializer_matrix &mat) : Matrix(mat.size(), mat.begin()->size()) { copyFrom(mat); };

Matrix::~Matrix() { delete[] data_; }

void Matrix::copyFrom(const initializer_matrix &mat) {
    for (size_t i = 0; i < rows_; i++) {
        if ((mat.begin() + i)->size() != cols_) throw std::invalid_argument("Invalid initializer list");
        const initializer_list line = *(mat.begin() + i);
        std::ranges::copy(line, data_ + i * cols_);
    }
}

const Matrix &Matrix::insert(const initializer_matrix &mat) {
    resize(mat.size(), mat.begin()->size());
    copyFrom(mat);
    return *this;
}

Matrix &Matrix::resize(size_t rows, size_t cols) {
    size_t oldLen = rows_ * cols_;
    rows_ = rows;
    cols_ = cols;
    if (oldLen < rows_ * cols_) {
        delete[] data_;
        data_ = new double[rows_ * cols_];
    }
    return *this;
}

size_t Matrix::getRows() const { return rows_; }
size_t Matrix::getCols() const { return cols_; }

void Matrix::print() const {
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

int Matrix::isElem(size_t i, size_t j) const { return i < rows_ && j < cols_; }

double &Matrix::getElement(size_t i, size_t j) const {
    if (!isElem(i, j)) throw std::invalid_argument("Indexes out of range");
    return data_[i * cols_ + j];
}

const Matrix &Matrix::setElement(size_t i, size_t j, double el) const{
    getElement(i, j) = el;
    return *this;
}

const Matrix &Matrix::subtractFromElement(size_t i, size_t j, double val) const{
    getElement(i, j) -= val;
    return *this;
}

Matrix &Matrix::operator=(const initializer_matrix &mat) {
    copyFrom(mat);
    return *this;
}

Matrix &Matrix::operator=(const Matrix &other) {
    resize(other.rows_, other.cols_);
    std::ranges::copy(other.data_, other.data_ + cols_ * rows_, data_);
    return *this;
}

Matrix &Matrix::operator=(Matrix &&other) noexcept {
    delete[] data_;
    cols_ = other.cols_;
    rows_ = other.rows_;
    data_ = other.data_;
    return *this;
}
