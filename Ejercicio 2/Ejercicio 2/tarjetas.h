#ifndef TARJETAS_H_INCLUDED
#define TARJETAS_H_INCLUDED

typedef struct
{
    char rangeLow[8 + 1];
    char rangeHigh[8 + 1];
    unsigned char len;
    int id;
} range_t;

typedef struct
{
    char label[12 + 1];
    int id;
} card_t;

#endif // TARJETAS_H_INCLUDED


int ValidarTarjeta(char* numeroDeTarjeta);
int ObtenerTarjeta(int id, char* label);

