// Escriba un programa que cree un proceso hijo que calcule el cuadrado de un numero 
// ingresado por el usuario. El proceso padre debe calcular el cubo de dicho número.

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num;
    printf("Ingrese un número: ");
    scanf("%d", &num);

    pid_t pid = fork(); // Creamos un nuevo proceso

    if (pid < 0) {
        // Error al crear el proceso hijo
        perror("Error al crear el proceso hijo");
        return 1;
    } else if (pid == 0) {
        // Este código se ejecuta en el proceso hijo
        int square = num * num;
        printf("En el proceso hijo (PID=%d): El cuadrado de %d es %d\n", getpid(), num, square);
    } else {
        // Este código se ejecuta en el proceso padre
        wait(NULL); // Esperamos a que el proceso hijo termine
        int cube = num * num * num;
        printf("En el proceso padre (PID=%d): El cubo de %d es %d\n", getpid(), num, cube);
    }

    return 0;
}