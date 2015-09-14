// File: fork5.cpp
// Author: lxw
// Date: 2015-09-14
// getpid(): get the pid of the current process.
// fork()返回值: 若成功调用一次则返回两个值，子进程返回0，父进程返回子进程ID；否则，出错返回-1

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int i = 0;
int main(){
	fork();
	fork() && fork() || fork();
	fork();
	printf("%d\n", i++);
    return 0;
}
/*
20个0
输出结果为20个0
注意是20个0，没有其他值
*/
