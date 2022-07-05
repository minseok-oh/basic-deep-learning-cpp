#include "perceptron.hpp"

const bool perceptron::And(const double& x1, const double& x2){
    Matrix x({x1, x2}, 1, 2);
    Matrix w({0.5, 0.5}, 1, 2);
    double b = -0.7;

    double temp = (x * w).Sum() + b;
    if(temp > 0){
        return true;
    }
    else{
        return false;
    }
}

const bool perceptron::Or(const double& x1, const double& x2){
    Matrix x({x1, x2}, 1, 2);
    Matrix w({0.5, 0.5}, 1, 2);
    double b = -0.2;

    double temp = (x * w).Sum() + b;
    if(temp > 0){
        return true;
    }
    else{
        return false;
    }
}

const bool perceptron::Nand(const double& x1, const double& x2){
    Matrix x({x1, x2}, 1, 2);
    Matrix w({-0.5, -0.5}, 1, 2);
    double b = 0.7;

    double temp = (x * w).Sum() + b;
    if(temp > 0){
        return true;
    }
    else{
        return false;
    }
}

const bool perceptron::Xor(const double& x1, const double& x2){
    double s1 = perceptron::Nand(x1, x2);
    double s2 = perceptron::Or(x1, x2);
    bool y = perceptron::And(s1, s2);
    return y;
}