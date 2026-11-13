#pragma once
#include <vector>
#include <iosfwd>

class Polynomial {
private:
	std::vector <double> coefficients;
public:
	Polynomial();
	Polynomial(const std::vector<double>& coeffs);
	Polynomial(const Polynomial& other);
	~Polynomial();
	Polynomial& operator=(const Polynomial& other);
	void setCoefficient(int degree, double value);
	double getCoefficient(int degree)const;
	int degree()const;
	double evaluate(double x)const;
	void display()const;
	Polynomial add(const Polynomial& other)const;
	Polynomial subtract(const Polynomial& other)const;
	Polynomial multiply(const Polynomial& other)const;
	bool operator==(const Polynomial& other)const;
	bool operator!=(const Polynomial& other) const;
	void clear();
	bool isEmpty() const;
};
std::ostream& operator<<(std::ostream& out, const Polynomial& polynomial);
std::istream& operator>>(std::istream& in, Polynomial& polynomial);

