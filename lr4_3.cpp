#include <iostream>
#include <cstdlib>

#define NUM_STRINGS 3 // ���������� �����

int main() {
    char** strings = (char**)calloc(NUM_STRINGS, sizeof(char*));

    if (!strings) {
        std::cerr << "������ ��������� ������!" << std::endl;
        return 1;
    }

    // ��������� ������ ��� ������ ������
    for (int i = 0; i < NUM_STRINGS; i++) {
        strings[i] = (char*)calloc(100, sizeof(char));
        if (!strings[i]) {
            std::cerr << "������ ��������� ������!" << std::endl;
            return 1;
        }
    }

    // ���� �����
    for (int i = 0; i < NUM_STRINGS; i++) {
        std::cout << "������� ������ " << i + 1 << ": ";
        std::cin.getline(strings[i], 100);
    }

    // ����� �����
    std::cout << "�� �����:\n";
    for (int i = 0; i < NUM_STRINGS; i++) {
        std::cout << "������ " << i + 1 << ": " << strings[i] << std::endl;
    }

    // ������������ ������
    for (int i = 0; i < NUM_STRINGS; i++) {
        free(strings[i]);
    }
    free(strings);

    return 0;
}