### << 和 >>
乘2左移1位,除2右移1位
左移还是右移一定要仔细
NOTE: negative integer ">>1" MAY NOT EQUAL TO "/2". positive integer is OK.

### int/long long 取值范围:
int 最大有几位数字？10
long long 呢？19
INT_MAX * INT_MAX 结果19位数字，没有超过long long 的范围
INT_MIN * INT_MIN 结果19位数字，没有超过long long 的范围

### DP:
DP（动态规划）一般不用递归，一般都需要使用一个二维数组对中间状态进行记录，然后求解该二维数组（逐行逐列计算二维数组的值）

###平衡因子:
**节点的平衡因子**是它的左子树的高度减去它的右子树的高度（有时相反）。带有平衡因子1、0或 -1的节点被认为是平衡的。带有平衡因子 -2或2的节点被认为是不平衡的，并需要重新平衡这个树。平衡因子可以直接存储在每个节点中，或从可能存储在节点中的子树高度计算出来。

###AVL树:
**AVL树**是最先发明的自平衡二叉查找树。在AVL树中任何节点的两个子树的高度最大差别为一，所以它**也被称为高度平衡树**。
AVL树是以它的发明者命名的.
高度为h的AVL树,节点数N最多2^h − 1;最少N(h)=N(h−1)+N(h−2)+1,一个递归数列。

###BST(Binary Search Tree)树:
可以不平衡.

http://blog.csdn.net/bingjing12345/article/details/7830474
###B树 B+树
TBD

###红黑树(Red-Black Tree) RBT
TBD

###Math
(a * b) mod c == (a mod c) * (b mod c)
(a * b) mod c == ((a mod c) * (b mod c)) mod c
2^100 mod 7 == (2^3)^33*2 mod 7 == 2^3 mod 7 * ... * 2^3 mod 7 * 2 mod 7 == 2 mod 7 == 2

###Bucket Sort
桶排序使用线性时间Θ（n）.桶排序并不是比较排序，他不受到O(n log n)下限的影响。

###Note
char s[10];
s = "hello"; //error: incompatible types in assignment of ‘const char[6]’ to ‘char [10]’                                                        
char t[10] = "hello";   //OK
