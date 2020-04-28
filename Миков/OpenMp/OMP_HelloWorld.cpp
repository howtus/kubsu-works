#include <iostream>
#include <omp.h>
using namespace std;

int main()
{
    setlocale(0, "");

    #pragma omp parallel
    {
        cout << "Привет, Мир!" << endl;
    }

    return 0;
}
