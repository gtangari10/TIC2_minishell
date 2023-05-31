#include <stdio.h> 
#include <unistd.h>

int builtin_pid (){
    // no lleva parámetros, muestra el process id del shell
    pid_t pid = getpid();
    pid_t ppid = getppid();
    fprintf(stderr,"pid: %d, ppid: %d\n",pid, ppid);
    return 0;
}