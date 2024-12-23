#include <iostream>
#include <string>
#include "all_functions.h"



int main() {
    while(askToRunProgram()==1) {
        std::string input1;
        std::string input2;

        do {
            std::cout << "Введите первое число в двоичной форме (первая цифра — знаковый бит)\n";
            std::cin >> input1;

            if (!isValidInput(input1)) {
                std::cout << "Ошибка: ввод должен содержать только символы '0' и '1'. Попробуйте снова.\n";
            }
        } while (!isValidInput(input1));

        do {
            std::cout << "Введите второе число в двоичной форме (первая цифра — знаковый бит)\n";
            std::cin >> input2;

            if (!isValidInput(input2)) {
                std::cout << "Ошибка: ввод должен содержать только символы '0' и '1'. Попробуйте снова.\n";
            }
        } while (!isValidInput(input2));

        int SIZE = input1.size();
        char* kod = new char[SIZE + 1];
        int SIZE2 = input2.size();
        char* kod2 = new char[SIZE2 + 1];

        vvod(kod, SIZE, input1);
        vvod(kod2, SIZE2, input2);

        std::cout << "Первое число\n" << kod << "\n";
        podschet(kod, SIZE);
        std::cout << "Обратный код: " << "\n";
        vyvod(kod, SIZE);

        dop(kod, SIZE);
        std::cout << "Дополнительный код: " << "\n";
        vyvod(kod, SIZE);

        std::cout << "Второе число\n" << kod2 << "\n";
        podschet(kod2, SIZE2);
        std::cout << "Обратный код: " << "\n";
        vyvod(kod2, SIZE2);

        dop(kod2, SIZE2);
        std::cout << "Дополнительный код: " << "\n";
        vyvod(kod2, SIZE2);

        std::cout << "Сумма" << "\n";
        summa(kod, kod2, SIZE, SIZE2);

        delete[] kod;
        delete[] kod2;
    }
    return 0;
}
