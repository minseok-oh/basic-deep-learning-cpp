#ifndef _LOSS_FUNCTION_H_
#define _LOSS_FUNCTION_H_

#include "../matrix/matrix.hpp"

namespace LossFunction{
	const double MeanSquaredError(const Matrix& y, const Matrix& t);
	const double CrossEntropyError(const Matrix& y, const Matrix& t);
};

#endif