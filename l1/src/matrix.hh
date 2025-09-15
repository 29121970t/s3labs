#pragma once
#include <memory>


namespace mat {
using initializer_list = std::initializer_list<double>;
using initializer_matrix = std::initializer_list<initializer_list>;
class matrix {
   private:
    size_t rows_;
    size_t cols_;
    double *data_;

   private:
    void copyFromInitMat(const initializer_matrix &mat);

   public:
    matrix();
    matrix(size_t rows, size_t cols);
    explicit matrix(matrix &&other) noexcept;
    explicit matrix(const matrix &other);
    matrix(const initializer_matrix &mat);
    ~matrix();

    const matrix &insert(const initializer_matrix &mat);

    matrix &resize(size_t rows, size_t cols);

    size_t getRows() const;
    size_t getCols() const;
    int isElem(size_t i, size_t j) const;
    double &getElement(size_t i, size_t j) const;
    const matrix &setElement(size_t i, size_t j, double el) const;

    void print() const;
    const matrix &subtractFromElement(size_t i, size_t j, double val) const;

    matrix &operator=(const initializer_matrix &mat);
    matrix &operator=(const matrix &other);
    matrix &operator=(matrix &&other) noexcept;
};

}  // namespace mat
