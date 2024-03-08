// Escriba un programa que permita mostrar información del usuario y el grupo de usuario que ejecuta un proceso

#include <sys/types.h>
#include <stdio.h>
int main()
{
    //Indicar proposito dle programa
    puts("\n==== ESTE PROGRAMA MUESTRA INFORMACION DEL USUARIO QUE EJECUTA EL PROCESO ====\n");
    //Mostrar resultados
    printf("Identificador de usuario : %d\n", getuid());
    printf("Identificador de usuario efectivo : %d\n", geteuid());
    printf("Identificador del grupo : %d\n", getgid());
    printf("Identificador de grupo efectivo : %d\n", geteuid());
    //Salir
    return 0;
}