#include <stdio.h> 
#include <unistd.h>

int builtin_gid (){
    gid_t git = getgid();
    fprintf(stderr,"El grupo principal es: %d\n", git);

    return 0;
}