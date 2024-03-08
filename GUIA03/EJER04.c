// Escriba un programa que muestre la variable de entorno HOME de un proceso

#include <stdio.h>
#include <stdlib.h>
int main()
{
    //Variables
    char *home = NULL;
    //Indicar proposito del programa
    puts("\n==== ESTE PROGRAMA MUESTRA EL CONTENIDO DE LA VARIABLE HOME DEL SISTEMA ====\n");
    //Procesar y mostrar
    home = getenv("HOME");
    if (home == NULL)
    printf("HOME no se encuentra definida\n");
    else
    printf("El valor de HOME es %s\n", home);
    //Salir
    return 0;
}