#include <iostream>

template<typename T>
int partition(T* arr, int low, int high) {
    T pivot = arr[high]; // Вибираємо останній елемент як опорний
    int i = low - 1; // Індекс меншого елемента

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]); // Міняємо місцями елементи
        }
    }

    std::swap(arr[i + 1], arr[high]); // Переміщуємо опорний елемент на його правильне місце
    return (i + 1); // Повертаємо індекс опорного елемента
}

template<typename T>
void quickSort(T* arr, int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Отримуємо індекс опорного елемента

        quickSort(arr, low, pivotIndex - 1); // Сортуємо ліву частину масиву
        quickSort(arr, pivotIndex + 1, high); // Сортуємо праву частину масиву
    }
}

int main() {
    int intArray[] = { 5, 2, 8, 1, 4 };
    int intSize = sizeof(intArray) / sizeof(int);
    quickSort(intArray, 0, intSize - 1);

    std::cout << "Sorted array (int): ";
    for (int i = 0; i < intSize; i++) {
        std::cout << intArray[i] << " ";
    }
    std::cout << std::endl;

    double doubleArray[] = { 3.5, 1.2, 4.7, 2.9, 1.8 };
    int doubleSize = sizeof(doubleArray) / sizeof(double);
    quickSort(doubleArray, 0, doubleSize - 1);

    std::cout << "Sorted array (double): ";
    for (int i = 0; i < doubleSize; i++) {
        std::cout << doubleArray[i] << " ";
    }
    std::cout << std::endl;

    const char* strArray[] = { "apple", "banana", "cat", "dog", "elephant" };
    int strSize = sizeof(strArray) / sizeof(const char*);
    quickSort(strArray, 0, strSize - 1);

    std::cout << "Sorted array (char*): ";
    for (int i = 0; i < strSize; i++) {
        std::cout << strArray[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
