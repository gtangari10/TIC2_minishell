#include <stdio.h> 
#include "minish.h"

extern struct deq * new_deq;

int builtin_history (int argc, char ** argv){
    deq_print(new_deq);
    return 0;
}