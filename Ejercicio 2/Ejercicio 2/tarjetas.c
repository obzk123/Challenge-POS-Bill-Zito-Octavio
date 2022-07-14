#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tarjetas.h"


int ValidarTarjeta(char* numeroDeTarjeta)
{
    char rangoTarjeta[8];
    char buffer[4][10];
    FILE* archivo;
    errno_t err = fopen_s(&archivo, "ranges.dat", "rt");
    if (err != 0)
    {
        return -1;
    }

    for (int i = 0; i < 8; i++)
    {
        rangoTarjeta[i] = numeroDeTarjeta[i];
    }
    
    int nRangoTarjeta = atoi(rangoTarjeta);
  
    do
    {
        fscanf_s(archivo, "%[^,],%[^,],%[^,],%[^\n]\n", buffer[0], sizeof(buffer[0]), buffer[1], sizeof(buffer[1]) , buffer[2], sizeof(buffer[2]), buffer[3], sizeof(buffer[3]));
        int nRangoMinimo = atoi(buffer[0]);
        int nRangoMaximo = atoi(buffer[1]);
        int len = atoi(buffer[2]);

        if (nRangoTarjeta >= nRangoMinimo && nRangoTarjeta <= nRangoMaximo && len == strlen(numeroDeTarjeta))
        {
            int id = atoi(buffer[3]);
            fclose(archivo);
            return id;
        }
    } while (!feof(archivo));

    fclose(archivo);
    return -1;
}

int ObtenerTarjeta(int id, char* label)
{
    char buffer[2][15];
    FILE* archivo;
    errno_t err =  fopen_s(&archivo, "cards.dat", "rt");
    if (err != 0)
    {
        return -1;
    }

    do
    {
        fscanf_s(archivo, "%[^,],%[^\n]\n", buffer[0], sizeof(buffer[0]), buffer[1], sizeof(buffer[1]));
        int idArchivo = atoi(buffer[1]);
        if (idArchivo == id)
        {
            strcpy_s(label, 20, buffer[0]);
            fclose(archivo);
            return 1;
        }

    } while (!feof(archivo));

    fclose(archivo);
    return -1;
}