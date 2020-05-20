#include <iostream>
#include <iomanip>
#include <random>
#include <chrono>

using namespace std;

int main() {
    setlocale(0, "");
    // =================================
    int n;
    cout << "Введите размерность \n";
    cin >> n;

    double** A = new double* [n];
    for (int i = 0; i < n; i++)
        A[i] = new double[n + 1];

    double** B = new double* [n];
    for (int i = 0; i < n; i++)
        B[i] = new double[n + 1];

    double* y = new double[n];

    int i, j, k;
    float buf;

    mt19937 gen(time(0));

    cout << "Матрица и вектор правой части\n";

    for (i = 0; i < n; ++i) {
        for (j = 0; j < n + 1; ++j) {
            B[i][j] = A[i][j] = 1 + gen() % 99;
            cout << setw(4) << A[i][j];
        }
        cout << endl;
    }

    auto t1 = chrono::high_resolution_clock::now();

    //метод Гаусса
    for (i = 0; i < n - 1; ++i)
    // ==========
#pragma omp parallel
    {
#pragma omp for
        for (j = i + 1; j < n; ++j)
        {
            buf = A[i][i] / A[j][i];
#pragma omp parallel shared(buf)
            {
#pragma omp for
                for (k = 0; k <= n; ++k)
                    A[j][k] = A[j][k] * buf - A[i][k];
            }
        }
    }
    // ==========
    y[n - 1] = A[n - 1][n] / A[n - 1][n - 1];

    for (i = n - 2; i >= 0; --i) {
        buf = 0;
        for (j = i + 1; j < n; ++j)
            buf += A[i][j] * y[j];
        y[i] = (A[i][n] - buf) / A[i][i];
    }

    auto t2 = chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = t2 - t1;
    cout << "\nВремя работы многопоточно: " << elapsed.count() << " мс\n";

    cout << "Решение\n";
    for (i = 0; i < n; ++i)
        cout << setw(10) << y[i] << " | ";

    return 0;
}
