###References:</br>
[valgrind 的使用简介](http://blog.csdn.net/sduliulun/article/details/7732906)</br>

###使用方法:</br>
```
lxw@11:42:25:num095$ valgrind --tool=memcheck --leak-check=full --log-file=./demo.txt ./a.out
```

###内存分配</br>
常见的内存分配方式分三种：静态存储，栈上分配，堆上分配。</br>
1. 全局变量属于静态存储，它们是在编译时就被分配了存储空间;</br>
2. 函数内的局部变量属于栈上分配</br>
3. 最灵活的内存使用方式当属堆上分配，也叫做内存动态分配了。</br>
常用的内存动态分配函数包括：malloc, alloc, realloc, new等，动态释放函数包括free, delete。</br>

###内存泄露</br>
Memcheck将内存泄露分为两种，一种是可能的内存泄露（Possibly lost），另外一种是确定的内存泄露（Definitely lost）。</br>
Possibly lost 是指仍然存在某个指针能够访问某块内存，但该指针指向的已经不是该内存首地址。</br>
Definitely lost 是指已经不能够访问这块内存。而Definitely lost又分为两种：直接的（direct）和间接的（indirect）。</br>
直接和间接的区别就是，直接是没有任何指针指向该内存，间接是指指向该内存的指针都位于内存泄露处。</br>