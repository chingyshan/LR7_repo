#include "all_functions.h"
#include "iostream"
#include <limits>

// Проверка делимости числа n на p: O((n/p) * logn)
bool isDivisible(int n, int p) {
    int r = n;
    while (r >= p) { // O(n/p)
        int s = p;
        while ((s << 1) <= r) { // O(logn)
            s <<= 1;
        }
        r -= s;
    }
    return r == 0;
}

// Проверка корректности числового ввода: O(1)
long double check() {
    long double number;
    std::cout << "Введите число: ";
    while (true) {
        std::cin >> number;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Введите число: ";
        } else {
            return number;
        }
    }
}

// Запрос запуска программы: O(1)
int askToRunProgram() {
    char choice;
    std::cout << "\n";
    std::cout << "Хотите запустить программу? (y/n) " << "\n";
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || std::cin.peek() != '\n' || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            std::cout << "Введите y/n.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        if (choice == 'n' || choice == 'N') {
            std::cout << "Спасибо за использование.\n";
            return 0;
        }

        if (choice == 'y' || choice == 'Y') {
            return 1;
        }
    }
}
