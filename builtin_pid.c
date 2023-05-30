#include <stdio.h> 

int builtin_pid (int argc, char ** argv){
    // no lleva parámetros, muestra el process id del shell
    return getpid();
}

int main(int argc, char *argv){
    int pid = getpid();
    printf("%i", pid);
}