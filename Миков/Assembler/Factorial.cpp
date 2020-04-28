#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "rus");
	int n, n1;
	cout << "Введите n: ";
	cin >> n;
	_asm
	{
		MOV EAX, 1;
		MOV EBX, 1;
	A:
		MUL EBX;
		INC EBX;
		CMP EBX, n;
		JNG A;
		MOV n1, EAX;
	}
	cout << "Факториал равен: " << n1 << endl;
	system("pause");
    return 0;
}
