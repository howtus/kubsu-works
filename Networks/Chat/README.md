# Клиент-Сервер чат

Выполнил **Дмитрий Мешари** совместно с **Николаем Золоцевским**. Группа 25/2.

## Ссылки на `.txt` файлы

* [Сервер чата](https://github.com/howtus/kubsu-works/blob/master/Networks/Chat/Chat-Server.txt)
* [Клиент чата](https://github.com/howtus/kubsu-works/blob/master/Networks/Chat/Chat-Client.txt)

## Исходный код

Ниже представлен исходный код программ.

### Сервер чата

Исходный код программы сервера чата по компьютерным сетям. Сделано через сокеты, потоки для отправки и принятия сообщений. Добавлена обработка никнеймов, вывода количества пользователей онлайн. Чат широковещательный, т.е. сообщения отправляются сразу всем клиентам и соответственно видят их сразу все клиенты. Также пишется кто отправил.

```
// Server chat
#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>

#pragma warning(disable: 4996)

SOCKET Connections[100];
int Counter = 0;

void ClientHandler(int index)
{
	char message[256];
	char name[256];
	recv(Connections[index], name, sizeof(name), NULL);
	std::cout << name << " в сети.\n";
	for (int i = 0; i < Counter; i++)
	{
		if (i == index) continue;
		send(Connections[i], "присоединился к чату!", sizeof(message), NULL);
		send(Connections[i], name, sizeof(name), NULL);
	}
	while (true)
	{
		recv(Connections[index], message, sizeof(message), NULL);
		recv(Connections[index], name, sizeof(name), NULL);

		if (strcmp(message, "Exit") == 0)
		{
			strcat(name, " покинул чат");
			for (int i = 0; i < Counter; i++)
			{
				if (i == index) continue;
				send(Connections[i], ("Ожидайте!"), sizeof(message), NULL);
				send(Connections[i], name, sizeof(name), NULL);
			}
			closesocket(Connections[index]);
			break;
		}
		for (int i = 0; i < Counter; i++)
		{
			if (i == index) continue;
			send(Connections[i], message, sizeof(message), NULL);
			send(Connections[i], name, sizeof(name), NULL);
		}
	}
}

int main(int argc, char* argv[])
{
	//WSAStartup
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		std::cout << "Ошибка" << std::endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("10.4.0.24");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	SOCKET sListen = socket(AF_INET, SOCK_STREAM, NULL);
	bind(sListen, (SOCKADDR*)&addr, sizeof(addr));
	listen(sListen, SOMAXCONN);

	char name[256];

	SOCKET newConnection;
	for (int i = 0; i < 100; i++)
	{
		newConnection = accept(sListen, (SOCKADDR*)&addr, &sizeofaddr);
		if (newConnection == 0)
			std::cout << "Ошибка #2\n";
		else
		{
			std::cout << "Новое подключение!\n";
			Connections[i] = newConnection;
			Counter++;
			std::cout << "Онлайн " << Counter << " пользователей.\n";
			CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, (LPVOID)(i), NULL, NULL);
		}
	}
	system("pause");
	return 0;
}
```

### Клиент чата

Исходный код программы клиента чата по компьютерным сетям. Сделано через сокеты, потоки для отправки и принятия сообщений. Добавлены никнеймы. Чат широковещательный, т.е. сообщения отправляются сразу всем клиентам и соответственно видят их сразу все клиенты. Также пишется кто отправил.

```
// Client chat
#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
using namespace std;

#pragma warning(disable: 4996)

SOCKET Connection;

void ClientHandler()
{
	char message[256];
	char name[256];
	while (true)
	{
		recv(Connection, message, sizeof(message), NULL);
		recv(Connection, name, sizeof(name), NULL);
		cout << name << ": " << message << endl << endl;
	}
}

int main(int argc, char* argv[])
{
	//WSAStartup
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	WSAData wsaData;
	WORD DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0)
	{
		cout << "Ошибка" << endl;
		exit(1);
	}

	SOCKADDR_IN addr;
	int sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr("10.4.0.24");
	addr.sin_port = htons(1111);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		cout << "Ошибка: не удалось подключиться к серверу.\n";
		system("pause");
		return 1;
	}
	cout << "Вы успешно подключены!\n";
	cout << "Введите своё имя: ";
	char send_name[256];
	cin.getline(send_name, sizeof(send_name));

	send(Connection, send_name, sizeof(send_name), NULL);

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientHandler, NULL, NULL, NULL);

	char message1[256];


	while (true)
	{
		cin.getline(message1, sizeof(message1));
		cout << "Отправлено: " << message1 << endl;
		send(Connection, message1, sizeof(message1), NULL);
		send(Connection, send_name, sizeof(send_name), NULL);
		if (strcmp(message1, "Exit") == 0)
		{
			closesocket(Connection);
			return 0;
		}
		Sleep(10);
	}

	system("pause");
}
```