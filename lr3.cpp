#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 10  // Размер массива

using namespace std;

// Функция для вывода массива в консоль
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Сортировка выбором (поиск минимального элемента и обмен)
void minMaxSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;  // Индекс минимального элемента
        // Поиск минимального элемента в оставшейся части массива
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        // Обмен текущего элемента с минимальным
        swap(arr[i], arr[minIndex]);
    }
}

// Пузырьковая сортировка
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Проход по массиву и сравнение соседних элементов
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);  // Обмен элементов, если они в неправильном порядке
            }
        }
    }
}

// Вспомогательная функция для быстрой сортировки (разделение массива)
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Опорный элемент (последний элемент массива)
    int i = low - 1;  // Индекс меньшего элемента

    for (int j = low; j < high; j++) {
        // Если текущий элемент меньше или равен опорному
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);  // Обмен элементов
        }
    }
    swap(arr[i + 1], arr[high]);  // Обмен опорного элемента с элементом на позиции i+1
    return i + 1;  // Возврат индекса опорного элемента
}

// Быстрая сортировка (рекурсивная реализация)
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        // pi - индекс опорного элемента
        int pi = partition(arr, low, high);
        // Рекурсивная сортировка левой и правой частей
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Сортировка четных элементов по возрастанию, нечетных - по убыванию
void sortEvenAscendingOddDescending(int arr[], int size) {
    int evens[SIZE], odds[SIZE], evenCount = 0, oddCount = 0;

    // Разделение массива на четные и нечетные элементы
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            evens[evenCount++] = arr[i];  // Четные элементы
        }
        else {
            odds[oddCount++] = arr[i];     // Нечетные элементы
        }
    }

    // Сортировка четных элементов по возрастанию
    bubbleSort(evens, evenCount);
    // Сортировка нечетных элементов по возрастанию
    bubbleSort(odds, oddCount);

    // Реверс массива нечетных элементов (для сортировки по убыванию)
    for (int i = 0; i < oddCount / 2; i++) {
        swap(odds[i], odds[oddCount - i - 1]);
    }

    // Слияние массивов обратно в исходный
    int index = 0;
    for (int i = 0; i < evenCount; i++) arr[index++] = evens[i];
    for (int i = 0; i < oddCount; i++) arr[index++] = odds[i];
}

// Сортировка диапазона массива по возрастанию (от n1 до n2 включительно)
void sortRangeAscending(int arr[], int n1, int n2) {
    // Используем пузырьковую сортировку для указанного диапазона
    bubbleSort(arr + n1, n2 - n1 + 1);
}

// Сортировка диапазона массива по убыванию (от n1 до n2 включительно)
void sortRangeDescending(int arr[], int n1, int n2) {
    // Сначала сортируем по возрастанию
    bubbleSort(arr + n1, n2 - n1 + 1);
    // Затем реверсируем диапазон для получения убывающего порядка
    for (int i = n1, j = n2; i < j; i++, j--) {
        swap(arr[i], arr[j]);
    }
}

int main() {
    srand(time(0));  // Инициализация генератора случайных чисел
    int arr[SIZE];   // Объявление массива

    // Демонстрация различных сортировок
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100 - 50;  // Заполнение массива случайными числами от -50 до 49
    }
    cout << "Original array: ";
    printArray(arr, SIZE);

    // Тестирование сортировки выбором
    minMaxSort(arr, SIZE);
    cout << "Min-Max Sorted: ";
    printArray(arr, SIZE);

    // Тестирование пузырьковой сортировки
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    bubbleSort(arr, SIZE);
    cout << "Bubble Sorted: ";
    printArray(arr, SIZE);

    // Тестирование быстрой сортировки
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    quickSort(arr, 0, SIZE - 1);
    cout << "Quick Sorted: ";
    printArray(arr, SIZE);

    // Тестирование сортировки четных/нечетных
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    sortEvenAscendingOddDescending(arr, SIZE);
    cout << "Sorted Even Ascending, Odd Descending: ";
    printArray(arr, SIZE);

    // Тестирование сортировки диапазона по возрастанию
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    sortRangeAscending(arr, 2, 7);
    cout << "Sorted in range (2-7) Ascending: ";
    printArray(arr, SIZE);

    // Тестирование сортировки диапазона по убыванию
    for (int i = 0; i < SIZE; i++) arr[i] = rand() % 100 - 50;
    sortRangeDescending(arr, 2, 7);
    cout << "Sorted in range (2-7) Descending: ";
    printArray(arr, SIZE);

    return 0;
}