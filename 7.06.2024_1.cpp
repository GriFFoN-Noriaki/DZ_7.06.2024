#include <iostream>
#include <vector>
using namespace std;

void addColumn(vector<vector<int>>& matrix, const vector<int>& newCol, int position) 
{
    setlocale(LC_ALL, "Rus");

    // Проверяем, допустима ли позиция
    if (position < 0 || position > matrix[0].size()) {
        cerr << "Недопустимая позиция.\n";
        return;
    }

    // Добавляем новый столбец
    for (size_t i = 0; i < matrix.size(); i++) {
        matrix[i].insert(matrix[i].begin() + position, newCol[i]);
    }
}

int main() 
{
    setlocale(LC_ALL, "Rus");

    int ch1, ch2, ch3;
    int position;

    cout << "Введите первое число: ";
    cin >> ch1;

    cout << "Введите второе число: ";
    cin >> ch2;

    cout << "Введите третье число: ";
    cin >> ch3;

    cout << "Введите позицию: ";
    cin >> position;

    vector<vector<int>> matrix = 
    {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> newCol = { ch1, ch2, ch3 };

    addColumn(matrix, newCol, position);

    // Выводим обновлённый массив
    for (const auto& row : matrix) {
        for (int elem : row) {
            cout << elem << " ";
        }
        cout << endl;
    }

    return 0;
}
