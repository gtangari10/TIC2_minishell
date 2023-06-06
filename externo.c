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
        execvp(argv[0], argv);
        exit(1);
    }
    /*
    else{
        fprintf(stderr, "minish: execvp error \n: No such file or directory\n%s", argv[0]);
    }
    */

    int status;
    waitpid(pid, &status, 0);
    if (status == 256){
        fprintf(stderr, "minish: execvp error \n: No such file or directory\n%s", argv[0]);
        return 2;
    }
    return status;
}