#pragma once
#include <memory>


namespace mat {
using initializer_list = std::initializer_list<double>;
using initializer_matrix = std::initializer_list<initializer_list>;
class Matrix {
   private:
    size_t rows_;
    size_t cols_;
    double *data_;

   private:
    void copyFrom(const initializer_matrix &mat);

   public:
    Matrix();
    Matrix(size_t rows, size_t cols);
    explicit Matrix(Matrix &&other) noexcept;
    explicit Matrix(const Matrix &other);
    Matrix(const initializer_matrix &mat);
    ~Matrix();

    const Matrix &insert(const initializer_matrix &mat);

    Matrix &resize(size_t rows, size_t cols);

    size_t getRows() const;
    size_t getCols() const;
    double &getElement(size_t i, size_t j) const;
    const Matrix &setElement(size_t i, size_t j, double el) const;
    int isElem(size_t i, size_t j) const;
    void print() const;
    const Matrix &subtractFromElement(size_t i, size_t j, double val) const;

    Matrix &operator=(const initializer_matrix &mat);
    Matrix &operator=(const Matrix &other);
    Matrix &operator=(Matrix &&other) noexcept;
};

}  // namespace mat
