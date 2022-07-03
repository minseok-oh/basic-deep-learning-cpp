#include "matrix.hpp"

#include <cassert>
#include <utility>

Matrix::Matrix(std::size_t row, std::size_t column)
    : matrix_data_(row * column), row_(row), column_(column), size_(row * column) {
    assert((!row && !column) || (row > 0 && column > 0));
}
Matrix::Matrix(double value, std::size_t row, std::size_t column)
    : matrix_data_(row * column, value), row_(row), column_(column), size_(row * column){
    assert((!row && !column) || (row > 0 && column > 0));
}
Matrix::Matrix(std::vector<double> data, std::size_t row, std::size_t column)
    : matrix_data_(data), row_(row), column_(column), size_(row * column){
    assert((!row && !column) || (row > 0 && column > 0));
    assert(row * column == matrix_data_.size());
}
Matrix::Matrix(const Matrix& matrix)
    : matrix_data_(matrix.matrix_data_), row_(matrix.row_), column_(matrix.column_)
    , size_(matrix.row_ * matrix.column_){
}

std::size_t Matrix::get_row() const{
    return this->row_;
}
std::size_t Matrix::get_column() const{
    return this->column_;
}

Matrix& Matrix::operator=(const Matrix& matrix){
    this->matrix_data_ = matrix.matrix_data_;
    this->row_ = matrix.row_;
    this->column_ = matrix.column_;
    return *this; 
}
double Matrix::operator[](const MatrixIndex& index) const noexcept{
    return matrix_data_[index.row * this->column_ + index.column];
}
double& Matrix::operator[](const MatrixIndex& index) noexcept{
    return matrix_data_[index.row * this->column_ + index.column];
}
        
Matrix Matrix::operator+(const Matrix& matrix) const{
    return Matrix(*this) += matrix;
}
Matrix Matrix::operator+(const double& value) const{
    return Matrix(*this) += value;
}

Matrix Matrix::operator-(const Matrix& matrix) const{
    return Matrix(*this) -= matrix;
}
Matrix Matrix::operator-(const double& value) const{
    return Matrix(*this) -= value;
}

Matrix Matrix::operator*(const Matrix& matrix) const{
    return Matrix(*this) *= matrix;
}
Matrix Matrix::operator*(const double& value) const{
    return Matrix(*this) *= value;
}

Matrix Matrix::operator/(const Matrix& matrix) const{
    return Matrix(*this) /= matrix;
}
Matrix Matrix::operator/(const double& value) const{
    return Matrix(*this) /= value;
}

Matrix& Matrix::operator+=(const Matrix& matrix) const{
    assert((this->size_ != matrix.size_) && matrix.row_ != 1 && matrix.column_ != 1);

    if(this->size_ == matrix.size_){
        for(std::size_t i = 0; i < this->size_; ++i){
            this->matrix_data_[i] += matrix.matrix_data_[i];
        }
    }
    return *this;
}
Matrix& Matrix::operator+=(const double& value) const{
    for(std::size_t i = 0; i < this->size_; ++i){
        this->matrix_data_[i] += value;
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& matrix) const{
    assert((this->size_ != matrix.size_) && matrix.row_ != 1 && matrix.column_ != 1);

    if(this->size_ == matrix.size_){
        for(std::size_t i = 0; i < this->size_; ++i){
            this->matrix_data_[i] -= matrix.matrix_data_[i];
        }
    }
    return *this;
}
Matrix& Matrix::operator-=(const double& value) const{
    for(std::size_t i = 0; i < this->size_; ++i){
        this->matrix_data_[i] -= value;
    }
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& matrix) const{
    assert((this->size_ != matrix.size_) && matrix.row_ != 1 && matrix.column_ != 1);

    if(this->size_ == matrix.size_){
        for(std::size_t i = 0; i < this->size_; ++i){
            this->matrix_data_[i] *= matrix.matrix_data_[i];
        }
    }
    return *this;
}
Matrix& Matrix::operator*=(const double& value) const{
    for(std::size_t i = 0; i < this->size_; ++i){
        this->matrix_data_[i] *= value;
    }
    return *this;
}

Matrix& Matrix::operator/=(const Matrix& matrix) const{
    assert((this->size_ != matrix.size_) && matrix.row_ != 1 && matrix.column_ != 1);

    if(this->size_ == matrix.size_){
        for(std::size_t i = 0; i < this->size_; ++i){
            this->matrix_data_[i] /= matrix.matrix_data_[i];
        }
    }
    return *this;
}
Matrix& Matrix::operator/=(const double& value) const{
    for(std::size_t i = 0; i < this->size_; ++i){
        this->matrix_data_[i] /= value;
    }
    return *this;
}

std::ostream& operator<<(std::ostream& stream, const Matrix& matrix){
    stream << '[';

    for(std::size_t i = 0; i < matrix.get_row(); ++i){
        stream << '[';
        for(std::size_t j = 0; j < matrix.get_column(); ++j){
            stream << ' ' << matrix[{i, j}];
        }
        stream << "]\n";
    }
    return stream << " ]\n";
}