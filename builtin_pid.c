#include <stdio.h> 
#include <unistd.h>

// Muestra el process id del shell
// No lleva parámetros

int builtin_pid (int argc, char ** argv){

    pid_t pid = getpid();
    pid_t ppid = getppid();
    fprintf(stderr,"pid: %d, ppid: %d\n",pid, ppid);
    return 0;
}