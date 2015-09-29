// File: orphan.cpp
// Author: lxw
// Date: 2015-09-29

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

int main(){
    pid_t pid;
    //创建一个进程
    pid = fork();
    //创建失败
    if (pid < 0){
        perror("fork error:");
        exit(1);
    }
    //子进程
    if (pid == 0){
        printf("I am the child process.\n");
        //输出进程ID和父进程ID
        printf("pid: %d\tppid:%d\n",getpid(),getppid());
        printf("I will sleep five seconds.\n");
        //睡眠5s，保证父进程先退出
        sleep(5);
        printf("pid: %d\tppid:%d\n",getpid(),getppid());
        printf("child process exited.\n");
    }
    //父进程
    else{
        printf("I am father process.\n");
        //父进程睡眠1s，保证子进程输出进程id
        sleep(1);
        printf("father process exited.\n");
    }
    return 0;
}

/*
lxw zombieOrphan$ ./a.out 
I am father process.
I am the child process.
pid: 3086	ppid:3085
I will sleep five seconds.
father process exited.
pid: 3086	ppid:2203
child process exited.

//Verification:
lxw proc$ cd 2203/
lxw 2203$ ls -l exe 
lrwxrwxrwx 1 lxw lxw 0 Sep 29 22:53 exe -> /sbin/init*
*/