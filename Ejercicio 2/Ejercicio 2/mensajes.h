#ifndef MENSAJES_H_INCLUDED
#define MENSAJES_H_INCLUDED

struct
{
    char tipoMensaje[5];
    char numeroDeTarjeta[30];
    char monto[30];
    char codigoDeSeguridad[4];
}typedef eRequest_message;

struct
{
    char tipoMensaje[4];
    char codigoDeRespuesta[2];
}typedef eResponse_message;

#endif // MENSAJES_H_INCLUDED

eRequest_message* CrearRequestMessage(char mensaje[], char numeroDeTarjeta[], char monto[], char codigoDeSeguridad[]);
int GetRequestMessage(eRequest_message* rqm, char data[]);

eResponse_message* CrearResponseMessage(char* mensaje, char* codigoDeRespuesta);
int MostrarResponseMessage(eResponse_message* rpm);