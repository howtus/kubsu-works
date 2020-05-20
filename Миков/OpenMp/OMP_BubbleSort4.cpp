#include <iostream>
using namespace std;

void BubbleSort4(int array[], int n) {
    int i, j;
#pragma omp parallel default(none) shared(array, n) private(i)
    for (i = 0; i < n; ++i) {
        if (i % 2 == 0) {
#pragma omp for
            for (j = 0; j < n - 1; j += 2) {
                if (array[j] > array[j + 1])
                    swap(array[j], array[j + 1]);
            }
        } else {
#pragma omp for
            for (j = 1; j < n - 1; j += 2) {
                if (array[j] > array[j + 1])
                    swap(array[j], array[j + 1]);
            }
        }
    }
}

void Print(int array[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << array[i] << " ";
    }
    cout << endl << endl;
}

int main()
{
    int array[10] = {34, 432, 43, 43, 75, 21, 8, 423, 75, 234};
    BubbleSort4(array, 10);
    Print(array, 10);

    return 0;
}
