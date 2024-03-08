// Escriba un programa que cree un proceso hijo el cual genere un número entero aleatorio,
// cuya primalidad sea verificada por el padre.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdbool.h>

bool es_primo(int num) {
    if (num <= 1) {
        return false;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    pid_t pid = fork(); // Creamos un nuevo proceso hijo

    if (pid < 0) {
        // Error al crear el proceso hijo
        perror("Error al crear el proceso hijo");
        return 1;
    } else if (pid == 0) {
        // Este código se ejecuta en el proceso hijo
        srand(getpid()); // Semilla aleatoria basada en el PID del proceso hijo
        int num = rand() % 100 + 1; // Generamos un número aleatorio entre 1 y 100
        printf("Proceso hijo (PID=%d) generó el número: %d\n", getpid(), num);
        exit(num); // Terminamos el proceso hijo y pasamos el número generado como estado de salida
    } else {
        // Este código se ejecuta en el proceso padre
        printf("Proceso padre (PID=%d) esperando a que el hijo termine...\n", getpid());
        int status;
        wait(&status); // Esperamos a que el proceso hijo termine y recogemos su estado

        if (WIFEXITED(status)) {
            int num_generado = WEXITSTATUS(status);
            printf("El número generado por el hijo (PID=%d) es: %d\n", pid, num_generado);

            if (es_primo(num_generado)) {
                printf("El número %d es primo.\n", num_generado);
            } else {
                printf("El número %d no es primo.\n", num_generado);
            }
        } else {
            printf("El proceso hijo no terminó correctamente.\n");
        }
    }

    return 0;
}

