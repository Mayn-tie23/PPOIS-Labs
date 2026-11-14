
#pragma once

#include <vector>
#include <iosfwd>

/**
 * @brief Represents a mathematical polynomial.
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
  explicit  Polynomial(const std::vector<double>& coeffs);

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
     * @param other Polynomial to copy from.
     * @return Reference to this polynomial.
     */
    Polynomial& operator=(const Polynomial& other);

    /**
     * @brief Sets the coefficient of a specified degree.
     * @param degree Degree of the term.
     * @param value New coefficient value.
     */
    void setCoefficient(int degree, double value);

    /**
     * @brief Returns the coefficient of a specified degree.
     * @param degree Degree of the term.
     * @return Coefficient value.
     */
    double getCoefficient(int degree) const;

    /**
     * @brief Returns the degree of the polynomial.
     * @return Degree of the polynomial.
     */
    int degree() const;

    /**
     * @brief Evaluates the polynomial at a given value.
     * @param x Value at which to evaluate.
     * @return Result of polynomial evaluation.
     */
    double evaluate(double x) const;

    /**
     * @brief Displays the polynomial.
     */
    void display() const;

    /**
     * @brief Adds another polynomial to this polynomial.
     * @param other Polynomial to add.
     * @return Resulting polynomial.
     */
    Polynomial add(const Polynomial& other) const;

    /**
     * @brief Subtracts another polynomial from this polynomial.
     * @param other Polynomial to subtract.
     * @return Resulting polynomial.
     */
    Polynomial subtract(const Polynomial& other) const;

    /**
     * @brief Multiplies this polynomial by another polynomial.
     * @param other Polynomial to multiply by.
     * @return Resulting polynomial.
     */
    Polynomial multiply(const Polynomial& other) const;

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
     * @brief Clears the polynomial coefficients.
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
