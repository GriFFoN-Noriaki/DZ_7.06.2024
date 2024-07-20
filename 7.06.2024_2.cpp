#include <iostream>
#include <vector>

// Функция для удаления столбца из двумерного массива
void removeColumn(std::vector<std::vector<int>>& array, int colToRemove) {
    // Проверяем корректность номера столбца
    if (colToRemove < 0 || colToRemove >= array[0].size()) {
        std::cout << "Неверный номер столбца!" << std::endl;
        return;
    }

    // Проходим по каждой строке и удаляем указанный столбец
    for (auto& row : array) {
        row.erase(row.begin() + colToRemove);
    }
}

// Функция для демонстрации работы
int main() {
    // Создаем пример двумерного массива
    std::vector<std::vector<int>> array = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Удаляем второй столбец (индекс 1)
    removeColumn(array, 1);

    // Выводим результат
    for (const auto& row : array) {
        for (int val : row) {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}