#include <stdio.h>

#define ARRAY_SIZE 10 // размер массива

// Функция для чтения массива
int input_array(int *arr) {
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("Введите %d число:",i+1);
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
    printf("\033[33mЦифры по возрастанию: ");
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("%d", arr[i]);
        if (i < ARRAY_SIZE - 1) {
            printf(", ");
        }
    }
    printf("\n\n");
}

int main() {
    int arr[ARRAY_SIZE];

    system("clear");

    // Чтение массива
    if (!input_array(arr)) {
        printf("\n\033[31mОшибка. Допустимы только цифровые значения!\n\n");
        return 1; // Возврат ошибки
    }

    // Сортировка массива
    bubble_sort(arr);

    // Вывод отсортированного массива
    print_array(arr);

    return 0;
}
