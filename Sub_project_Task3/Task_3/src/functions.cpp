#include "all_functions.h"
#include <iostream>
#include <string>
#include <limits>

// Генерация алфавита: O(n * log(n)), где n — основание системы счисления
std::string* Spisok(long long base, long long& size) {
    size = base;
    std::string* alph = new std::string[base];
    for (long long i = 0; i < base; ++i) {
        if (i < 10) {
            alph[i] = std::string(1, '0' + i);
        } else {
            long long val = i - 10;
            std::string sym;
            while (val >= 0) {
                sym = char('A' + val % 26) + sym;
                val = val / 26 - 1;
            }
            alph[i] = sym;
        }
    }
    return alph;
}

// Преобразование символа в значение: O(n), где n — размер алфавита
long long stv(const std::string& sym, std::string* alph, long long size) {
    for (long long i = 0; i < size; ++i) {
        if (alph[i] == sym) {
            return i;
        }
    }
    return -1;
}

// Преобразование значения в символ: O(1)
std::string vts(long long val, std::string* alph, long long size) {
    if (val < 0 || val >= size) {
        return "";
    }
    return alph[val];
}

// Сложение двух чисел: O(max(len1, len2) * n), где len1, len2 — длины строк, n — размер алфавита
std::string add(const std::string& n1, const std::string& n2, std::string* alph, long long size) {
    long long base = size;
    std::string result;
    long long carry = 0;
    unsigned long long len1 = n1.size(), len2 = n2.size();
    unsigned long long maxLen = std::max(len1, len2);

    for (unsigned long long i = 0; i < maxLen || carry > 0; ++i) {
        long long val1 = i < len1 ? stv(std::string(1, n1[len1 - 1 - i]), alph, size) : 0;
        long long val2 = i < len2 ? stv(std::string(1, n2[len2 - 1 - i]), alph, size) : 0;

        if (val1 == -1 || val2 == -1) {
            return "";
        }

        long long sum = val1 + val2 + carry;
        std::string sym = vts(sum % base, alph, size);

        if (sym.empty()) return "";

        result = sym + result;
        carry = sum / base;
    }

    return result;
}

// Вычитание двух чисел: O(max(len1, len2) * n), где len1, len2 — длины строк, n — размер алфавита
std::string subtract(const std::string& n1, const std::string& n2, std::string* alph, long long size) {
    long long base = size;
    std::string result;
    long long borrow = 0;

    unsigned long long len1 = n1.size(), len2 = n2.size();

    if (len1 < len2 || (len1 == len2 && n1 < n2)) {
        return "";
    }

    for (unsigned long long i = 0; i < len1; ++i) {
        long long val1 = stv(std::string(1, n1[len1 - 1 - i]), alph, size);
        long long val2 = i < len2 ? stv(std::string(1, n2[len2 - 1 - i]), alph, size) : 0;

        if (val1 == -1 || val2 == -1) {
            return "";
        }

        long long diff = val1 - val2 - borrow;

        if (diff < 0) {
            diff += base;
            borrow = 1;
        } else {
            borrow = 0;
        }

        std::string sym = vts(diff, alph, size);
        if (sym.empty()) {
            return "";
        }
        result = sym + result;
    }

    while (result.size() > 1 && result[0] == alph[0][0]) {
        result.erase(0, 1);
    }
    return result;
}

// Проверка числового ввода: O(1)
long double validate_input(const std::string& prompt) {
    long double value;
    while (true) {
        std::cout << prompt;
        std::cin >> value;
        if (std::cin.fail() || std::cin.peek() != '\n') {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Пожалуйста, введите корректное число!\n";
        } else {
            break;
        }
    }
    return value;
}

// Проверка строкового ввода: O(n), где n — длина строки
std::string validate_string_input(const std::string& prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        std::cin >> input;
        bool is_valid = true;
        for (char c : input) {
            if (!isdigit(c) && !(c >= 'A' && c <= 'Z')) {
                is_valid = false;
                break;
            }
        }
        if (is_valid) {
            break;
        } else {
            std::cout << "Некорректный ввод! Введите строку, содержащую только цифры или заглавные буквы английского алфавита.\n";
        }
    }
    return input;
}

// Выполнение операции сложения или вычитания: O(max(len1, len2) * n), где len1, len2 — длины строк, n — размер алфавита
void handle_operation() {
    long double base = validate_input("Введите основание системы счисления: ");
    if (base <= 0) {
        std::cout << "Основание системы счисления должно быть положительным.\n";
        return;
    }

    long long size;
    std::string* alphabet = Spisok(base, size);

    std::string num1 = validate_string_input("Введите первое число: ");
    std::string num2 = validate_string_input("Введите второе число: ");

    char operation;
    std::cout << "Введите операцию (+ или -): ";
    std::cin >> operation;

    if (operation == '+') {
        std::string result = add(num1, num2, alphabet, size);
        if (result.empty()) {
            std::cout << "Ошибка при выполнении сложения.\n";
        } else {
            std::cout << "Результат: " << result << "\n";
        }
    } else if (operation == '-') {
        std::string result = subtract(num1, num2, alphabet, size);
        if (result.empty()) {
            std::cout << "Ошибка при выполнении вычитания.\n";
        } else {
            std::cout << "Результат: " << result << "\n";
        }
    } else {
        std::cout << "Неподдерживаемая операция.\n";
    }

    delete[] alphabet;
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
