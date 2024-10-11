// editing

#include <stdio.h>

#define ARRAY_SIZE 10

// Функция для чтения массива
int read_array(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        if (scanf("%d", &arr[i]) != 1) {
            return 0; // Ошибка ввода
        }
    }
    return 1; // Успешное чтение
}

// Функция для сортировки массива (алгоритм пузырька)
void bubble_sort(int *arr) {
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        for (int j = 0; j < ARRAY_SIZE - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Меняем местами элементы
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Функция для вывода массива
void print_array(const int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d", arr[i]);
        if (i < ARRAY_SIZE - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int arr[ARRAY_SIZE];

    // Чтение массива
    if (!read_array(arr)) {
        printf("n/a\n");
        return 1; // Возврат ошибки
    }

    // Сортировка массива
    bubble_sort(arr);

    // Вывод отсортированного массива
    print_array(arr);

    return 0;
}
