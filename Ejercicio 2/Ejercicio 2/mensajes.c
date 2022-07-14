#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mensajes.h"


eRequest_message* CrearRequestMessage(char mensaje[], char numeroDeTarjeta[], char monto[], char codigoDeSeguridad[])
{
    eRequest_message* rqm = (eRequest_message*)malloc(sizeof(eRequest_message));
    if (rqm != NULL)
    {
        strcpy_s(rqm->tipoMensaje, 5, mensaje);
        strcpy_s(rqm->numeroDeTarjeta, 30, numeroDeTarjeta);
        strcpy_s(rqm->monto, 30, monto);
        strcpy_s(rqm->codigoDeSeguridad, 4, codigoDeSeguridad);
        return rqm;
    }
    return NULL;
}



eResponse_message* CrearResponseMessage(char* mensaje, char* codigoDeRespuesta)
{
    eResponse_message* rpm = (eResponse_message*)malloc(sizeof(eResponse_message));
    if (rpm != NULL)
    {
        strcpy_s(rpm->tipoMensaje, 4, mensaje);
        strcpy_s(rpm->codigoDeRespuesta, 2, codigoDeRespuesta);
        return rpm;
    }
    return NULL;
}


int GetRequestMessage(eRequest_message* rqm, char data[])
{
    if (rqm != NULL)
    {
        strcat_s(data, 30, rqm->tipoMensaje);
        strcat_s(data, 30, rqm->numeroDeTarjeta);
        strcat_s(data, 30, rqm->monto);
        strcat_s(data, 30, rqm->codigoDeSeguridad);
        return 1;
    }
    return 0;
}


int MostrarResponseMessage(eResponse_message* rpm)
{
    if (rpm != NULL)
    {
        printf("Tipo de mensaje Codigo de respuesta\n");
        printf("%s %s\n", rpm->tipoMensaje, rpm->codigoDeRespuesta);
        return 1;
    }
    return 0;
}
