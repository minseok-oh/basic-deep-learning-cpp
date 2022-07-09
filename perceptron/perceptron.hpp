#ifndef _PERCEPTRON_H_
#define _PERCEPTRON_H_

#include "../matrix/matrix.hpp"
namespace Perceptron{
    const bool And(const double& x1, const double& x2);
    const bool Or(const double& x1, const double& x2);
    const bool Nand(const double& x1, const double& x2);
    const bool Xor(const double& x1, const double& x2);
};

#endif