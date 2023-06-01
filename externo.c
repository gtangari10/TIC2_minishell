#include <stdio.h> 
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int externo (int argc, char ** argv){
    //fprintf(stderr, "Entre a externo\n");

    pid_t pid = fork();

    if(pid == -1){
        fprintf(stderr, "Error creando proceso hijo\n");
        return 1;
    }

    if(pid == 0){
        execvp(argv[0],argv);
        exit(1);
    }

    //Aca el padre tiene que esperar al hijo para matar a los 2

    return 0;
}