// File: fork4.cpp
// Author: lxw
// Date: 2015-09-05
// getpid(): get the pid of the current process.
// fork()返回值: 若成功调用一次则返回两个值，子进程返回0，父进程返回子进程ID；否则，出错返回-1

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
	for(int i = 0; i < 9; ++i){
		if(fork()){
			printf("%d\n", i);
            fflush(stdout);
		}
		else{
			printf("%d\n", ++i);
            fflush(stdout);
		}
		wait(NULL);
		wait(NULL);
	}    
    return 0;
}
/*
for(int i = 0; i < 3; ++i)
lxw fork$ ./a.out 
0
1
2
3
1
2
2
3
*/
/*
for(int i = 0; i < 9; ++i)
lxw fork$ ./a.out 
0
1
2
3
4
5
6
7
8
9
7
8
8
9
5
6
7
8
8
9
6
7
8
9
7
8
8
9
.
.
.
*/
