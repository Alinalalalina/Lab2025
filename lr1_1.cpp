#include <iostream>

using namespace std;

// ������� ��� ���������� �������
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++)
        result *= base;
    return result;
}

int main() {
    int base, exponent;

    // ���� ����� � �������
    cout << "������� �����: ";
    cin >> base;
    cout << "������� �������: ";
    cin >> exponent;

    // ���������� � ����� ����������
    int result = power(base, exponent);
    cout << base << " � ������� " << exponent << " = " << result << endl;

    return 0;
}