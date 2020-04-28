#include <iostream>
#include <thread>

using namespace std;

const int n = 24; // Размерность матриц
int a[n][n];
int b[n][n];
int c[n][n];

// Заполнение матриц A и B
// Обнуление матрицы C = A + B
void nums() {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            a[i][j] = 3;
            b[i][j] = 2;
            c[i][j] = 0;
        }
    }
}

// ======== 12 ПОТОКОВ ДЛЯ СЛОЖЕНИЯ ========
// Каждый поток складывает все столбцы каждой 12-й строчки

void t1() {
    for (int i = 0; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t2() {
    for (int i = 1; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t3() {
    for (int i = 2; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t4() {
    for (int i = 3; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t5() {
    for (int i = 4; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t6() {
    for (int i = 5; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t7() {
    for (int i = 6; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t8() {
    for (int i = 7; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t9() {
    for (int i = 8; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t10() {
    for (int i = 9; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t11() {
    for (int i = 10; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

void t12() {
    for (int i = 11; i < n; i+=12) {
        for (int j = 0; j < n; ++j) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
}

// Вывод матрицы в консоль
void print() {
    cout << "\n\n\n";
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    // Заполняем и обнуляем матрицы
    nums();
    // Создаем потоки
    thread th1(t1);
    thread th2(t2);
    thread th3(t3);
    thread th4(t4);
    thread th5(t5);
    thread th6(t6);
    thread th7(t7);
    thread th8(t8);
    thread th9(t9);
    thread th10(t10);
    thread th11(t11);
    thread th12(t12);
    // Запускаем потоки
    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();
    th9.join();
    th10.join();
    th11.join();
    th12.join();
    // Выводим матрицу в консоль
    print();
    return 0;
}
