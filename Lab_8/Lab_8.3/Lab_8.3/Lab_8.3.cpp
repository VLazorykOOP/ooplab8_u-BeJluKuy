#include <iostream>

template<typename T>
class MyArray {
private:
    T* data; // Вказівник на динамічний масив
    int size; // Розмір масиву

public:
    // Конструктор за замовчуванням
    MyArray() : data(nullptr), size(0) {}

    // Параметризований конструктор
    MyArray(int size) : size(size) {
        data = new T[size];
    }

    // Конструктор копіювання
    MyArray(const MyArray& other) : size(other.size) {
        data = new T[size];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }

    // Деструктор
    ~MyArray() {
        delete[] data;
    }

    // Перевантажений оператор доступу до елемента масиву []
    T& operator[](int index) {
        return data[index];
    }

    // Перевантажений оператор присвоєння =
    MyArray& operator=(const MyArray& other) {
        if (this != &other) {
            delete[] data;
            size = other.size;
            data = new T[size];
            for (int i = 0; i < size; i++) {
                data[i] = other.data[i];
            }
        }
        return *this;
    }

    // Перевантажений оператор додавання +
    MyArray operator+(const MyArray& other) const {
        MyArray result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] + other.data[i];
        }
        return result;
    }

    // Перевантажений оператор додавання з присвоєнням +=
    MyArray& operator+=(const MyArray& other) {
        for (int i = 0; i < size; i++) {
            data[i] += other.data[i];
        }
        return *this;
    }

    // Перевантажений оператор віднімання -
    MyArray operator-(const MyArray& other) const {
        MyArray result(size);
        for (int i = 0; i < size; i++) {
            result.data[i] = data[i] - other.data[i];
        }
        return result;
    }

    // Перевантажений оператор віднімання з присвоєнням -=
    MyArray& operator-=(const MyArray& other) {
        for (int i = 0; i < size; i++) {
            data[i] -= other.data[i];
        }
        return *this;
    }
};

int main() {
    // Приклад використання класу MyArray
    MyArray<int> arr1(5);
    MyArray<int> arr2(5);
    MyArray<int> arr3;

    for (int i = 0; i < 5; i++) {
        arr1[i] = i;
        arr2[i] = i * 2;
    }

    arr3 = arr1 + arr2;
    std::cout << "arr3 = arr1 + arr2: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    arr3 += arr1;
    std::cout << "arr3 += arr1: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    arr3 -= arr2;
    std::cout << "arr3 -= arr2: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr3[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
