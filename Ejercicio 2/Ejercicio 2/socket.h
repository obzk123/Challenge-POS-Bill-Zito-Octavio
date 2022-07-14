#ifndef SOCKET_H_INCLUDED
#define SOCKET_H_INCLUDED


#endif // SOCKET_H_INCLUDED

/**
* Crea un socket
* @return handle del socket o -1 en caso de error
*/
int socketCreate();

/**
* Conectar el socket a un host
* @param handle handle del socket a utilizar
* @param ip direccion ip del host a conectarse
* @param port puerto del host a conectarse
* @return 0 en caso de exito o -1 en caso de error
*/
int socketConnect(int handle, const char* ip, unsigned short port);

/**
* Leer datos del socket. La función bloquea hasta leer datos o transcurrir maxTimeout
milisegundos
* @param handle handle del socket a utilizar
* @param data puntero donde se guardarán los datos leidos
* @param maxTimeout tiempo máximo de espera en milisegundos
* @return cantidad de bytes leidos o -1 en caso de error
*/
int socketRecive(int handle, unsigned char* data, int maxTimeout);

/**
* Escribir datos en un socket
* @param handle handle del socket a utilizar
* @param data puntero desde donde se leerán los datos a escribir
* @return cantidad de bytes escritos o -1 en caso de error
*/
int socketSend(int handle, const unsigned char* data);

/**
* Cierra el socket y libera recursos
* @param handle handle del socket a utilizar
* @return 0 en caso de exito o -1 en caso de error
*/
int socketClose(int handle);

