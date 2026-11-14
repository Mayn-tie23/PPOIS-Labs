#include "../polynomial/Polynomial.h"
#include <cassert>
#include <iostream>
#include <vector>
#include <sstream>
#include <stdexcept>
int main() {
    Polynomial p;

    assert(p.isEmpty());
    assert(p.degree() == -1);

    p.setCoefficient(2, 5);
    assert(p.getCoefficient(2) == 5);
    assert(p.degree() == 2);
    assert(p.evaluate(2) == 20);

    p.setCoefficient(0, 3);
    assert(p.evaluate(2) == 23);

    Polynomial q(std::vector<double>{1, 2});

    Polynomial sum = p.add(q);
    assert(sum.getCoefficient(0) == 4);
    assert(sum.getCoefficient(1) == 2);
    assert(sum.getCoefficient(2) == 5);

    Polynomial difference = p.subtract(q);
    assert(difference.getCoefficient(0) == 2);
    assert(difference.getCoefficient(1) == -2);

    Polynomial product = p.multiply(q);
    assert(product.evaluate(2) == 115);

    Polynomial copied(p);
    assert(copied == p);

    Polynomial assigned;
    assigned = p;
    assert(assigned == p);
    assert(assigned != q);

    p.display();
    p.clear();
    assert(p.isEmpty());
    // Test Polynomial stream input and output
    Polynomial original({ 3.0, 2.0, 5.0 });

    std::stringstream stream;
    stream << original;

    Polynomial loaded;
    stream >> loaded;

    assert(loaded == original);

    std::cout << "All Polynomial tests passed!\n";

    // Test polynomial indexing and function-call operators
    Polynomial operatorTest({ 3.0, 2.0, 5.0 });

    assert(operatorTest[0] == 3.0);
    assert(operatorTest[1] == 2.0);
    assert(operatorTest[2] == 5.0);

    assert(operatorTest(2.0) == 27.0);

    // Test polynomial division
    Polynomial dividend({ 2.0, 3.0, 1.0 });
    Polynomial divisor({ 1.0, 1.0 });
    Polynomial expectedQuotient({ 2.0, 1.0 });

    assert(dividend.divide(divisor) == expectedQuotient);
    assert((dividend / divisor) == expectedQuotient);

    // Test compound division
    Polynomial divisionResult = dividend;
    divisionResult /= divisor;
    assert(divisionResult == expectedQuotient);

    // Test division by a higher-degree polynomial
    Polynomial smaller({ 1.0 });
    assert((smaller / divisor) == Polynomial({ 0.0 }));

    // Test division by zero
    bool exceptionCaught = false;

    try {
        Polynomial zeroPolynomial({ 0.0 });
        Polynomial result = dividend / zeroPolynomial;
        (void)result;
    }
    catch (const std::invalid_argument&) {
        exceptionCaught = true;
    }

    assert(exceptionCaught);

    // Test arithmetic operators
    Polynomial arithmeticA({ 1.0, 2.0 });
    Polynomial arithmeticB({ 3.0, 4.0 });

    assert((arithmeticA + arithmeticB) ==
        Polynomial({ 4.0, 6.0 }));

    assert((arithmeticA - arithmeticB) ==
        Polynomial({ -2.0, -2.0 }));

    assert((arithmeticA * arithmeticB) ==
        Polynomial({ 3.0, 10.0, 8.0 }));

    // Test compound assignment operators
    Polynomial compoundTest = arithmeticA;

    compoundTest += arithmeticB;
    assert(compoundTest == Polynomial({ 4.0, 6.0 }));

    compoundTest = arithmeticA;
    compoundTest -= arithmeticB;
    assert(compoundTest == Polynomial({ -2.0, -2.0 }));

    compoundTest = arithmeticA;
    compoundTest *= arithmeticB;
    assert(compoundTest == Polynomial({ 3.0, 10.0, 8.0 }));



    return 0;
}

