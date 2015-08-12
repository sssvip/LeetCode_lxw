// File: fork2.cpp
// Author: lxw
// Date: 2015-08-12

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
    for(int i= 0; i< 3; i++){
        int pid= fork();
        if(pid== 0){
            printf("son\n");
        }
        else{
            printf("father\n");
        }
    }
    return 0;
}

/*
7 "father" and 7 "son" in total.
*/