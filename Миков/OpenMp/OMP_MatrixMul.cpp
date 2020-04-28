#include <iostream>
#include <thread>

using namespace std;

// A[N x M] x B[M x N] = C[N x N]
const int N = 100; // 3
const int M = 200; // 4
int A[N][M];
// 2 2 2 2
// 2 2 2 2
// 2 2 2 2
int B[M][N];
// 3 3 3
// 3 3 3
// 3 3 3
// 3 3 3
int C[N][N];
// 24 24 24
// 24 24 24
// 24 24 24

// Заполнение матриц
void MatrixRand() {
//#pragma omp parallel for shared(A, B, C)
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            A[i][j] = 2;
            B[j][i] = 3;
//            A[i][j] = rand() % 10;
//            B[j][i] = rand() % 10;
        }
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            C[i][j] = 0;
}

// Потоки
void MatrixMul() {
#pragma omp parallel for shared(A, B, C)
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            for (int k = 0; k < M; ++k)
            {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

// Вывод в консоль
void MatrixPrint()
{
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    auto begin = std::chrono::steady_clock::now();

    // Три прохода для большей достоверности
    for (int l = 0; l < 3; ++l) {
        MatrixRand();
        MatrixMul();
        MatrixPrint();
    }

    auto end = std::chrono::steady_clock::now();

    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time: " << elapsed_ms.count() << " ms\n";

    return 0;
}

