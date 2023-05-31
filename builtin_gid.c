#include <stdio.h> 
#include <unistd.h>
#include <string.h>
#include <grp.h>

int builtin_gid (){
    gid_t git = getgid();
    gid_t git_group[100];
    int number = getgroups(git, git_group);

    struct group * grp = getgrgid(git);

    for(int i=0;git_group[i]!=0;i++){
        struct group * grp = getgrgid(git_group[i]);
        if(grp != NULL){
            fprintf(stderr,"%d(%s)\n", git_group[i], grp->gr_name);
        }
    }
    fprintf(stderr, "\n");
    return 0;
}