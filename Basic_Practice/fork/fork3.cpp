// File: fork2.cpp
// Author: lxw
// Date: 2015-08-12

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(){
    for(int i= 0; i< 4; i++){
        int pid= fork();
        printf("-\n");
    }
    return 0;
}


/*
30 '-' in total.
*/