#include "Polynomial.h"

Polynomial::Polynomial() : degree(0) {
    coefficients.push_back(0.0);
}

Polynomial::Polynomial(const string& filename) : degree(0) {
    readFromFile(filename);
}

void Polynomial::readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        throw runtime_error("Could not open file: " + filename);
    }

    file >> degree;
    coefficients.resize(degree + 1, 0.0);

    for (int i = degree; i >= 0; i--) {
        file >> coefficients[i];
    }

    file.close();
}

int Polynomial::getDegree() const {
    return degree;
}

double Polynomial::getCoefficient(int power) const {
    if (power < 0 || power > degree) return 0.0;
    return coefficients[power];
}

const vector<double>& Polynomial::getCoefficients() const {
    return coefficients;
}

Polynomial Polynomial::operator+(const Polynomial& other) const {
    Polynomial result;
    int maxDeg = max(degree, other.degree);

    result.degree = maxDeg;
    result.coefficients.resize(maxDeg + 1, 0.0);

    for (int i = 0; i <= maxDeg; i++) {
        double a = (i <= degree)       ? coefficients[i]       : 0.0;
        double b = (i <= other.degree) ? other.coefficients[i] : 0.0;
        result.coefficients[i] = a + b;
    }

    return result;
}

Polynomial Polynomial::operator*(const Polynomial& other) const {
    Polynomial result;
    int resultDeg = degree + other.degree;

    result.degree = resultDeg;
    result.coefficients.resize(resultDeg + 1, 0.0);

    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= other.degree; j++) {
            result.coefficients[i + j] += coefficients[i] * other.coefficients[j];
        }
    }

    return result;
}

double Polynomial::evaluate(double x) const {
    double result = 0.0;
    for (int i = degree; i >= 0; i--) {
        result = result * x + coefficients[i];
    }
    return result;
}

void Polynomial::display() const {
    bool firstTerm = true;

    for (int i = degree; i >= 0; i--) {
        double coef = coefficients[i];
        if (coef == 0.0) continue;

        if (!firstTerm) cout << " + ";

        if      (i == 0) cout << coef;
        else if (i == 1) cout << coef << "x";
        else             cout << coef << "x^" << i;

        firstTerm = false;
    }

    if (firstTerm) cout << "0";

    cout << endl;
}