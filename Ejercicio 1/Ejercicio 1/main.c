#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int ObtenerNumero(char* numero);
void ObtenerNombreArchivo(char nombreArchivo[]);
void GuardarNumerosEnArchivo(FILE* archivo, char** numeros, int length);
int VerificarString(char* palabra);

int main()
{
    char** numeros = NULL;
    char* auxNumero = NULL;
    char** aux = NULL;
    char numero[10];
    int contador = 0;
    FILE* archivo = NULL;
    char nombreArchivo[50] = {""};

    for (int i = 0; ; i++)
    {
        ObtenerNumero(numero);
        if (strcmp(numero, "0") != 0)
        {
            aux = (char**)realloc(numeros, sizeof(numeros) + (i * sizeof(char*)));
            if (aux != NULL)
            {
                numeros = aux;
                auxNumero = (char*)malloc(10 * sizeof(char));
                if (auxNumero != NULL)
                {
                    numeros[i] = auxNumero;
                    strcpy_s(numeros[i], sizeof(numero), numero);
                    contador++;
                }
                else
                {
                    printf("Ocurrio un error");
                    system("PAUSE");
                    exit(1);
                }
            }
            else
            {
                printf("Ocurrio un error");
                system("PAUSE");
                exit(1);
            }
        }
        else
        {
            break;
        }
    }

    printf("Escribe el nombre del archivo para guardar: ");
    fflush(stdin);
    fscanf_s(stdin, "%s", nombreArchivo, sizeof(nombreArchivo));
    strcat_s(nombreArchivo, 50, ".txt");
    fopen_s(&archivo, nombreArchivo, "w+");
    if (archivo == NULL)
    {
        printf("Error al crear el archivo\n");
        system("PAUSE");
        exit(1);
    }
    else
    {
        GuardarNumerosEnArchivo(archivo, numeros, contador);
        printf("Archivo guardado con exito\n");
    }

    free(numeros);
    fclose(archivo);

    system("pause");
    return 0;
}

int ObtenerNumero(char* numero)
{
    printf("Ingrese un numero (0 para finalizar): ");
    fflush(stdin);
    fscanf_s(stdin, "%s", numero, sizeof(numero));
    while (VerificarString(numero) == -1)
    {
        printf("Error. Ingrese un numero (0 para finalizar): ");
        fflush(stdin);
        fscanf_s(stdin, "%s", numero, sizeof(numero));
    }
    return 0;
}

int VerificarString(char* palabra)
{
    for (int i = 0; i < strlen(palabra); i++)
    {
        if (i == 0 && palabra[0] == '-')
        {
            continue;
        }

        if (!isdigit(palabra[i]))
        {
            return -1;
        }
    }
    return 0;
}

void GuardarNumerosEnArchivo(FILE* archivo, char** numeros, int length)
{
    int numero;
    for (int i = 0; i < length; i++)
    {
        numero = atoi(numeros[i]);
        fprintf(archivo, "%10.10d\n", numero);
    }
}
