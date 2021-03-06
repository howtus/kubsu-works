#include "pch.h"
#include <iostream>
#include <windows.h>
using namespace std;

void FillArray(int a[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << "array[" << i << "] = ";
		cin >> a[i];
	}
	cout << endl;
}

void out(int a[], int N)
{
	cout << "Отсортированный массив: ";
	for (int i = 0; i < N; i++) 
		cout << a[i] << " ";
	cout << endl << endl;
}

void BubbleSort(int a[], int N) {
	SYSTEMTIME st; // начало времени
	GetLocalTime(&st);
	cout << "Начало сортировки пузырьком:  " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << ":" << st.wMilliseconds << endl;
	for (int i = 0; i < N - 1; i++) {
		for (int j = 0; j < N - i - 1; j++) {
			if (a[j] > a[j + 1]) {
				swap(a[j], a[j + 1]);
			}
		}
	}
	SYSTEMTIME end;
	GetLocalTime(&end); // конец времени
	cout << "Конец сортировки пузырьком:  " << end.wHour << ":" << end.wMinute << ":" << end.wSecond << ":" << end.wMilliseconds << endl;
	cout << "Время работы: " << end.wMilliseconds - st.wMilliseconds << " мс" << endl;
}

void ChoiceSort(int a[], int N) {
	SYSTEMTIME st;
	GetLocalTime(&st);
	cout << "Начало сортировки выбором:  " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << ":" << st.wMilliseconds << endl;
	int min = 0; // для записи минимального значения
	int buf = 0; // для обмена значениями
	for (int i = 0; i < N; i++) {
		min = i;
		for (int j = i + 1; j < N; j++)
			min = (a[j] < a[min]) ? j : min;
		// меняем местами с текущим
		if (i != min) {
			swap(a[i], a[min]);
		}
	}
	SYSTEMTIME end;
	GetLocalTime(&end);
	cout << "Конец сортировки выбором:  " << end.wHour << ":" << end.wMinute << ":" << end.wSecond << ":" << end.wMilliseconds << endl;
	cout << "Время работы: " << end.wMilliseconds - st.wMilliseconds << " мс" << endl;
}

void InsertionSort(int a[], int N) {
	SYSTEMTIME st;
	GetLocalTime(&st);
	cout << "Начало сортировки вставками:  " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << ":" << st.wMilliseconds << endl;
	for (int i = 1; i < N; i++) {
		for (int j = i; j > 0 && a[j - 1] > a[j]; j--)
			swap(a[j - 1], a[j]);
	}
	SYSTEMTIME end;
	GetLocalTime(&end);
	cout << "Конец сортировки вставками:  " << end.wHour << ":" << end.wMinute << ":" << end.wSecond << ":" << end.wMilliseconds << endl;
	cout << "Время работы: " << end.wMilliseconds - st.wMilliseconds << " мс" << endl;
}

void ShakerSort(int a[], int N) {
	SYSTEMTIME st;
	GetLocalTime(&st);
	cout << "Начало сортировки шейкером:  " << st.wHour << ":" << st.wMinute << ":" << st.wSecond << ":" << st.wMilliseconds << endl;
	int left = 0, right = N - 1;
	while (left <= right) {
		for (int i = right; i >= left; i--) {
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
			}
		}
		left++;
		for (int i = left; i <= right; i++) {
			if (a[i - 1] > a[i]) {
				swap(a[i - 1], a[i]);
			}
		}
		right--;
	}
	SYSTEMTIME end;
	GetLocalTime(&end);
	cout << "Конец сортировки шейкером:  " << end.wHour << ":" << end.wMinute << ":" << end.wSecond << ":" << end.wMilliseconds << endl;
	cout << "Время работы: " << end.wMilliseconds - st.wMilliseconds << " мс" << endl;

}

int main()
{
	setlocale(0, "rus");
	int *a, *b, size;
	cout << "Введите количество элементов массива: ";
	cin >> size;
	a = new int[size];		// Выделение памяти под массив
	b = new int[size];
	FillArray(a, size);	// Заполнение массива
	b = a;

	BubbleSort(a, size);	// Сортировка пузырьком
	out(a, size);
	a = b;

	ChoiceSort(a, size);	// Сортировка выбором
	out(a, size);
	a = b;

	InsertionSort(a, size); // Сортировка вставками
	out(a, size);
	a = b;

	ShakerSort(a, size);	// Сортировка шейкером
	out(a, size);

	system("pause");
}