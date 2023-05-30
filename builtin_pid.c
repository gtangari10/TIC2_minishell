#include <stdio.h> 
#include <unistd.h>

int builtin_pid (){
    // no lleva parámetros, muestra el process id del shell
    pid_t pid = getpid();
    fprintf(stderr,"El id del proceso es: %d\n",pid);
    return 0;
}