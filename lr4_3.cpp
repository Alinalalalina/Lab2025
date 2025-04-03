#include <iostream>
#include <cstdlib>

#define NUM_STRINGS 3 // Количество строк

int main() {
    char** strings = (char**)calloc(NUM_STRINGS, sizeof(char*));

    if (!strings) {
        std::cerr << "Ошибка выделения памяти!" << std::endl;
        return 1;
    }

    // Выделение памяти под каждую строку
    for (int i = 0; i < NUM_STRINGS; i++) {
        strings[i] = (char*)calloc(100, sizeof(char));
        if (!strings[i]) {
            std::cerr << "Ошибка выделения памяти!" << std::endl;
            return 1;
        }
    }

    // Ввод строк
    for (int i = 0; i < NUM_STRINGS; i++) {
        std::cout << "Введите строку " << i + 1 << ": ";
        std::cin.getline(strings[i], 100);
    }

    // Вывод строк
    std::cout << "Вы ввели:\n";
    for (int i = 0; i < NUM_STRINGS; i++) {
        std::cout << "Строка " << i + 1 << ": " << strings[i] << std::endl;
    }

    // Освобождение памяти
    for (int i = 0; i < NUM_STRINGS; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}