// Escriba un programa que cree una jerarquía de procesos como la mostrada en el gráfico adjunto

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

#define NUM_PROC 4 // Definimos el número de procesos deseado

int main() {
    int n = NUM_PROC; // Establecemos el número de procesos

    // Iteramos para crear la jerarquía de procesos
    for (int i = 1; i <= n; i++) {
        pid_t pid = fork(); // Creamos un nuevo proceso

        if (pid < 0) {
            // Error al crear el proceso hijo
            perror("Error al crear el proceso hijo");
            return 1;
        } else if (pid == 0) {
            // Este código se ejecuta en el proceso hijo
            printf("Proceso %d (PID=%d) creado por el padre (PID=%d)\n", i, getpid(), getppid());
            exit(0); // Salir del proceso hijo
        }
    }

    // El proceso padre espera a que todos los procesos hijos terminen
    for (int i = 1; i <= n; i++) {
        wait(NULL);
    }

    return 0;
}
