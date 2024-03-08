# I.TEMA: CREACION DE PROCESOS

# II.OBJETIVO DE LA PRACTICA
Al finalizar la presente práctica, el estudiante:
1. Comprende los mecanismos de gestión de procesos en Linux
2. Desarrolla aplicaciones para la gestión de procesos en Linux

# III. TRABAJO PREPARATORIO.
Para un trabajo con mejores resultados, es imprescindible que el estudiante:
1. Tenga conocimientos de programación en C en el sistema operativo Linux
2. Conozca la teoría de gestión de procesos en los sistemas operativos.

# IV. MATERIALES.
Para el desarrollo de la presente práctica es necesario contar con:
1. Computador con arquitectura x86.
2. Sistema operativo Linux instalado en el computador o en su defecto un liveCD o
liveUSB que incluya el compilador GCC y un editor de texto pre instalado.

# V. MARCO TEORICO
## SERVICIOS POSIX PARA LA GESTION DE PROCESOS
## IDENTIFICACIÓN DE PROCESOS
POSIX identifica cada proceso por medio de un entero único llamado identificador de
proceso de tipo pid_t.

A continuación se indica las funciones para la identificación de procesos:

### Obtener el identificador de proceso
pid_t getpid(void);
### Obtener el identificar del proceso padre
pid_t getppid(void);

## EL ENTORNO DE UN PROCESO
El entorno de un proceso viene definido por una lista de variables que se pasan al mismo en
el momento de comenzar su ejecución. Estas variables se denominan variables de entorno, y
son accesibles a un proceso a través de la variable externa environ, declarada de la
siguiente manera:
extern char **environ;

### Obtener el valor de una variable de entorno
char *getenv(const char *name);

### Definir el entorno de un proceso
char *setenv(char **env);

## GESTIÓN DE PROCESOS
La creación de procesos se realiza utilizando el servicio fork(). El sistema operativo trata
este servicio realizando una clonación del proceso que lo solicite, el mismo que se convierte
en el proceso padre del nuevo proceso el cual es, a su vez, el proceso hijo.
El prototipo de esta función es el siguiente:
pid_t fork();

### Ejecutar un programa
El servicio exec tiene por objeto cambiar el programa que está ejecutando un proceso. En
POSIX existe una familia de funciones exec, cuyos prototipos se muestran a continuación:
int execl(char *path, char *arg, ...);
int execv(char *path, char *argv[]);
int execle(char *path, char *arg, ...);
int execve(char *path, char *argv[], char *envp[]);
int execlp(char *file, const char *erg, ...);
int execvp(char *file, char *argv[]);

### Terminar la ejecución de un proceso
void exit(int status);
Esta función es equivalente a la sentencia
return (valor);

### Esperar por la finalización de un proceso hijo
El proceso padre se queda bloqueado hasta que termina un proceso hijo. Existen dos formas
de invocar este servicio:
pid_t wait(int *status);
pid_t waitpid(pid_t pid, int *status, int options);

### Suspender la ejecución de un hijo
Suspende al proceso durante un número determinado de segundos. Su prototipo es:
int sleep(unsigned int seconds);