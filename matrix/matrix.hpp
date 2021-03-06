#ifndef _MATRIX_H_
#define _MATRIX_H_

#include <cstddef>
#include <vector>
#include <ostream>

struct MatrixIndex{
    std::size_t row, column;
};

class Matrix{
    private:
        std::vector<double> matrix_data_;
        std::size_t row_ = 0, column_ = 0, size_ = 0;

    public:
        Matrix() noexcept = default;
        Matrix(std::size_t row, std::size_t column);
        Matrix(double value, std::size_t row, std::size_t column);
        Matrix(std::vector<double> data, std::size_t row, std::size_t column);
        Matrix(const Matrix& matrix);
        Matrix(Matrix&& matrix) noexcept;
        ~Matrix() = default;

        std::size_t get_row() const;
        std::size_t get_column() const;
        std::size_t get_size() const;
        std::vector<double> get_matrix_data() const;

        Matrix& operator=(const Matrix& matrix);
        double operator[](const MatrixIndex& index) const noexcept;
        double& operator[](const MatrixIndex& index) noexcept;
        
        Matrix operator+(const Matrix& matrix) const;
        Matrix operator+(const double& value) const;

        Matrix operator-(const Matrix& matrix) const;
        Matrix operator-(const double& value) const;

        Matrix operator*(const Matrix& matrix) const;
        Matrix operator*(const double& value) const;

        Matrix operator/(const Matrix& matrix) const;
        Matrix operator/(const double& value) const;

        Matrix& operator+=(const Matrix& matrix) noexcept;
        Matrix& operator+=(const double& value) noexcept;

        Matrix& operator-=(const Matrix& matrix) noexcept;
        Matrix& operator-=(const double& value) noexcept;

        Matrix& operator*=(const Matrix& matrix) noexcept;
        Matrix& operator*=(const double& value) noexcept;

        Matrix& operator/=(const Matrix& matrix) noexcept;
        Matrix& operator/=(const double& value) noexcept;

        const double Sum();
        const Matrix Dot(const Matrix& matrix);
};

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
#endif