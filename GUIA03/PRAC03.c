// Escriba un programa que cree un hijo, espere su terminación y muestre la información de
// Estado de terminación del mismo.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid = fork(); // Creamos un nuevo proceso

    if (pid < 0) {
        // Error al crear el proceso hijo
        perror("Error al crear el proceso hijo");
        return 1;
    } else if (pid == 0) {
        // Este código se ejecuta en el proceso hijo
        printf("Proceso hijo (PID=%d) creado.\n", getpid());
        exit(42); // Terminamos el proceso hijo con un estado de terminación arbitrario
    } else {
        // Este código se ejecuta en el proceso padre
        printf("Proceso padre (PID=%d) esperando a que el hijo termine...\n", getpid());
        
        int status;
        pid_t child_pid = wait(&status); // Esperamos a que el proceso hijo termine y recogemos su estado
        
        if (child_pid == -1) {
            perror("Error al esperar a que el hijo termine");
            return 1;
        } else {
            if (WIFEXITED(status)) {
                printf("El proceso hijo (PID=%d) ha terminado con estado de salida: %d\n", child_pid, WEXITSTATUS(status));
            } else if (WIFSIGNALED(status)) {
                printf("El proceso hijo (PID=%d) ha sido terminado por una señal: %d\n", child_pid, WTERMSIG(status));
            }
        }
    }

    return 0;
}