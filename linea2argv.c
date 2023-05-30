#include <string.h>
#include <stdio.h> 

int linea2argv (char *linea, int argc, char **argv);

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