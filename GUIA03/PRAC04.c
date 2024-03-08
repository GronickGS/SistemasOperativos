// Escriba un programa que cree un proceso hijo que determine la raíz cuadrada de un
// numero ingresado por el usuario. El proceso padre debe mostrar el resultado calculado
// (investigue la llamada vfork()).

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <math.h>
#include <sys/wait.h>

int main() {
    int num;

    printf("Ingrese un número para calcular su raíz cuadrada: ");
    scanf("%d", &num);

    pid_t pid = vfork(); // Creamos un nuevo proceso hijo usando vfork()

    if (pid < 0) {
        // Error al crear el proceso hijo
        perror("Error al crear el proceso hijo");
        return 1;
    } else if (pid == 0) {
        // Este código se ejecuta en el proceso hijo
        double square_root = sqrt((double)num);
        printf("En el proceso hijo (PID=%d): La raíz cuadrada de %d es %f\n", getpid(), num, square_root);
        _exit(0); // Salimos del proceso hijo
    } else {
        // Este código se ejecuta en el proceso padre
        printf("Esperando a que el proceso hijo termine...\n");
        // El proceso padre espera a que el proceso hijo termine
        wait(NULL);
        printf("Proceso hijo ha terminado. Volviendo al proceso padre (PID=%d).\n", getpid());
    }

    return 0;
}
