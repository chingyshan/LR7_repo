#include <iostream>
#include <string>

// Функция запроса запуска программы: O(1)
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

// Ввод данных: O(n)
void vvod(char* kod, int SIZE, std::string input) {
    for (int i = 0; i < SIZE; i++) {
        kod[i] = input[i];
    }
    kod[SIZE] = '\0';  // Добавляем нулевой терминатор
}

// Инверсия битов для отрицательных чисел: O(n)
void podschet(char* kod, int SIZE) {
    if (kod[0] == '1') {  // Если знак числа отрицателен, инвертируем все биты
        for (int i = 1; i < SIZE; i++) {
            kod[i] = (kod[i] == '1') ? '0' : '1';
        }
    }
}

// Вывод данных: O(n)
void vyvod(const char* kod, int SIZE) {
    for (int i = 0; i < SIZE; i++) {
        std::cout << kod[i];
    }
    std::cout << std::endl;
}

// Перевод в дополнительный код: O(n)
void dop(char* kod, int SIZE) {
    if (kod[0] == '1') { // Если знак отрицателен
        for (int i = SIZE - 1; i >= 0; --i) {
            if (kod[i] == '0') {
                kod[i] = '1';  // Перенос завершен
                break;
            } else {
                kod[i] = '0';  // Обработка переноса
            }
        }
    }
}

// Перевод из дополнительного в прямой код: O(n)
void dop_to_pryam(char* kod, int SIZE) {
    if (kod[0] == '1') {
        for (int i = 1; i < SIZE; i++) {
            kod[i] = (kod[i] == '0') ? '1' : '0';  // Инвертируем
        }
        bool carry = true;  // Прибавляем 1
        for (int i = SIZE - 1; i >= 1 && carry; --i) {
            if (kod[i] == '0') {
                kod[i] = '1';
                carry = false;
            } else {
                kod[i] = '0';
            }
        }
    }
}

// Сложение двух чисел: O(n)
void summa(const char* kod1, const char* kod2, int SIZE1, int SIZE2) {
    int maxSize = std::max(SIZE1, SIZE2);  // Наибольший размер
    char* new_Kod = new char[maxSize + 2]; // +1 для переноса и +1 для \0
    int carry = 0; // Переменная для переноса

    int i1 = SIZE1 - 1; // Индекс первого числа
    int i2 = SIZE2 - 1; // Индекс второго числа
    int iResult = maxSize; // Индекс результата

    new_Kod[iResult + 1] = '\0'; // Завершающий символ

    // Сложение
    while (i1 >= 0 || i2 >= 0 || carry) {
        int bit1 = (i1 >= 0) ? kod1[i1--] - '0' : 0;
        int bit2 = (i2 >= 0) ? kod2[i2--] - '0' : 0;

        int sum = bit1 + bit2 + carry;
        new_Kod[iResult--] = (sum % 2) + '0';
        carry = sum / 2;
    }

    // Добавляем знаковый бит
    new_Kod[0] = (kod1[0] == kod2[0]) ? kod1[0] : ((carry > 0) ? '0' : '1');

    char* trimmed_Kod = new char[maxSize + 2];
    std::copy(new_Kod + 1, new_Kod + maxSize + 1, trimmed_Kod);
    trimmed_Kod[maxSize] = '\0';

    std::cout << "Результат суммы (Доп. код): " << trimmed_Kod << std::endl;

    // Переводим в прямой код
    dop_to_pryam(trimmed_Kod, maxSize);
    std::cout << "Результат суммы (Прямой код): " << trimmed_Kod << std::endl;

    delete[] new_Kod;
    delete[] trimmed_Kod;
}

// Проверка входных данных: O(n)
bool isValidInput(const std::string& input) {
    for (char ch : input) {
        if (ch != '0' && ch != '1') {
            return false;
        }
    }
    return true;
}
