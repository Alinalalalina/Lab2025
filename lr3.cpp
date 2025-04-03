#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 10  // ������ �������

using namespace std;

// ������� ��� ������ ������� � �������
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ���������� ������� (����� ������������ �������� � �����)
void minMaxSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;  // ������ ������������ ��������
        // ����� ������������ �������� � ���������� ����� �������
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // ����� �������� �������� � �����������
        swap(arr[i], arr[minIndex]);
    }
}

// ����������� ����������
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // ������ �� ������� � ��������� �������� ���������
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);  // ����� ���������, ���� ��� � ������������ �������
            }
        }
    }
}

// ��������������� ������� ��� ������� ���������� (���������� �������)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // ������� ������� (��������� ������� �������)
    int i = low - 1;  // ������ �������� ��������

    for (int j = low; j < high; j++) {
        // ���� ������� ������� ������ ��� ����� ��������
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // ����� ���������
        }
    }
    swap(arr[i + 1], arr[high]);  // ����� �������� �������� � ��������� �� ������� i+1
    return i + 1;  // ������� ������� �������� ��������
}

// ������� ���������� (����������� ����������)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi - ������ �������� ��������
        int pi = partition(arr, low, high);
        // ����������� ���������� ����� � ������ ������
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// ���������� ������ ��������� �� �����������, �������� - �� ��������
void sortEvenAscendingOddDescending(int arr[], int size) {
    int evens[SIZE], odds[SIZE], evenCount = 0, oddCount = 0;

    // ���������� ������� �� ������ � �������� ��������
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evens[evenCount++] = arr[i];  // ������ ��������
        }
        else {
            odds[oddCount++] = arr[i];     // �������� ��������
        }
    }

    // ���������� ������ ��������� �� �����������
    bubbleSort(evens, evenCount);
    // ���������� �������� ��������� �� �����������
    bubbleSort(odds, oddCount);

    // ������ ������� �������� ��������� (��� ���������� �� ��������)
    for (int i = 0; i < oddCount / 2; i++) {
        swap(odds[i], odds[oddCount - i - 1]);
    }

    // ������� �������� ������� � ��������
    int index = 0;
    for (int i = 0; i < evenCount; i++) arr[index++] = evens[i];
    for (int i = 0; i < oddCount; i++) arr[index++] = odds[i];
}

// ���������� ��������� ������� �� ����������� (�� n1 �� n2 ������������)
void sortRangeAscending(int arr[], int n1, int n2) {
    // ���������� ����������� ���������� ��� ���������� ���������
    bubbleSort(arr + n1, n2 - n1 + 1);
}

// ���������� ��������� ������� �� �������� (�� n1 �� n2 ������������)
void sortRangeDescending(int arr[], int n1, int n2) {
    // ������� ��������� �� �����������
    bubbleSort(arr + n1, n2 - n1 + 1);
    // ����� ����������� �������� ��� ��������� ���������� �������
    for (int i = n1, j = n2; i < j; i++, j--) {
        swap(arr[i], arr[j]);
    }
}

int main() {
    srand(time(0));  // ������������� ���������� ��������� �����
    int arr[SIZE];   // ���������� �������

    // ������������ ��������� ����������
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100 - 50;  // ���������� ������� ���������� ������� �� -50 �� 49
    }
    cout << "Original array: ";
    printArray(arr, SIZE);

    // ������������ ���������� �������
    minMaxSort(arr, SIZE);
    cout << "Min-Max Sorted: ";
    printArray(arr, SIZE);

    // ������������ ����������� ����������
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    bubbleSort(arr, SIZE);
    cout << "Bubble Sorted: ";
    printArray(arr, SIZE);

    // ������������ ������� ����������
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    quickSort(arr, 0, SIZE - 1);
    cout << "Quick Sorted: ";
    printArray(arr, SIZE);

    // ������������ ���������� ������/��������
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    sortEvenAscendingOddDescending(arr, SIZE);
    cout << "Sorted Even Ascending, Odd Descending: ";
    printArray(arr, SIZE);

    // ������������ ���������� ��������� �� �����������
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    sortRangeAscending(arr, 2, 7);
    cout << "Sorted in range (2-7) Ascending: ";
    printArray(arr, SIZE);

    // ������������ ���������� ��������� �� ��������
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    sortRangeDescending(arr, 2, 7);
    cout << "Sorted in range (2-7) Descending: ";
    printArray(arr, SIZE);

    return 0;
}