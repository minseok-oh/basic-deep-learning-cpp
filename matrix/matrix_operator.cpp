#include "matrix_operator.hpp"
#include <assert.h>

const Matrix MatrixOperator::Dot(const Matrix& m1, const Matrix& m2){
    assert(m1.get_row() == m2.get_column() && m1.get_column() == m2.get_row());

    Matrix ret(0, m1.get_row(), m2.get_column());
    for(std::size_t i = 0; i < m1.get_row(); ++i){
        for(std::size_t j = 0; j < m2.get_column(); ++j){
            for(std::size_t k = 0; k < m1.get_column(); ++k){
                ret[{i, j}] += (m1[{i, k}]) * (m2[{k, j}]);
            }
        }
    }
    return ret;
}
