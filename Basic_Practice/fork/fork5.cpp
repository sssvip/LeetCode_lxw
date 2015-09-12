// File: fork2.cpp
// Author: lxw
// Date: 2015-08-12

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

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
