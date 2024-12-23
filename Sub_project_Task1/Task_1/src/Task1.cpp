#include <iostream>
#include <string>
#include "all_functions.h"

int main() //O(7n)
{
    while (askToRunProgram() == 1) {
        std::cout << "В данном задании необходимо было перевести число из прямого кода в обратный\n"
                  << "Агейчик Влад\n"
                  << "Вариант 1\n";
        std::string input;

        do {
            std::cout << "Введите прямой код своего числа (только 0 и 1):\n";  // O(1)
            std::cin >> input;  // O(n) — ввод строки

            if (!isValidInput(input)) {
                std::cout << "Ошибка: ввод должен содержать только символы '0' и '1'. Попробуйте снова.\n";
            }
        } while (!isValidInput(input));  // O(n)

        std::cout << "Размер строки " << input.size() << "\n";  // O(1)
        int SIZE = input.size();  // O(1) — присваивание размера строки

        char* kod = new char[SIZE + 1];  // O(n)
        vvod(kod, SIZE, input);//O(n)
        podschet(kod, SIZE); //O(n)
        vyvod(kod, SIZE); //O(n)
        delete[] kod;  // O(n)
    }
    return 0;
}
