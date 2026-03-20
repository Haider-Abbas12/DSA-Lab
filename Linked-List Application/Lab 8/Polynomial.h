#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <cmath>

using namespace std;

class Polynomial {
private:
    vector<double> coefficients; 
    int degree;

public:
    Polynomial();
    Polynomial(const string& filename);

    int getDegree() const;
    double getCoefficient(int power) const;
    const vector<double>& getCoefficients() const;

    Polynomial operator+(const Polynomial& other) const;
    Polynomial operator*(const Polynomial& other) const;

    double evaluate(double x) const;
    void display() const;
    void readFromFile(const string& filename);
};

#endif