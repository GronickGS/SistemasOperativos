// Escriba un programa que muestre su nombre e identificador de proceso

#include <stdio.h>
#include <sys/types.h> //tipos de datos v.g. pid_t
int main (int argc, char *argv[])
{
    //Variables
    char *nombreDePrograma = argv[0];
    //Lee el nombre del programa de la linea de comandos
    pid_t processId;
    //Indicar proposito del programa
    puts("\n==== ESTE PROGRAMA MUESTRA SU NOMBRE Y SU IDENTIFICADOR DE PROCESO ====\n");
    //Procesar
    processId = getpid();
    //Mostrar resultados
    printf("Mi nombre de programa es: %14s\n", nombreDePrograma+2);
    //Sumamos 2 para omitir los caracteres "./"
    printf("Mi identificador de proceso es: %6d\n\n", processId);
    //salir
    return 0;
}