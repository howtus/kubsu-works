#include <iostream>
using namespace std;

const int n = 64;
bool graph[n][n];

// Минимум двух чисел
int min(int a, int b)
{
    return (a > b ? b : a);
}

// Вывод матрицы смежности в консоль
void print() {
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

// Обнуление матрицы смежности
void reset() {
    for (int i = 0; i < 64; i++)
    {
        for (int j = 0; j < 64; j++)
        {
            graph[i][j] = false;
        }
    }
}

// Поиск диаметра графа
int diameter()
{
    int** edge = new int* [n];

    for (int i = 0; i < n; i++)
        edge[i] = new int[n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            edge[i][j] = graph[i][j];
            if (!edge[i][j])
                edge[i][j] = 10000;
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (i != j)
                    edge[i][j] = min(edge[i][j], edge[i][k] + edge[k][j]);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edge[i][j] == 10000)
                edge[i][j] = 0;
        }
    }

    int max = edge[0][1];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (edge[i][j] > max)
                max = edge[i][j];
        }
    }

    return max;
    delete[] edge;
}

// ================ MAIN ================
int main()
{
    setlocale(0, "rus");
    // Обнуляем граф
    reset();
    // Связываем по горизонтали
    // Ставим в уголки 1
    graph[0][63] = true;
    graph[63][0] = true;
    // Ставим выше и ниже главной диагонали 1
    for (int i = 0; i < 63; i++)
    {
        graph[i][i + 1] = true;
        graph[i + 1][i] = true;
        
    }
    // Связываем по вертикали
    for (int i = 0; i < 64; i++)
    {
        // Связываем все вершины до 55-й
        if (i + 8 < 64)
        {
            graph[i][i + 8] = true;
            graph[i + 8][i] = true;
        }
        // После 55-й
        else
        {
            graph[i][i - 56] = true;
            graph[i - 56][i] = true;
        }
    }
    // Все проделанное выше делаем симметрично
    // Выводим граф в консоль
    print();
    cout << "\n\nДиаметр графа: " << diameter() << "\n\n\n";
    system("pause");
    return 0;
}
