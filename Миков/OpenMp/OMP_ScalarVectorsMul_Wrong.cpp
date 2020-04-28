#include <iostream>
#include <vector>
#include <thread>
#include <future>

using namespace std;

const int n = 100;
int a[n], b[n];

// Функция заполнения векторов случайными числами
void VectorRand() {
    for(int i = 0; i < n; ++i) {
        a[i] = 2;
        b[i] = 2;
    }
}

// Вывод векторов в консоль
void VectorPrint()
{
    cout << "\n\nВектор a = ";
    for (int i = 0; i < n; ++i)
        cout << a[i] << ", ";
    cout << "\n\nВектор b = ";
    for (int i = 0; i < n; ++i)
        cout << b[i] << ", ";
}

// Функция подсчета для отдельного потока
int VectorMulParallel()
{
    unsigned long int sum = 0;
#pragma omp parallel
    {
#pragma omp for
        for (int i = 0; i < n; ++i)
        {
            sum += a[i] * b[i];
        }
    }
    return sum;
}

// Функция подсчета для отдельного потока
int VectorMul()
{
    unsigned long int sum = 0;
    for (int i = 0; i < n; ++i)
        sum += a[i] * b[i];
    return sum;
}

int main()
{
    // Запоняем вектора случайными числами
    VectorRand();

    // Выводим вектора в консоль
    VectorPrint();

    // Выводим ответ в консоль
    auto begin1 = std::chrono::steady_clock::now();

    cout << "\n\nОтвет многопоточно: " << VectorMulParallel() << endl;

    auto end1 = std::chrono::steady_clock::now();
    auto elapsed_ms1 = std::chrono::duration_cast<std::chrono::milliseconds>(end1 - begin1);

    cout << "Время многопоточно: " << elapsed_ms1.count() << " ms\n";


    auto begin2 = std::chrono::steady_clock::now();

    cout << "\nОтвет однопоточно: " << VectorMul() << endl;

    auto end2 = std::chrono::steady_clock::now();
    auto elapsed_ms2 = std::chrono::duration_cast<std::chrono::milliseconds>(end2 - begin2);

    cout << "Время однопоточно: " << elapsed_ms2.count() << " ms\n";

    return 0;
}
