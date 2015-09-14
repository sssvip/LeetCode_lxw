// File: fork6.cpp
// Author: lxw
// Date: 2015-09-14
// getpid(): get the pid of the current process.
// fork()返回值: 若成功调用一次则返回两个值，子进程返回0，父进程返回子进程ID；否则，出错返回-1

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    fork();
    fork();
    fork();
    printf("hello\n");
    return 0;
}

/*
hello
hello
hello
hello
hello
hello
hello
hello
*/
