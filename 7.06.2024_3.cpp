#include <iostream>
#include <vector>

using namespace std;

// Функция для печати матрицы
void printMatrix(const vector<vector<int>>& matrix) 
{
    for (const auto& row : matrix) 
    {
        for (int val : row) 
        {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Функция для циклического сдвига строк и/или столбцов
void shiftMatrix(vector<vector<int>>& matrix, int shifts, char direction) 
{
    int M = matrix.size();
    int N = matrix[0].size();

    // Сдвиг строк
    if (direction == 'H') 
    {
        shifts = shifts % M; // Сдвиг в пределах количества строк
        vector<vector<int>> temp(M, vector<int>(N));

        for (int i = 0; i < M; ++i) 
        {
            temp[(i + shifts) % M] = matrix[i];
        }
        matrix = temp;
    }
    // Сдвиг столбцов
    else if (direction == 'V') 
    {
        shifts = shifts % N; // Сдвиг в пределах количества столбцов
        vector<vector<int>> temp(M, vector<int>(N));

        for (int j = 0; j < N; ++j) 
        {
            for (int i = 0; i < M; ++i) 
            {
                temp[i][(j + shifts) % N] = matrix[i][j];
            }
        }
        matrix = temp;
    }
}

int main() 
{
    setlocale(LC_ALL, "Rus");

    // Пример заполнения и сдвига матрицы
    int M = 3, N = 4;
    vector<vector<int>> matrix = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12} };

    cout << "Исходная матрица:" << endl;
    printMatrix(matrix);

    shiftMatrix(matrix, 1, 'H'); // Сдвиг строк вправо на 1

    cout << "Матрица после сдвига:" << endl;
    printMatrix(matrix);

    return 0;
}