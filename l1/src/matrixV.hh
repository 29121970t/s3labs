#include <vector>
#include <stdexcept>
#include <iostream>

namespace mat {
    template<typename T> class matrix {
    private:
        size_t cols_;
        size_t rows_;
        std::vector<std::vector<T>> data_;
    public:
        matrix() : cols_{ 2 }, rows_{ 2 }, data_(2, std::vector<T>(2, 0)) {};
        matrix(size_t cols, size_t rows) : cols_{ cols }, rows_{ rows }, data_(rows_, std::vector<T>(cols_, 0)) {};
        matrix(std::initializer_list<std::vector<T>> mat) : cols_{ mat.begin()->size() }, rows_{ mat.size() }, data_(mat) {
            for (size_t i = 0; i < rows_; i++) {
                if (data_[i].size() > cols_) throw std::invalid_argument("Invalid initializer list");
            }
        };

        matrix& insert(std::initializer_list<std::vector<T>> mat) {
            data_ = mat;
            return *this;
        }

        size_t getRows() const { return rows_; }
        size_t getCols() const { return cols_; }
        void print() {
            for (size_t i = 0; i < rows_; i++) {
                for (size_t j = 0; j < cols_; j++) {
                    std::cout << data_[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }
        T& getElement(size_t i, size_t j) {
            return data_[i][j];
        }
        matrix& setElement(size_t i, size_t j, T& el) {
            data_[i][j] = el;
            return *this;
        }
        matrix& subtractFromElement(size_t i, size_t j, T val) {
            data_[i][j] -= val;
        }

        const std::vector<T>& operator[](size_t index) const { return data_[index]; }

    };

}

