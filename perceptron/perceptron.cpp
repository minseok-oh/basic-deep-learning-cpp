#include "perceptron.hpp"

const bool Perceptron::And(const double& x1, const double& x2){
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

const bool Perceptron::Or(const double& x1, const double& x2){
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

const bool Perceptron::Nand(const double& x1, const double& x2){
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

const bool Perceptron::Xor(const double& x1, const double& x2){
    double s1 = Perceptron::Nand(x1, x2);
    double s2 = Perceptron::Or(x1, x2);
    bool y = Perceptron::And(s1, s2);
    return y;
}