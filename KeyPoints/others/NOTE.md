@1:netstat
netstat - Print network connections, routing tables, interface statistics,
masquerade connections, and multicast memberships

netstat常用选项：
-a (all)显示所有选项，默认不显示LISTEN相关
-t (tcp)仅显示tcp相关选项
-u (udp)仅显示udp相关选项
-n 拒绝显示别名，能显示数字的全部转化成数字。
-l 仅列出有在 Listen (监听) 的服務状态

-p 显示建立相关链接的程序名
-r 显示路由信息，路由表
-e 显示扩展信息，例如uid等
-s 按各个协议进行统计
-c 每隔一个固定时间，执行该netstat命令。
-i 显示网络接口列表

提示：LISTEN和LISTENING的状态只有用-a或者-l才能看到

netstat -ie //运行结果与ifconfig相同

@2:PDB
'''
import pdb
def main():
	pass
pdb.run("main()")
'''
或者在需要调试的地方加入`pdb.set_trace()`, 运行后在`pdb.set_trace()`位置被断住
'''
import pdb
def main():
    pdb.set_trace()
    for line in wlist:
        print line
main()
'''

pdb
b 加断点，函数名、行号
c continue 运行程序，直到遇到断点。
l 查看断点周围的代码
a 查看参数
s, n 单步运行
p 查看表达式的值
condition 条件断点，只有条件为true断点才命中
'''
(Pdb) b
Num Type         Disp Enb   Where
2   breakpoint   keep yes   at c:\users\plpcc\desktop\pdbtest.py:5
(Pdb) condition 2 i==1   //i==1时才触发断点2
New condition set for breakpoint 2.
'''
bt 查看调用堆栈
r 执行到函数返回

@3: tcpdump
[tcpdump Demo](http://www.cnblogs.com/lxw0109/p/tcpdump.html)

@4: strace
strace - trace system calls and signals
-c	统计每种系统调用所执行的时间，调用次数，出错次数。
-p	跟踪指定的进程
-o filename 默认strace将结果输出到stdout
-f	跟踪由fork子进程系统调用
-ff	常与-o选项一起使用，不同进程(子进程)产生的系统调用输出到filename.PID文件
-r	打印每一个系统调用的相对时间
-t	在输出中的每一行前加上时间信息。 -tt 时间确定到微秒级。还可以使用-ttt打印相对时间
-e expr 输出过滤器，通过表达式，可以过滤出掉你不想要输出
-e trace=file/process/network/signal/ipc/all	只跟踪有关文件操作/进程控制/与网络有关/与系统信号有关/与进程通讯有关/所有的/的系统调用. 
'''
strace -crt -e trace=all -o result cat /dev/null
'''
