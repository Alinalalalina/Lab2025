#include <iostream>
#include <iomanip>    // Для форматированного вывода (setw, setprecision)
#include <cstdlib>     // Для функции rand()
#include <climits>     // Для констант целочисленных типов
#include <cmath>       // Для математических функций (fabs)

#define N 5            // Размер квадратной матрицы

using namespace std;

// Функция заполнения матрицы случайными значениями от 0.0 до 9.9
void fillMatrix(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = rand() % 100 / 10.0;  // rand()%100 дает 0-99, деление на 10.0 дает 0.0-9.9
        }
    }
}

// Функция вывода матрицы с форматированием
void printMatrix(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // setw(8) - ширина поля вывода, setprecision(5) - точность 5 знаков
            cout << setw(8) << setprecision(5) << m[i][j] << " ";
        }
        cout << endl;
    }
}

// Нахождение минимального значения в матрице
float findMin(float m[N][N]) {
    float minVal = m[0][0];  // Начальное предположение
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] < minVal) minVal = m[i][j];
    return minVal;
}

// Нахождение максимального значения в матрице
float findMax(float m[N][N]) {
    float maxVal = m[0][0];  // Начальное предположение
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] > maxVal) maxVal = m[i][j];
    return maxVal;
}

// Нахождение минимального значения на главной диагонали
float findMinDiagonal(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++)
        if (m[i][i] < minVal) minVal = m[i][i];  // Главная диагональ: i == j
    return minVal;
}

// Нахождение максимального значения на главной диагонали
float findMaxDiagonal(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++)
        if (m[i][i] > maxVal) maxVal = m[i][i];
    return maxVal;
}

// Нахождение минимального значения на побочной диагонали
float findMinSecondaryDiagonal(float m[N][N]) {
    float minVal = m[0][N - 1];  // Начинаем с правого верхнего элемента
    for (int i = 0; i < N; i++)
        if (m[i][N - 1 - i] < minVal) minVal = m[i][N - 1 - i];  // Побочная диагональ: i + j = N - 1
    return minVal;
}

// Нахождение максимального значения на побочной диагонали
float findMaxSecondaryDiagonal(float m[N][N]) {
    float maxVal = m[0][N - 1];
    for (int i = 0; i < N; i++)
        if (m[i][N - 1 - i] > maxVal) maxVal = m[i][N - 1 - i];
    return maxVal;
}

// Вычисление суммы всех элементов матрицы
float findSum(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += m[i][j];
    return sum;
}

// Вычисление среднего арифметического элементов матрицы
float findAvg(float m[N][N]) {
    return findSum(m) / (N * N);  // Сумма / количество элементов
}

// Нахождение элемента, наиболее близкого к среднему значению
float findClosestToAvg(float m[N][N], float avg) {
    float closest = m[0][0];
    float minDiff = fabs(m[0][0] - avg);  // Начальная минимальная разница

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = fabs(m[i][j] - avg);  // Модуль разницы
            if (diff < minDiff) {
                minDiff = diff;
                closest = m[i][j];
            }
        }
    }
    return closest;
}

int main() {
    float matrix[N][N];
    fillMatrix(matrix);  // Заполнение матрицы случайными значениями

    cout << "Matrix:" << endl;
    printMatrix(matrix);  // Вывод матрицы

    float avg = findAvg(matrix);  // Вычисление среднего значения

    // Вывод различных характеристик матрицы:
    cout << "Minimum value: " << findMin(matrix) << endl;
    cout << "Maximum value: " << findMax(matrix) << endl;
    cout << "Minimum main diagonal: " << findMinDiagonal(matrix) << endl;
    cout << "Maximum main diagonal: " << findMaxDiagonal(matrix) << endl;
    cout << "Minimum secondary diagonal: " << findMinSecondaryDiagonal(matrix) << endl;
    cout << "Maximum secondary diagonal: " << findMaxSecondaryDiagonal(matrix) << endl;
    cout << "Average value: " << avg << endl;
    cout << "Element closest to average: " << findClosestToAvg(matrix, avg) << endl;

    return 0;
}