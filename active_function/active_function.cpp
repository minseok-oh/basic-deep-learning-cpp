#include "active_function.hpp"
#include <vector>
#include <cmath>

const double ActiveFunction::StepFunction(const double& x){
    return x > 0;
}
const Matrix ActiveFunction::StepFunction(const Matrix& x){
    std::vector<double> ret(x.get_size());
    std::vector<double> matrix_data(x.get_matrix_data());

    for(std::size_t i = 0; i < x.get_size(); ++i){
        ret[i] = StepFunction(matrix_data[i]);
    }
    return Matrix(ret, x.get_row(), x.get_column());
}

const double ActiveFunction::Sigmoid(const double& x){
    return 1 / (1 + exp(-1 * x));
}
const Matrix ActiveFunction::Sigmoid(const Matrix& x){
    std::vector<double> ret(x.get_size());
    std::vector<double> matrix_data(x.get_matrix_data());

    for(std::size_t i = 0; i < x.get_size(); ++i){
        ret[i] = Sigmoid(matrix_data[i]);
    }
    return Matrix(ret, x.get_row(), x.get_column());
}

const double ActiveFunction::Relu(const double& x){
    return x > 0? x: 0;
}
const Matrix ActiveFunction::Relu(const Matrix& x){
    std::vector<double> ret(x.get_size());
    std::vector<double> matrix_data(x.get_matrix_data());

    for(std::size_t i = 0; i < x.get_size(); ++i){
        ret[i] = Relu(matrix_data[i]);
    }
    return Matrix(ret, x.get_row(), x.get_column());
}

const Matrix ActiveFunction::SoftMax(const Matrix& x){
	std::vector<double> ret(x.get_size());
	std::vector<double> matrix_data(x.get_matrix_data());
	
	double data_mean = 0;
	for(std::size_t i = 0; i < matrix_data.size(); ++i){
		matrix_data[i] = exp(matrix_data[i]);
		data_mean += matrix_data[i];
	}
	data_mean /= matrix_data.size();
	
	for(std::size_t i = 0; i < ret.size(); ++i){
		ret[i] = matrix_data[i] / data_mean;
	}
	return Matrix(ret, x.get_row(), x.get_column());
}