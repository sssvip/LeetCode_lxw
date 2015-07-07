1. int 最大有几位数字？10
long long 呢？19
INT_MAX * INT_MAX 结果19位数字，没有超过long long 的范围
INT_MIN * INT_MIN 结果19位数字，没有超过long long 的范围

2. DP（动态规划）一般不用递归，一般都需要使用一个二维数组对中间状态进行记录，然后求解该二维数组（逐行逐列计算二维数组的值）
