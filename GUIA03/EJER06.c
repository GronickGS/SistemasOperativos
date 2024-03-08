// Escriba un programa que cree un proceso hijo. Cada proceso debe mostrar su identificador

#include <stdio.h>
#include <sys/types.h>
extern char **environ; //Variable externa
int main()
{
    //Variables
    pid_t forkReturn;
    //Indicar proposito dle programa
    puts("\n==== ESTE PROGRAMA CREA UN PROCESO Y MUESTRA EL ID DEL PROCESO CREADO Y DEL PROCESO CREADOR ====\n");
    //Procesar
    forkReturn = fork(); //Creamos el proceso
    //Mostrar resultados
    if (forkReturn == 0) //¿Quien soy?
    {
    //Este codigo se ejecuta solo en el proceso hijo
    printf("Soy el proceso Hijo. Mi PID es %d\n", getpid());
    }
    else
    {
    //Este codigo se ejecuta solo en el proceso padre
    printf("Soy el proceso Padre. Mi PID es %d\n",getpid());
    }
    //Salir
    return 0;
}