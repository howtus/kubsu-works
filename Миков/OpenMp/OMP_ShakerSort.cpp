#include <iostream>
#include <chrono>
using namespace std;

void FillArray(int array[], int N)
{
    cout << "array[";
    for (int i = 0; i < N; ++i)
    {
        array[i] = rand() % 100;
        cout << array[i];
        if (i < N - 1) cout << ", ";
    }
    cout << "]";
    cout << endl;
}

void Print(int array[], int N)
{
    cout << "array[";
    for (int i = 0; i < N; ++i)
    {
        cout << array[i];
        if (i < N - 1) cout << ", ";
    }
    cout << "]";
    cout << endl;
}

void ShakerSortOMP(int *array, int N) {
    auto t1 = chrono::high_resolution_clock::now();
    int left = 0, right = N - 1;
    while (left <= right) {
#pragma omp parallel shared(array, N)
        {
#pragma omp for
            for (int i = right; i >= left; --i) {
                if (array[i - 1] > array[i]) {
                    swap(array[i - 1], array[i]);
                }
            }

        }
        ++left;
#pragma omp parallel shared(array, N)
        {
#pragma omp for
            for (int i = left; i <= right; ++i) {
                if (array[i - 1] > array[i]) {
                    swap(array[i - 1], array[i]);
                }
            }

        }
        --right;
    }
    auto t2 = chrono::high_resolution_clock::now();
    std::chrono::duration<double, milli> elapsed = t2 - t1;
    cout << "Время работы многопоточно: " << elapsed.count() << " мс\n";
}

void ShakerSort(int array[], int N) {
    auto t1 = chrono::high_resolution_clock::now();
    int left = 0, right = N - 1;
    while (left <= right) {
        for (int i = right; i >= left; i--) {
            if (array[i - 1] > array[i]) {
                swap(array[i - 1], array[i]);
            }
        }
        left++;
        for (int i = left; i <= right; i++) {
            if (array[i - 1] > array[i]) {
                swap(array[i - 1], array[i]);
            }
        }
        right--;
    }
    auto t2 = chrono::high_resolution_clock::now();
    std::chrono::duration<double,milli> elapsed = t2 - t1;
    cout << "Время работы однопоточно: " << elapsed.count() << " мс\n";
}

int main()
{
    const int N = 10000;
    int array[N];

    cout << "\nМногопоточно:\n";
    FillArray(array, N);
    ShakerSortOMP(array, N);
    Print(array, N);

    cout << "\n\nОднопоточно:\n";
    FillArray(array, N);
    ShakerSort(array, N);
    Print(array, N);

    return 0;
}
