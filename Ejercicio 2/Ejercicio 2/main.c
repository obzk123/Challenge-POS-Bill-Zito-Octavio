#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "socket.h"
#include "tarjetas.h"
#include "mensajes.h"



int main()
{
    char numeroDeTarjeta[30] = {""};
    char label[20] = {""};
    char monto[30] = {""};
    char codigoDeSeguridad[4] = {""};
    int idTarjeta;
    eRequest_message* rqm = NULL;

    printf("Ingrese el monto: ");
    fflush(stdin);
    fscanf_s(stdin, "%s", monto, sizeof(monto));

    printf("Ingrese el numero de tarjeta: ");
    fflush(stdin);
    fscanf_s(stdin, "%s", numeroDeTarjeta, sizeof(numeroDeTarjeta));
    while (strlen(numeroDeTarjeta) < 13 || strlen(numeroDeTarjeta) > 20)
    {
        printf("Error. Ingrese el numero de tarjeta: ");
        fflush(stdin);
        fscanf_s(stdin, "%s", numeroDeTarjeta, sizeof(numeroDeTarjeta));
    }

    idTarjeta = ValidarTarjeta(numeroDeTarjeta);
    if (idTarjeta == -1 || ObtenerTarjeta(idTarjeta, label) == -1)
    {
        printf("TARJETA NO SOPORTADA\n");
        system("pause");
        exit(1);
    }

    printf("%s\n", label);
    printf("Ingrese el codigo de seguridad: ");
    fflush(stdin);
    fscanf_s(stdin, "%s", codigoDeSeguridad, sizeof(codigoDeSeguridad));

    int handleSocket = socketCreate();
    if (handleSocket == -1)
    {
        printf("ERROR AL CREAR EL SOCKET");
        system("PAUSE");
        exit(1);
    }

    short port = 5534;
    socketConnect(handleSocket, "127.0.0.1", port);

    char data[120] = {""};
    rqm = CrearRequestMessage("0200", numeroDeTarjeta, monto, codigoDeSeguridad);
    GetRequestMessage(rqm, data);
    printf("%s", data);
    if (socketSend(handleSocket, data) <= 0)
    {
        printf("ERROR DE COMUNICACION");
        system("PAUSE");
        exit(1);
    }
    else if (socketRecive(handleSocket, data, 5) <= 0)
    {
        printf("ERROR DE RECIBIR");
        system("PAUSE");
        exit(1);
    }

    if (strcmp(data, "00") == 0)
    {
        printf("APROBADA");
    }else
    { 
        printf("RECHAZADA");
    }
    
    system("PAUSE");
    return 0;
}