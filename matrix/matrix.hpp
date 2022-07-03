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
        ~Matrix() = default;

        std::size_t get_row() const;
        std::size_t get_column() const;

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

        Matrix& operator+=(const Matrix& matrix) const;
        Matrix& operator+=(const double& value) const;

        Matrix& operator-=(const Matrix& matrix) const;
        Matrix& operator-=(const double& value) const;

        Matrix& operator*=(const Matrix& matrix) const;
        Matrix& operator*=(const double& value) const;

        Matrix& operator/=(const Matrix& matrix) const;
        Matrix& operator/=(const double& value) const;
};

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix);
