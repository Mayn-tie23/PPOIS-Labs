#include "../polynomial/Polynomial.h"
#include <cassert>
#include <iostream>
#include <vector>

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

    std::cout << "All Polynomial tests passed!\n";
    return 0;
}