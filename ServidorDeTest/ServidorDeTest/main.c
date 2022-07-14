#include <stdio.h>
#include <stdlib.h>

#include <windows.h>
#include <winsock.h>

#pragma comment(lib, "Ws2_32.lib")

int main()
{
	WSADATA wsa;
	int sock;
	struct sockaddr_in server;
	WSAStartup(MAKEWORD(2, 0), &wsa);


	if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		// creamos el socket, atento en una condicion(if) la funcion devuele -1 si esta falla.
		printf("Error creando el socket, saliendo…");
		getch();
		exit(0);
	}

	server.sin_family = AF_INET; // familia socket
	server.sin_addr.s_addr = INADDR_ANY; // INADDR_ANY es lo mimo que poner local host (127.0.0.1).
	server.sin_port = htons(5534); //Puerto

	if (bind(sock, (struct sockaddr*)&server, sizeof(server)) == -1) {//Asociamos
		printf("error asociando");
		getch();
		exit(0);
	}

	printf("Esperando Clientes\n");
	listen(sock, 2); // Maximos de clientes permitidos 2

	if ((sock = accept(sock, 0, 0)) < 0) {   // Aceptamos conexion cliente
		printf("error aceptando connexion");
		exit(0);
	}

	puts("Cliente conectado");

	char buffer[120];
	if (recv(sock, buffer, sizeof(buffer), 0) == -1) { // recivimos lo que nos envia el cliente
		printf("error reciviendo");
		exit(0);
	}
	puts("Esto es lo que envio el cliente;\n");
	puts(buffer);


	send(sock, "00", 3, 0);
	getch();


	closesocket(sock);  // Cerramos socket
	system("PAUSE");
	return 0;
}