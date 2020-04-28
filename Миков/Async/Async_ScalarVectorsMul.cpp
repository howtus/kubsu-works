#include <iostream>
#include <vector>
#include <thread>
#include <future>

using namespace std;

const int n = 144;
vector<int> a, b;

// Функция заполнения векторов случайными числами
void VectorRand() {
    for(int i = 0; i < n; ++i) {
        a[i] = rand() % 15 + 10;
        b[i] = rand() % 15 + 10;
    }
}

// Вывод векторов в консоль
void VectorPrint() {
    cout << "\n\nВектор a = ";
    for (int i = 0; i < n; ++i) {
        cout << a[i] << ", ";
    }
    cout << "\n\nВектор b = ";
    for (int i = 0; i < n; ++i) {
        cout << b[i] << ", ";
    }
}

// Функция подсчета для отдельного потока
int VectorThread(int thread) {
    int sum = 0;
    for (int i = thread - 1; i < n; i+=12) {
        sum += a[i] * b[i];
    }
    return sum;
}

// Функция асинхронного подсчета скалярного произведения двух векторов
int VectorScalarMul() {
   auto f1 = async(launch::async, VectorThread, 1);
   auto f2 = async(launch::async, VectorThread, 2);
   auto f3 = async(launch::async, VectorThread, 3);
   auto f4 = async(launch::async, VectorThread, 4);
   auto f5 = async(launch::async, VectorThread, 5);
   auto f6 = async(launch::async, VectorThread, 6);
   auto f7 = async(launch::async, VectorThread, 7);
   auto f8 = async(launch::async, VectorThread, 8);
   auto f9 = async(launch::async, VectorThread, 9);
   auto f10 = async(launch::async, VectorThread, 10);
   auto f11 = async(launch::async, VectorThread, 11);
   auto f12 = async(launch::async, VectorThread, 12);
   return f1.get() + f2.get() + f3.get() + f4.get() + f5.get()
   + f6.get()  + f7.get() + f8.get() + f9.get() + f10.get() + f11.get() + f12.get();
}

int main() {
    // Резервируем место в векторах для дальнейшего заполнения
    a.reserve(n);
    b.reserve(n);
    // Запоняем вектора случайными числами
    VectorRand();
    // Выводим вектора в консоль
    VectorPrint();
    // Запускаем вычисления и сохраняем ответ в переменную
    int result = VectorScalarMul();
    // Выводим ответ в консоль
    cout << "\n\nОтвет: " << result << "\n\n";
    return 0;
}
