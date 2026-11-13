#include <iostream>
#include "set/Set.h"
#include "polynomial/Polynomial.h"

int main() {
    int choice;
    Set mySet;
    do {
        std::cout << "\n===== PPOIS LAB 1 =====\n";
        std::cout << "1. Set\n";
        std::cout << "2. Polynomial\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1: {
            int setChoice;
            do {
                std::cout << "n== SET MENU=====\n";
                std::cout << "1. Add element\n";
                std::cout << "2. Remove element\n";
                std::cout << "3. Display Set\n";
                std::cout << "4. Check element\n";
                std::cout << "5. Set size\n";
                std::cout << "6. Clear Set\n";
                std::cout << "7. Check if Set is empty\n";
                std::cout << "8. Get element by index\n";
                std::cout << "9. Compare two Sets\n";
                std::cout << "0. Back\n";
                std::cout << "Enter your choice:";
                std::cin >> setChoice;
                if (setChoice == 1) {
                    int value;
                    std::cout << "Enter element:";
                    std::cin >> value;
                    mySet.add(value);
                    std::cout << "Element added\n";
                }
                if (setChoice == 2) {
                    int value;
                    std::cout << "Enter element to remove:";
                    std::cin >> value;
                    if (mySet.contains(value)) {
                        mySet.remove(value);
                        std::cout << "Element removed\n";
                    }
                    else {
                        std::cout << "Elements not founf\n";
                    }
                }
                if (setChoice == 3) {
                    std::cout << "Set elements:";
                    mySet.display();
                }
                if (setChoice == 4) {
                    int value;
                    std::cout << "Enter elements to check:";
                    std::cin >> value;
                    if (mySet.contains(value)) {
                        std::cout << "Element found\n";
                    }
                    else {
                        std::cout << "Element not found\n";
                    }
                }
                if (setChoice == 5) {
                    std::cout << "Set size:"
                        << mySet.size() << "\n";
                }
                if (setChoice == 6) {
                    mySet.clear();
                    std::cout << "Set cleared\n";
                }
                if (setChoice == 7) {
                    if (mySet.isEmpty()) {
                        std::cout << "Set is empty\n";
                    }
                    else {
                        std::cout << "Set is not empty\n";
                    }
                }
                if (setChoice == 8) {
                    int index;
                    std::cout << "Enter index:";
                    std::cin >> index;
                    if (index >= 0 && index < mySet.size()) {
                        std::cout << "element:" << mySet.getElement(index) << "\n";
                    }
                    else {
                        std::cout << "Invalid index\n";
                    }
                }
                if (setChoice == 9) {
                    Set otherSet;
                    int count, value;
                    std::cout << "How many elements in the second Set?";
                    std::cin >> count;
                    if (count < 0) {
                        std::cout << "Invalid number of elements\n";
                    }
                    else {
                        for (int i = 0;i < count; i++) {
                            std::cout << "Enter elements:";
                            std::cin >> value;
                            otherSet.add(value);
                        }
                        if (mySet == otherSet) {
                            std::cout << "Sets are equal\n";
                        }
                        else {
                            std::cout << "Sets are not equal\n";
                        }
                    }
                }
            } while (setChoice != 0);
            break;
        }
        case 2: {
            Polynomial myPolynomial;
            int polyChoice;

            std::cout << "Polynomial selected\n";

            do {
                std::cout << "\n===== POLYNOMIAL MENU =====\n";
                std::cout << "1. Set coefficient\n";
                std::cout << "2. Get coefficient\n";
                std::cout << "3. Display polynomial\n";
                std::cout << "4. Get degree\n";
                std::cout << "5. Evaluate polynomial\n";
                std::cout << "6. Add polynomials\n";
                std::cout << "7. Subtract polynomials\n";
                std::cout << "8. Multiply polynomials\n";
                std::cout << "9. Compare polynomials\n";
                std::cout << "10. Clear polynomial\n";
                std::cout << "11. Check if empty\n";
                std::cout << "0. Back\n";
                std::cout << "Enter your choice: ";
                std::cin >> polyChoice;
                if (polyChoice == 1) {
                    int degree;
                    double value;
                    std::cout << "Enter degree:";
                    std::cin >> degree;

                    std::cout << "Enter coefficient: ";
                    std::cin >> value;

                    if (degree >= 0) {
                        myPolynomial.setCoefficient(degree, value);
                        std::cout << "Coefficient set\n";
                    }
                    else {
                        std::cout << "Invalid degree\n";
                    }
                }
                if (polyChoice == 2) {
                    int degree;

                    std::cout << "Enter degree: ";
                    std::cin >> degree;

                    if (degree >= 0) {
                        std::cout << "Coefficient: "
                            << myPolynomial.getCoefficient(degree) << "\n";
                    }
                    else {
                        std::cout << "Invalid degree\n";
                    }
                }
                if (polyChoice == 3) {
                    std::cout << "Polynomial: ";
                    myPolynomial.display();
                }
                if (polyChoice == 4) {
                    std::cout << "Polynomial degree: "
                        << myPolynomial.degree() << "\n";
                }
                if (polyChoice == 5) {
                    double x;

                    std::cout << "Enter x value: ";
                    std::cin >> x;

                    std::cout << "Result: "
                        << myPolynomial.evaluate(x) << "\n";
                }
                if (polyChoice == 6 || polyChoice == 9) {
                    Polynomial otherPolynomial;
                    int highestDegree;
                    double value;

                    std::cout << "Enter degree of second polynomial: ";
                    std::cin >> highestDegree;

                    if (highestDegree < 0) {
                        std::cout << "Invalid degree\n";
                    }
                    else {
                        for (int i = 0; i <= highestDegree; i++) {
                            std::cout << "Enter coefficient for x^" << i << ": ";
                            std::cin >> value;
                            otherPolynomial.setCoefficient(i, value);
                            if (polyChoice == 6) {
                                Polynomial result = myPolynomial.add(otherPolynomial);
                                std::cout << "Sum: ";
                                result.display();
                            }
                            else {
                                if (myPolynomial == otherPolynomial) {
                                    std::cout << "Polynomials are equal\n";
                                }
                                else {
                                    std::cout << "Polynomials are not equal\n";
                                }
                            }
                        }
                    }
                }
                if (polyChoice == 7 || polyChoice == 8) {
                    Polynomial otherPolynomial;
                    int highestDegree;
                    double value;

                    std::cout << "Enter degree of second polynomial: ";
                    std::cin >> highestDegree;

                    if (highestDegree < 0) {
                        std::cout << "Invalid degree\n";
                    }
                    else {
                        for (int i = 0; i <= highestDegree; i++) {
                            std::cout << "Enter coefficient for x^" << i << ": ";
                            std::cin >> value;
                            otherPolynomial.setCoefficient(i, value);
                        }
                        if (polyChoice == 7) {
                            Polynomial result = myPolynomial.subtract(otherPolynomial);
                            std::cout << "Difference: ";
                            result.display();
                        }
                        else {
                            Polynomial result = myPolynomial.multiply(otherPolynomial);
                            std::cout << "Product: ";
                            result.display();
                        }
                    }
                }
                if (polyChoice == 10) {
                    myPolynomial.clear();
                    std::cout << "Polynomial cleared\n";
                }
                if (polyChoice == 11) {
                    if (myPolynomial.isEmpty()) {
                        std::cout << "Polynomial is empty\n";
                    }
                    else {
                        std::cout << "Polynomial is not empty\n";
                    }
                }
            } while (polyChoice != 0);
            break;
        }
        case 0: {
            std::cout << "Goodbye!\n";
            break;
        }
        default:
            std::cout << "Invalid choice\n";
        }
        } while (choice != 0);
    return 0;
}