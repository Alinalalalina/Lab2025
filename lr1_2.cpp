#include <iostream>

#define PR(x) std::cout << #x << " = " << (x) << "\t *" << #x << " = " << *(x) << "\t &" << #x << " = " << &(x) << std::endl;

int main()
{
    // ������������� ������� �� 3 ����� �����
    int mas[] = { 100, 200, 300 };

    // ���������� ���� ���������� �� int
    int* ptr1, * ptr2;

    ptr1 = mas;

    // ptr2 ����������� ����� �������� �������� �������
    ptr2 = &mas[2];

    PR(ptr1);

    ptr1++;

    PR(ptr1);

    PR(ptr2);

    ++ptr2;

    // ��������� ������� ����� ����������� (� ��������� �������)
    std::cout << "ptr2 - ptr1 = " << ptr2 - ptr1 << std::endl;

    return 0;
}