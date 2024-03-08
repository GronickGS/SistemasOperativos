// Escriba un programa que muestre todas las variables de entorno de un proceso

#include <stdio.h>
extern char **environ; //Variable externa
int main()
{
    //Variables
    char** var;
    //Indicar proposito del programa
    puts("\n==== ESTE PROGRAMA MUESTRA INFORMACION DEL ENTORNO DE UN PROCESO ====\n");
    //Procesar y mostrar resultados
    for(var = environ; *var != NULL; ++var)
    printf("%s\n", *var);
    //Salir
    return 0;
}