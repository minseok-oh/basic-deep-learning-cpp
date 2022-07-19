#include "loss_function.hpp"
#include <cmath>
#include <vector>
#include <iostream>

const double LossFunction::MeanSquaredError(const Matrix& y, const Matrix& t){
	std::vector<double> err = (y - t).get_matrix_data();
	for(size_t i = 0; i < err.size(); ++i){
		err[i] = pow(err[i], 2);
	}
	
	Matrix res(err, y.get_row(), y.get_column());
	return res.Sum() / 2;
}

const double LossFunction::CrossEntropyError(const Matrix& y, const Matrix& t){
	double delta = 1e-7;
	std::vector<double> err = y.get_matrix_data();
	for(size_t i = 0; i < err.size(); ++i){
		err[i] = log(err[i] + delta);
	}
	
	Matrix res(err, y.get_row(), y.get_column());
	return -1 * ((res * t).Sum());
}