###References:</br> 
[GDB和Valgrind 的使用方法](http://www.tudou.com/programs/view/_k4KxRcbBKo/)</br>

###使用方法:</br>
```
lxw@14:51:18:~$ g++ -g test.cpp   #option "-g" is essential.
lxw@14:51:31:~$ gdb ./a.out 	#或者先gdb,然后file导入./a.out
GNU gdb (Ubuntu 7.7.1-0ubuntu5~14.04.2) 7.7.1
...
Reading symbols from ./a.out...done.
(gdb)
```

###常用命令:</br>
l	list. l 3,5	#打印程序指定行数</br>
p	print. print i	#打印变量值</br>
n	next	#逐行(不进入函数内)</br>
s	step	#逐行(进入函数内)</br>
r	run</br>
b	break 10/break funcName</br>
q	quit</br>
</br>
多进程(fork):</br>
```
set follow-fork-mode parent
set follow-fork-mode child
```
</br>
多线程:</br>
```
info threads
thread 1	#thread ThreadID
```

###出现错误后可以到/var/log/syslog中查看错误</br>
```
lxw@15:19:13:gdb$ vim /var/log/syslog
lxw@15:19:22:gdb$ tail -n 2 /var/log/syslog
Jul 29 15:11:05 lxw-Aspire-4736Z kernel: [ 5799.157298] a.out[5840]: segfault at 8048801 ip 080486e6 sp bfb926a0 error 7 in a.out[8048000+1000]
Jul 29 15:17:01 lxw-Aspire-4736Z CRON[6000]: (root) CMD (   cd / && run-parts --report /etc/cron.hourly)
```
对于上面的error 7中的7，是二进制的111, 每一位分别代表u/s, r/w, present.</br>
111代表: 用户u, 读写rw, 存在p.</br>
000代表: 内核s, 只读r, 不存在.</br>
可以通过例子crash.cpp理解, 当尝试修改"hello"常量的内容时出现`Segmentation fault (core dumped)`错误. "用户 写 存在"</br>

###从源代码（source.cpp）生成可执行文件（a.out）一共分为四个阶段：</br>
1. 预编译阶段</br>
 使用gcc的-E选项可以查看预编译结果：</br>
 ```
 g++ -E source.cpp
 ```
 </br>处理结果不会保存在文件中，而是在标准输出中。</br>
2. 汇编阶段</br>
 使用gcc的-S选项可以查看汇编结果：</br>
 ```
 g++ -S source.cpp
 ```
 </br>会在当前目录下产生一个source.s的文件</br>
3. 编译阶段</br>
 使用gcc的-c选项可以生成目标文件：</br>
 ```
 g++ -c source.s
 ```
 </br>也可以从源代码直接生成目标文件：</br>
 ```
 g++ -c source.cpp
 ```
 </br>gcc会通过**_扩展名_**自动判断处理的是汇编代码还是C++代码。</br>
 到此，（狭义上的）编译器已经完成它的全部工作。</br>
4. 链接阶段</br>
 此时已经没有编译器的事情了。链接工作交由链接器来处理。链接器会将多个目标文件链接成可执行文件。</br>
 我们可以通过gcc来进行链接，但是实际上，gcc还是调用ld命令来完成链接工作的。</br>
 ```
 g++ xx1.o xx2.o
 ```

详情请参见 [编译过程](https://github.com/lexdene/gcc_five_minute/blob/master/09_%E7%BC%96%E8%AF%91%E8%BF%87%E7%A8%8B%2FREADME.md) 很不错</br>
