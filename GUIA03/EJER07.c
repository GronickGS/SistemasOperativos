// Escriba un programa que cree N procesos hijo.

#include <stdio.h>
#include <sys/types.h>

int main()
{
    //Variables
    pid_t forkReturn;
    int i;
    int n=5;
    //Indicar proposito del programa
    puts("\n==== ESTE PROGRAMA CREA N PROCESOS HIJO Y CADA UNO MUESTRA SU IDENTIFICADOR Y EL DE SU PADRE ====\n");
    //Procesar
    for (i = 0; i < n; i++)
    {
    forkReturn = fork();
    if (forkReturn == 0)
    break; //Si es el hijo, salir del bucle
    }
    //Mostrar resultados
    printf("%d; El padre del proceso %d es %d \n", i, getpid(),
    getppid());
    //Salir
    return 0;
}