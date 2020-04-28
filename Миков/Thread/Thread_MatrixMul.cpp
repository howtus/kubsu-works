#include <iostream>
#include <thread>

using namespace std;

// A[N x M] x B[M x N] = C[N x N]
const int N = 6;
const int M = 8;
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
void MatrixRandom() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            // A[i][j] = 2;
            // B[j][i] = 3;
            A[i][j] = rand() % 10;
            B[j][i] = rand() % 10;
        }
    }
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            C[i][j] = 0;
}

// Потоки
void T1() {
    for (int i = 0; i < N; i+=4) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void T2() {
    for (int i = 1; i < N; i+=4) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void T3() {
    for (int i = 2; i < N; i+=4) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

void T4() {
    for (int i = 3; i < N; i+=4) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < M; ++k) {
                C[i][j] += A[i][k]*B[k][j];
            }
        }
    }
}

// Вывод в консоль
void print() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    MatrixRandom();
    thread thr1(T1);
    thread thr2(T2);
    thread thr3(T3);
    thread thr4(T4);
    thr1.join();
    thr2.join();
    thr3.join();
    thr4.join();
    print();
    return 0;
}

