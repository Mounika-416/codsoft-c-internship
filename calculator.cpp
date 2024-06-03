#include <iostream>

void printMenu() {
    std::cout << "Select an operation:\n";
    std::cout << "1. Addition (+)\n";
    std::cout << "2. Subtraction (-)\n";
    std::cout << "3. Multiplication (*)\n";
    std::cout << "4. Division (/)\n";
    std::cout << "5. Exit\n";
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b == 0) {
        std::cerr << "Error: Division by zero is not allowed.\n";
        return 0;
    }
    return a / b;
}

int main() {
    int choice;
    double num1, num2, result;

    while (true) {
        printMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        if (choice == 5) {
            std::cout << "Exiting the program.\n";
            break;
        }

        if (choice < 1 || choice > 5) {
            std::cerr << "Invalid choice. Please try again.\n";
            continue;
        }

        std::cout << "Enter first number: ";
        std::cin >> num1;
        std::cout << "Enter second number: ";
        std::cin >> num2;

        switch (choice) {
            case 1:
                result = add(num1, num2);
                std::cout << "Result: " << num1 << " + " << num2 << " = " << result << "\n";
                break;
            case 2:
                result = subtract(num1, num2);
                std::cout << "Result: " << num1 << " - " << num2 << " = " << result << "\n";
                break;
            case 3:
                result = multiply(num1, num2);
                std::cout << "Result: " << num1 << " * " << num2 << " = " << result << "\n";
                break;
            case 4:
                result = divide(num1, num2);
                if (num2 != 0) {
                    std::cout << "Result: " << num1 << " / " << num2 << " = " << result << "\n";
                }
                break;
            default:
                std::cerr << "Invalid choice.\n";
                break;
        }
    }

    return 0;
}

