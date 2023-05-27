#include <iostream>

template<typename T>
int sequentialSearch(const T* arr, int size, const T& key) {
    int lastIndex = -1; // Індекс останнього знайденого елемента, початково -1

    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            lastIndex = i; // Оновлюємо індекс останнього знайденого елемента
        }
    }

    return lastIndex;
}

int main() {
    int intArray[] = { 1, 2, 3, 4, 5 };
    int intKey = 3;
    int intIndex = sequentialSearch(intArray, 5, intKey);
    std::cout << "Index of last occurrence (int): " << intIndex << std::endl;

    double doubleArray[] = { 1.5, 2.5, 3.5, 4.5, 5.5 };
    double doubleKey = 2.5;
    int doubleIndex = sequentialSearch(doubleArray, 5, doubleKey);
    std::cout << "Index of last occurrence (double): " << doubleIndex << std::endl;

    const char* strArray[] = { "apple", "banana", "apple", "orange" };
    const char* strKey = "apple";
    int strIndex = sequentialSearch(strArray, 4, strKey);
    std::cout << "Index of last occurrence (char*): " << strIndex << std::endl;

    return 0;
}
