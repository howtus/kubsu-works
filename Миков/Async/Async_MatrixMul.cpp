#include <iostream>
#include <thread>
#include <future>

using namespace std;

// A[N x M] x B[M x N] = C[N x N]
const int N = 3;
const int M = 4;
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
void MatrixThread(int thread) {
    for (int i = thread - 1; i < N; i+=12) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void MatrixMul() {
    auto f1 = async(launch::async, MatrixThread, 1);
    auto f2 = async(launch::async, MatrixThread, 2);
    auto f3 = async(launch::async, MatrixThread, 3);
    auto f4 = async(launch::async, MatrixThread, 4);
    auto f5 = async(launch::async, MatrixThread, 5);
    auto f6 = async(launch::async, MatrixThread, 6);
    auto f7 = async(launch::async, MatrixThread, 7);
    auto f8 = async(launch::async, MatrixThread, 8);
    auto f9 = async(launch::async, MatrixThread, 9);
    auto f10 = async(launch::async, MatrixThread, 10);
    auto f11 = async(launch::async, MatrixThread, 11);
    auto f12 = async(launch::async, MatrixThread, 12);
}

// Вывод в консоль
void MatrixPrint() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    MatrixRand();
    MatrixMul();
    MatrixPrint();
    return 0;
}

