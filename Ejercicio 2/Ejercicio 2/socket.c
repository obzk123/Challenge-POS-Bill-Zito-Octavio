#include <stdio.h>
#include "socket.h"

#include <windows.h>
#include <winsock.h>

#pragma comment(lib, "Ws2_32.lib")

int socketCreate()
{
    int sock;
    WSADATA WsaData;
    WORD wVersionRequerida = MAKEWORD(2, 2);
    WSAStartup(wVersionRequerida, &WsaData);
    sock = socket(AF_INET, SOCK_STREAM, 0);
    return sock;
}

int socketConnect(int handle, const char* ip, unsigned short port)
{
    struct sockaddr_in direccion;
    direccion.sin_family = AF_INET;
    direccion.sin_port = htons(port);
    direccion.sin_addr.s_addr = inet_addr(ip);
    connect(handle, (struct sockaddr*)&direccion, sizeof(direccion));
    return 0;
}

int socketRecive(int handle, unsigned char* data, int maxTimeout)
{
    struct timeval timeout;
    timeout.tv_sec = maxTimeout;
    timeout.tv_usec = 0;

    if (setsockopt(handle, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0)
    {
        return -1;
    }
    return recv(handle, data, sizeof(data), 0);
    //0 no hay mensajes
    //-1 error
    
}

int socketSend(int handle, const unsigned char* data)
{
    return send(handle, data, 130, 0);
    
}

int socketClose(int handle)
{
    return closesocket(handle);
    
}
