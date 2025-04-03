#include <iostream>
#include <cstdlib>

int main() {
    // ������������� calloc ������ malloc
    char* str1 = (char*)calloc(100, sizeof(char));
    char* str2 = (char*)calloc(100, sizeof(char));

    if (!str1 || !str2) {
        std::cerr << "������ ��������� ������!" << std::endl;
        return 1;
    }

    std::cout << "������� ������ ������: ";
    std::cin.getline(str1, 100);

    std::cout << "������� ������ ������: ";
    std::cin.getline(str2, 100);

    std::cout << "������ 1: " << str1 << std::endl;
    std::cout << "������ 2: " << str2 << std::endl;

    free(str1);
    free(str2);

    return 0;
}