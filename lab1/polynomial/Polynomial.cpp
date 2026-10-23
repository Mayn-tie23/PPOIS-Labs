#include"Polynomial.h"
#include<iostream>
#include<algorithm>
#include<cmath>

Polynomial::Polynomial() {
}
Polynomial::Polynomial(const std::vector<double>& coeffs) {
	coefficients = coeffs;
}
Polynomial::Polynomial(const Polynomial& other) {
	coefficients = other.coefficients;
}
Polynomial::~Polynomial() {
}
Polynomial& Polynomial::operator=(const Polynomial& other) {
	if (this != &other) {
		coefficients = other.coefficients;
	}
	return*this;
}
void Polynomial::setCoefficient(int degree, double value) {
	if (degree < 0) {
		return;
	}
	if (degree >= static_cast<int>(coefficients.size())) {
		coefficients.resize(degree + 1, 0.0);
	}
	coefficients[degree] = value;
}
double Polynomial::getCoefficient(int degree)const {
	if (degree < 0 || degree >= static_cast<int>(coefficients.size())){
	return 0.0;
}
return coefficients[degree];
}
int Polynomial::degree()const {
	for (int i = static_cast<int>(coefficients.size()) - 1; i >= 0; i--) {
		if (coefficients[i] != 0.0) {
			return i;
		}
	}
	return -1;
}
double Polynomial::evaluate(double x)const {
	double result = 0.0;
	for (int i = degree(); i >= 0; i--) {
		result = result * x + coefficients[i];
	}
	return result;
}
void Polynomial::display()const {
	int highest = degree();
	if (highest == -1) {
		std::cout << "0" << std::endl;
		return;
	}
	bool first = true;
	for (int i = highest;i >= 0;i--) {
		double value = coefficients[i];
		if (value == 0.0) {
			continue;
		}
		if (!first) {
			std::cout << (value < 0 ? "-" : "+");
		}
		else if (value < 0) {
			std::cout << "-";
		} double magnitude = std::abs(value);
		if (i == 0 || magnitude != 1.0) {
			std::cout << magnitude;
		}
		if (i > 0) {
			std::cout << "x";
			if (i > 1) {
				std::cout << "^" << i;
			}
		}
		first = false;
	}
	std::cout << std::endl;
}
Polynomial Polynomial::add(const Polynomial& other)const {
	Polynomial result;
	int maxSize = std::max(
		coefficients.size(), other.coefficients.size());
	for (int i = 0; i < maxSize; i++) {
		result.setCoefficient(i, getCoefficient(i) + other.getCoefficient(i));
	}
	return result;
}
Polynomial Polynomial::subtract(const Polynomial& other)const {
	Polynomial result;
	int maxSize = static_cast<int>(std::max(coefficients.size(), other.coefficients.size()));
	for (int i = 0; i < maxSize;i++) {
		result.setCoefficient(i, getCoefficient(i) - other.getCoefficient(i));
	}
	return result;
}
Polynomial Polynomial::multiply(const Polynomial& other) const {
	Polynomial result;
	if (isEmpty() || other.isEmpty()) {
		return result;
	}
	for (int i = 0;i <= degree();i++) {
		for (int j = 0;j <= other.degree();j++) {
			double value = result.getCoefficient(i + j)
				+ getCoefficient(i) * other.getCoefficient(j);
			result.setCoefficient(i + j, value);
		}
	}
	return result;
}
bool Polynomial::operator==(const Polynomial& other)const {
	int maxDegree = std::max(degree(), other.degree());
	for (int i = 0; i <= maxDegree; i++) {
		if (getCoefficient(i) != other.getCoefficient(i)) {
			return false;
		}
	}
	return true;
}
bool Polynomial:: operator!=(const Polynomial& other)const {
	return!(*this == other);
}
void Polynomial::clear() {
	coefficients.clear();
}
bool Polynomial::isEmpty()const {
	return degree() == -1;
}
