#include <iostream>
using namespace std;
#define N 20

int temp[N];

void Merge(int array[], int left, int m, int right) {
    int i1 = left;
    int i2 = m + 1;
    for (int j = 0; j < right - left + 1; ++j) {
        if ((i2 > right) || (i1 <= m) && (array[i1] < array [i2])) {
            temp[j] = array[i1];
            ++i1;
        } else {
            temp[j] = array[i2];
            ++i2;
        }
    }
    for (int j = 0; j < right - left + 1; ++j) {
        array[left + j] = temp[j];
    }
}

void MergeSort(int array[], int left, int right) {
    if (left == right) return;
    int middle = (left + right) / 2;
#pragma omp parallel sections
    {
#pragma omp section
        MergeSort(array, left, middle);
#pragma omp section
        MergeSort(array, middle + 1, right);
    }
    Merge(array, left, middle, right);
}

void Print(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

int main()
{
    int array[N];
    for (int i = 0; i < N; ++i) {
        array[i] = rand() % 100;
    }
    Print(array, N);
    MergeSort(array, 0, N - 1);
    Print(array, N);

    return 0;
}

