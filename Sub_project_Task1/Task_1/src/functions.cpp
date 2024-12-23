#include <iostream>
#include <string>
#include "all_functions.h"
void vvod(char* kod, int SIZE, std::string input) {
    for (int i = 0; i < SIZE; i++) {  // O(n)
        kod[i] = input[i];
    }
    kod[SIZE] = '\0';
}

void podschet(char* kod, int SIZE) {
    if (kod[0] == '1') {  // O(1)
        for (int i = 1; i < SIZE; i++) {  //O(n)
            if (kod[i] == '1') {
                kod[i] = '0';
            }
            else {
                kod[i] = '1';
            }
        }
    }
}

void vyvod(const char* kod, int SIZE) {
    std::cout << "Обратный код" << "\n";
    for (int i = 0; i < SIZE; i++) {  // O(n)
        std::cout << kod[i];  // O(1)
    }
}

int askToRunProgram() {
    char choice;
    std::cout << "\n";
    std::cout << "Хотите запустить программу? (y/n) " << "\n";
    while (true) {
        std::cin >> choice;
        if (std::cin.fail() || std::cin.peek() != '\n' || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            std::cout << "Введите y/n.\n";
            std::cin.clear();
            std::cin.ignore(100000000, '\n');
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

bool isValidInput(const std::string& input) {
    for (char ch : input) {
        if (ch != '0' && ch != '1') {
            return false;
        }
    }
    return true;
}
