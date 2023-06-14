#include <string.h>
#include <stdio.h> 

int linea2argv (char *linea, int argc, char **argv);

// El objetivo de esta función es armar argv para luego invocar a otras funciones. 
// Retorna la cantidad N de palabras encontradas y argv[N] deberá ser NULL.
// Se descartan las palabras “sobrantes” (palabra es un texto entre espacios o tabuladores)
// Si la línea está “vacía” o contiene solo espacios, retorna 0.

int linea2argv (char *linea, int argc, char **argv){
    char delimiters[] = " \t\n";
    int arg_numbers = 0;

    char *token = strtok(linea, delimiters);
    while (arg_numbers < argc && token != NULL) {
        argv[arg_numbers++] = token;
        token = strtok(NULL, delimiters);
    }
    argv[arg_numbers] = NULL;

    return arg_numbers;
}