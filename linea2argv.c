#include <string.h>
#include <stdio.h> 

int linea2argv (char *linea, int argc, char **argv);

int main() {
    char prueba[] = "Hola,       Mundo. Esto es una prueba";
    int argc = 0;
    char *argv[10];

    linea2argv(prueba, argc, argv);
    printf("%i", argc);
    for (int i = 0; i < 10; i++) {
        
        printf("%s\n", argv[i]);

    }
    return 0;
}

int linea2argv (char *linea, int argc, char **argv){
    char delimiters[] = " \t";

    char *token = strtok(linea, delimiters);
    while (token != NULL) {
        argv[argc++] = token;
        token = strtok(NULL, delimiters);
    }
    printf("%i", argc);
    return 0;
}
<<<<<<< HEAD
// ▪ recibe una línea (texto con un \n final) y hace apuntar argv[0] a la primera
// palabra, argv[1] a la segunda, etc.
// ▪ argc+1 es el tamaño con el cual está definido argv en el invocador a esta
// función.
// ▪ Retorna la cantidad N de palabras encontradas y argv[N] deberá ser
// NULL. Se sobreentiende que N debe ser inferior a argc. Pueden
// descartarse las palabras “sobrantes”.
// ▪ Una palabra es un texto entre espacios o tabuladores.
// ▪ El objetivo de esta función es armar argv para invocar a las funciones
// anteriores.
// ▪ Debe funcionar perfectamente aún si la línea está “vacía” o contiene solo
// espacios. Retorna 0 en este caso.
// ▪ Los strings apuntados por argv[0], argv[1], etc. se mallocarán. Es
// responsabilidad de quien invoca a linea2argv, de hacer los free
// correspondientes.
=======
 */
>>>>>>> cc17e3cfdae58ad1059d2a5728ca8b1b3d35fd7a
