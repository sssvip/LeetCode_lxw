//File: trie_3.cpp
//Author: lxw
//Time: 2015-07-27
//Usage: Trie Tree Demo 3.

/*
http://acm.hrbust.edu.cn/index.php?m=ProblemSet&a=showProblem&problem_id=1717
Description
给一个长度为n的整数序列，现在要你截取这个序列的一个前缀和一个后缀(前缀和后缀不能相交)，使得前缀和后缀的异或值最大。
前缀和后缀的异或值为前缀序列中的数和后缀序列中的数，异或的结果，比如，某个序列的前缀为1、2、4，后缀为8、16，那么它们的异或值为31.
前缀和后缀可以为空，为空时他们的值为0。
Input
有多组测试数据，请处理到文件结束。

对于每组测试数据，第一行包含一个整数n(1<=n<=100 000)。

接下来一行有n个用空格隔开的整数a1, a2, a3, ..., an (0 <= ai <= 1000 000 000 000)。

Output
对于每组测试数据输出一行，保包含一个整数，表示异或的最大的值。
Sample Input
2
1 2
3
1 2 3
2
1000 1000
Sample Output
3
3
1000

分析：
两个相同值异或后为0，那么所以以1 2 4 8 16为例说明，1 2 4 8是a[]的一个前缀, 而4 8 16是a[]的一个后缀，但是它们有交叉，由异或的性质，
它们实际上与前缀1 2和后缀16等价，因为中间的相同部分抵消了。这样我们先对所有前缀插入深度为40的字典树，然后对于每一个后缀来查找，求出最
大值即可。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class TrieNode{
public:
    TrieNode *next[2];
    TrieNode(){
        //memset(next, NULL, sizeof(next));
        int length = sizeof(next) / sizeof(next[0]);
        for(int i = 0; i < length; ++i){
            next[i] = NULL;
        }
    }
};

void insert(long long n, TrieNode * root){
    TrieNode *p = root;
    int id = 0;
    for(int i = 63; i >= 0; i--){
        id = (n >> i) & 1;
        //No "value" property, use the 
        if(p->next[id] == NULL){
             p->next[id] = new TrieNode();
        }
        p = p->next[id];
    }
}

void delTrieNode(TrieNode * root){
    if(root == NULL)
        return;
    for(int i = 0; i < 2; ++i){
        if(root->next[i] != NULL){
            delTrieNode(root->next[i]);
        }
    }
    delete root;
}

long long match(long long val, TrieNode * root){
    val = ~val;
    long long ans = 0;
    TrieNode * p = root;
    for(int i = 63; i >= 0; i--){
        ans <<= 1;
        int bit = (val >> i) & 1;
        if(bit){
            if(p->next[1]){
                p = p->next[1];
                ++ans;
            }
            else{
                p = p->next[0];
            }
        }
        else{
            if(p->next[0]){
                p = p->next[0];
            }
            else{
                p = p->next[1];
                ++ans;
            }
        }
    }
    return ans; //the most similar element in "n numbers".
}

//NOTE: 注意题目中数据的位数需要用long long才能存得下
int main(){
    int n;
    long long temp, result;
    while(cin >> n){
    	if(n == 1){
    		cin >> temp;
    		cout << temp << endl;
    	}
    	else{
		    TrieNode * root = new TrieNode();
		    long long  * array = new long long [n];	    
		    temp = 0;
		    for(int i = 0; i < n; ++i){
		    	cin >> array[i];
		    	temp ^= array[i];	//all prefixes
		        insert(temp, root);
		    }
		    result = LONG_LONG_MIN;
		    temp = 0;
		    for(int i = 0; i < n; ++i){
		    	temp ^= array[n-1-i];
		    	result = max(result, temp ^ match(temp, root));
		    }
		    delTrieNode(root);
		    delete[] array;
		    cout << result << endl;
	    }
	}
    return 0;
}
