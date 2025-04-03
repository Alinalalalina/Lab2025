#include <iostream>
#include <iomanip>    // ��� ���������������� ������ (setw, setprecision)
#include <cstdlib>     // ��� ������� rand()
#include <climits>     // ��� �������� ������������� �����
#include <cmath>       // ��� �������������� ������� (fabs)

#define N 5            // ������ ���������� �������

using namespace std;

// ������� ���������� ������� ���������� ���������� �� 0.0 �� 9.9
void fillMatrix(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = rand() % 100 / 10.0;  // rand()%100 ���� 0-99, ������� �� 10.0 ���� 0.0-9.9
        }
    }
}

// ������� ������ ������� � ���������������
void printMatrix(float m[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            // setw(8) - ������ ���� ������, setprecision(5) - �������� 5 ������
            cout << setw(8) << setprecision(5) << m[i][j] << " ";
        }
        cout << endl;
    }
}

// ���������� ������������ �������� � �������
float findMin(float m[N][N]) {
    float minVal = m[0][0];  // ��������� �������������
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] < minVal) minVal = m[i][j];
    return minVal;
}

// ���������� ������������� �������� � �������
float findMax(float m[N][N]) {
    float maxVal = m[0][0];  // ��������� �������������
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (m[i][j] > maxVal) maxVal = m[i][j];
    return maxVal;
}

// ���������� ������������ �������� �� ������� ���������
float findMinDiagonal(float m[N][N]) {
    float minVal = m[0][0];
    for (int i = 0; i < N; i++)
        if (m[i][i] < minVal) minVal = m[i][i];  // ������� ���������: i == j
    return minVal;
}

// ���������� ������������� �������� �� ������� ���������
float findMaxDiagonal(float m[N][N]) {
    float maxVal = m[0][0];
    for (int i = 0; i < N; i++)
        if (m[i][i] > maxVal) maxVal = m[i][i];
    return maxVal;
}

// ���������� ������������ �������� �� �������� ���������
float findMinSecondaryDiagonal(float m[N][N]) {
    float minVal = m[0][N - 1];  // �������� � ������� �������� ��������
    for (int i = 0; i < N; i++)
        if (m[i][N - 1 - i] < minVal) minVal = m[i][N - 1 - i];  // �������� ���������: i + j = N - 1
    return minVal;
}

// ���������� ������������� �������� �� �������� ���������
float findMaxSecondaryDiagonal(float m[N][N]) {
    float maxVal = m[0][N - 1];
    for (int i = 0; i < N; i++)
        if (m[i][N - 1 - i] > maxVal) maxVal = m[i][N - 1 - i];
    return maxVal;
}

// ���������� ����� ���� ��������� �������
float findSum(float m[N][N]) {
    float sum = 0;
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            sum += m[i][j];
    return sum;
}

// ���������� �������� ��������������� ��������� �������
float findAvg(float m[N][N]) {
    return findSum(m) / (N * N);  // ����� / ���������� ���������
}

// ���������� ��������, �������� �������� � �������� ��������
float findClosestToAvg(float m[N][N], float avg) {
    float closest = m[0][0];
    float minDiff = fabs(m[0][0] - avg);  // ��������� ����������� �������

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            float diff = fabs(m[i][j] - avg);  // ������ �������
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
    fillMatrix(matrix);  // ���������� ������� ���������� ����������

    cout << "Matrix:" << endl;
    printMatrix(matrix);  // ����� �������

    float avg = findAvg(matrix);  // ���������� �������� ��������

    // ����� ��������� ������������� �������:
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