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
                std::cout<<"4. Check element\n";
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
                    mySet.remove(value);
                    std::cout << "Element removed\n";
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
            } while (setChoice != 0);
            break;
        }
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