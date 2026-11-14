
#pragma once

#include <vector>
#include <iosfwd>

/**
 * @brief Represents a single-variable mathematical polynomial.
 *
 * Stores polynomial coefficients and supports
 * arithmetic operations, evaluation, and comparison.
 */
class Polynomial {
private:
    std::vector<double> coefficients;

public:
    /**
     * @brief Creates an empty polynomial.
     */
    Polynomial();

    /**
     * @brief Creates a polynomial from coefficients.
     * @param coeffs Vector containing polynomial coefficients.
     */
    explicit Polynomial(const std::vector<double>& coeffs);

    /**
     * @brief Creates a copy of another polynomial.
     * @param other Polynomial to copy.
     */
    Polynomial(const Polynomial& other);

    /**
     * @brief Destroys the Polynomial object.
     */
    ~Polynomial();

    /**
     * @brief Assigns another polynomial to this polynomial.
     * @param other Polynomial to copy.
     * @return Reference to this polynomial.
     */
    Polynomial& operator=(const Polynomial& other);

    /**
     * @brief Sets a coefficient.
     * @param degree Degree of the term.
     * @param value New coefficient value.
     */
    void setCoefficient(int degree, double value);

    /**
     * @brief Gets a coefficient.
     * @param degree Degree of the term.
     * @return Coefficient value.
     */
    double getCoefficient(int degree) const;

    /**
     * @brief Returns the polynomial degree.
     * @return Highest degree with a nonzero coefficient.
     */
    int degree() const;

    /**
     * @brief Evaluates the polynomial at x.
     * @param x Value to evaluate.
     * @return Polynomial value.
     */
    double evaluate(double x) const;

    /**
     * @brief Retrieves a coefficient using indexing.
     * @param termDegree Degree of the term.
     * @return Coefficient value.
     */
    double operator[](int termDegree) const;

    /**
     * @brief Evaluates the polynomial using function-call syntax.
     * @param x Value to evaluate.
     * @return Polynomial value.
     */
    double operator()(double x) const;

    /**
     * @brief Displays the polynomial.
     */
    void display() const;

    /**
     * @brief Adds another polynomial.
     * @param other Polynomial to add.
     * @return Sum.
     */
    Polynomial add(const Polynomial& other) const;

    /**
     * @brief Subtracts another polynomial.
     * @param other Polynomial to subtract.
     * @return Difference.
     */
    Polynomial subtract(const Polynomial& other) const;

    /**
     * @brief Multiplies by another polynomial.
     * @param other Polynomial to multiply.
     * @return Product.
     */
    Polynomial multiply(const Polynomial& other) const;

    /**
     * @brief Divides by another polynomial.
     * @param other Divisor polynomial.
     * @return Quotient.
     * @throws std::invalid_argument If the divisor is zero.
     */
    Polynomial divide(const Polynomial& other) const;

    /**
     * @brief Adds two polynomials.
     * @param other Polynomial to add.
     * @return Sum.
     */
    Polynomial operator+(const Polynomial& other) const;

    /**
     * @brief Subtracts two polynomials.
     * @param other Polynomial to subtract.
     * @return Difference.
     */
    Polynomial operator-(const Polynomial& other) const;

    /**
     * @brief Multiplies two polynomials.
     * @param other Polynomial to multiply.
     * @return Product.
     */
    Polynomial operator*(const Polynomial& other) const;

    /**
     * @brief Divides two polynomials.
     * @param other Divisor polynomial.
     * @return Quotient.
     */
    Polynomial operator/(const Polynomial& other) const;

    /**
     * @brief Adds another polynomial to this polynomial.
     * @param other Polynomial to add.
     * @return Reference to this polynomial.
     */
    Polynomial& operator+=(const Polynomial& other);

    /**
     * @brief Subtracts another polynomial from this polynomial.
     * @param other Polynomial to subtract.
     * @return Reference to this polynomial.
     */
    Polynomial& operator-=(const Polynomial& other);

    /**
     * @brief Multiplies this polynomial by another.
     * @param other Polynomial to multiply.
     * @return Reference to this polynomial.
     */
    Polynomial& operator*=(const Polynomial& other);

    /**
     * @brief Divides this polynomial by another.
     * @param other Divisor polynomial.
     * @return Reference to this polynomial.
     */
    Polynomial& operator/=(const Polynomial& other);

    /**
     * @brief Checks whether two polynomials are equal.
     * @param other Polynomial to compare.
     * @return True if equal, otherwise false.
     */
    bool operator==(const Polynomial& other) const;

    /**
     * @brief Checks whether two polynomials are different.
     * @param other Polynomial to compare.
     * @return True if different, otherwise false.
     */
    bool operator!=(const Polynomial& other) const;

    /**
     * @brief Removes all coefficients.
     */
    void clear();

    /**
     * @brief Checks whether the polynomial is empty.
     * @return True if empty, otherwise false.
     */
    bool isEmpty() const;
};

/**
 * @brief Writes a polynomial to an output stream.
 * @param out Output stream.
 * @param polynomial Polynomial to write.
 * @return Reference to the output stream.
 */
std::ostream& operator<<(std::ostream& out,
    const Polynomial& polynomial);

/**
 * @brief Reads a polynomial from an input stream.
 * @param in Input stream.
 * @param polynomial Polynomial to populate.
 * @return Reference to the input stream.
 */
std::istream& operator>>(std::istream& in,
    Polynomial& polynomial);

