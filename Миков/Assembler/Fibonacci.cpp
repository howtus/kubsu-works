#include <iostream>

using namespace std;
int main() {
  setlocale(0, "rus");
  int num;
  cout << "Какой член последовательности вывести: ";
  short int index;
  cin >> index;
  _asm {
    MOV CX, index
    MOV EAX, 1
    MOV EBX, 1
    MOV EDX, 1
    L: CMP CX, 2
    JLE A
    MOV EDX, EAX
    ADD EAX, EBX
    MOV EBX, EDX
    DEC CX
    JMP L
    A: MOV num, EAX
  }
  cout << "Ответ: " << num << endl << endl;
  system("pause");
  return 0;
}
