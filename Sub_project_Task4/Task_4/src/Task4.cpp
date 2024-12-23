#include "all_functions.h"
#include <iostream>
#include <limits>




int main() {
    while (askToRunProgram() == 1) {
        std::cout << "В данном задании необходимо было проверить делимости числа на 3, 37, 89 не используя умножение, деление и остаток от деления\n"
                  << "Агейчик Влад\n"
                  << "Вариант 1\n";

        long double num = check();
        const int num1 = 3;
        const int num2 = 37;
        const int num3 = 89;
        num = (num < 0) ? -num : num;
        std::cout << "На " << num1 << ": " << (isDivisible(num, num1) ? "Да" : "Нет") << '\n';
        std::cout << "На " << num2 << ": " << (isDivisible(num, num2) ? "Да" : "Нет") << '\n';
        std::cout << "На " << num3 << ": " << (isDivisible(num, num3) ? "Да" : "Нет") << '\n';
    }
    return 0;
}
