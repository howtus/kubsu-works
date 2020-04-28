#include <iostream>
#include <vector>
#include <thread>

using namespace std;

const int n = 100;  // Длина вектора
vector<int> a;      // Вектор а
vector<int> b;      // Вектор b
int scalar = 0;     // Результат скалярного умножения a на b

// Функция заполнения векторов случайными числами
void VectorRand() {
    for(int i = 0; i < n; ++i) {
        a[i] = rand() % 15 + 10;
        b[i] = rand() % 15 + 10;
    }
}

// Первый поток, сложение от 1 до 50 координаты вектора
void T1() {
    for (int i = 0; i < n / 2; ++i) {
        scalar += a[i] * b[i];
    }
}

// Второй поток, сложение от 50 до 100 координаты вектора
void T2() {
    for (int i = n / 2; i < n; ++i) {
        scalar += a[i] * b[i];
    }
}

// Вывод векторов в консоль
void PrintVector() {
    cout << "\n\nВектор a = ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ", ";
    }
    cout << "\n\nВектор b = ";
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ", ";
    }
}

int main() {
    // Резервируем место в векторах для дальнейшего заполнения
    a.reserve(n);
    b.reserve(n);
    // Запоняем вектора случайными числами
    VectorRand();
    // Выводим вектора в консоль
    PrintVector();
    // Создаем потоки
    thread th1(T1);
    thread th2(T2);
    // Запускаем потоки
    th1.join();
    th2.join();
    // Выводим ответ в консоль
    cout << "\n\nОтвет: " << scalar << "\n\n";
    return 0;
}
