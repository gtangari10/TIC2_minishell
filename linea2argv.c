#include <string.h>
#include <stdio.h> 
#include "minish.h"

int linea2argv (char *linea, int argc, char **argv);

int linea2argv (char *linea, int argc, char **argv){
    char delimiters[] = " \t";
    int arg_numbers = 0;

    char *token = strtok(linea, delimiters);
    while (token != NULL && arg_numbers<MAXWORDS) {
        argv[arg_numbers++] = token;
        token = strtok(NULL, delimiters);
    }
    return arg_numbers;
}