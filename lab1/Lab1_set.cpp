#include <iostream>
#include "set/Set.h"
#include "polynomial/Polynomial.h"

int main() {
    int choice;

    do {
        std::cout << "\n===== PPOIS LAB 1 =====\n";
        std::cout << "1. Set\n";
        std::cout << "2. Polynomial\n";
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Set selected\n";
            break;
        case 2:
            std::cout << "Polynomial selected\n";
            break;
        case 0:
            std::cout << "Goodbye!\n";
            break;
        default:
            std::cout << "Invalid choice\n";
        }
    } while (choice != 0);

    return 0;
}