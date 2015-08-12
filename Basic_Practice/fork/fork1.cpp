// File: fork1.cpp
// Author: lxw
// Date: 2015-08-12

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
int main(){
    pid_t pid;
    printf("\n[%d]not fork pid=%d\n",getpid(),pid);
    pid=fork();
    printf("\n[%d]forked pid=%d\n",getpid(),pid);
    if(pid<0){
        printf("error in fork!\n");
        //getchar();
        exit(1);
    }
    else if(pid==0)
    	printf("\n[%d]in child process,p_id=%d\n",getpid(),getpid());
    else{
        printf("\n[%d]in parent process,my pid=%d\n",getpid(),pid);
        printf("\n[%d]in parent process,my getpid=%d\n",getpid(),getpid());
    }
    return 0;
}

/*
[3691]not fork pid=-1217191936

[3691]forked pid=3692

[3691]in parent process,my pid=3692

[3691]in parent process,my getpid=3691
lxw Basic_Practice$ 
[3692]forked pid=0          //NOTE HERE, pid = 0

[3692]in child process,p_id=3692
*/
