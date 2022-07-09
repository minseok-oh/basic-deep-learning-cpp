#ifndef _ACTIVE_FUNCTION_H_
#define _ACTIVE_FUNCTION_H_

#include "../matrix/matrix.hpp"

namespace ActiveFunction{
    const double StepFunction(const double& x);
    const Matrix StepFunction(const Matrix& x);

    const double Sigmoid(const double& x);
    const Matrix Sigmoid(const Matrix& x);

    const double Relu(const double& x);
    const Matrix Relu(const Matrix& x);
};

#endif