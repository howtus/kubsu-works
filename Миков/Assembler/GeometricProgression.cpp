#include <iostream>

using namespace std;

int main() {
  setlocale(0, "rus");
  int n, first, step;
  cout << "Введите количество членов последовательности: ";
  cin >> n;
  n -= 1;
  cout << "Введите первый член последовательности: ";
  cin >> first;
  cout << "Введите шаг: ";
  cin >> step;
  _asm {
    MOV EAX, first;
    MOV EBX, 1;
    MOV ECX, 1;
    A:
      MOV EBX, step;
    MUL EBX;
    INC ECX;
    CMP ECX, n;
    JNG A;
    MOV first, EAX;
  }
  cout << n + 1 << " член последовательности: " << first << endl;
  system("pause");
  return 0;
}
