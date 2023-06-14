#include <stdio.h> 
#include <stdlib.h>
#include "minish.h"

extern struct deq * new_deq;


// muestra los N – por defecto 10 – comandos anteriores.
// deben almacenarse para ejecuciones posteriores del minish, en el archivo $HOME/.minish_history

int builtin_history (int argc, char ** argv){
    if(argc == 1){
        deq_print_ordered(new_deq, 10);
        return 0;
    }
    char * word = argv[1];
    int number = atoi(word);

    if(number){
        deq_print_ordered(new_deq, number);
        return 0;
    }

    fprintf(stderr, "history: mal argumento %s - help history\n", argv[1]);
    return 1;
}