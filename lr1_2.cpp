#include <iostream>

#define PR(x) std::cout << #x << " = " << (x) << "\t *" << #x << " = " << *(x) << "\t &" << #x << " = " << &(x) << std::endl;

int main()
{
    // Инициализация массива из 3 целых чисел
    int mas[] = { 100, 200, 300 };

    // Объявление двух указателей на int
    int* ptr1, * ptr2;

    ptr1 = mas;

    // ptr2 присваиваем адрес третьего элемента массива
    ptr2 = &mas[2];

    PR(ptr1);

    ptr1++;

    PR(ptr1);

    PR(ptr2);

    ++ptr2;

    // Вычисляем разницу между указателями (в элементах массива)
    std::cout << "ptr2 - ptr1 = " << ptr2 - ptr1 << std::endl;

    return 0;
}