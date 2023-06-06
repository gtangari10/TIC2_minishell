#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>



int externo (int argc, char ** argv){
    //fprintf(stderr, "Entre a externo\n");
    struct sigaction sig_old_action;
    struct sigaction sig_new_action;
    memset(&sig_new_action, 0, sizeof(sig_old_action));
    sig_new_action.sa_handler = SIG_IGN;
    sigaction(SIGINT, &sig_new_action, &sig_old_action);

    pid_t pid = fork();

    if(pid == -1){
        fprintf(stderr, "Error creando proceso hijo\n");
        return 1;
    }

    if(pid == 0){
        execvp(argv[0], argv);
        exit(1);
    }




    int status;
    waitpid(pid, &status, 0);
    
    sigaction(SIGINT, &sig_old_action, NULL);
    
    if (status == 256){
        fprintf(stderr, "minish: execvp error \n: No such file or directory\n%s", argv[0]);
        return 2;
    }
    return status;
}