//File: trie_1.cpp
//Author: lxw
//Time: 2015-07-26
//Usage: Trie Tree Demo 1.

/*
题目：给定一个数组a[]，再给出m个询问，每个询问一个数x，在a[]中找出一个数y，使得x与y的异或值最大。
 
分析：最直观的思路就是对于每一个询问，直接暴力在数组a[]中比较，找最大的，但这样做的时间复杂度会很大。O(m*n) 
我们有一个很好的解法，那就是字典树，假设所有的数字范围均在int内，那么就可以建立深度为32的字典树即可，所以总的时间复杂度为O(32*m)。 
建好字典树后，从根节点往下遍历一遍就行了，先对x按位取反，尽量走相同的节点，如果不存在就忽略。
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;
typedef long long LL;

class TrieNode{
public:
    TrieNode *next[2];
    /*
    TrieNode(){
        memset(next,NULL,sizeof(next));
    }
    */
};

TrieNode *root;

void Insert(LL n){
    TrieNode *p = root;
    for(int i = 31; i >= 0; i--){
        int id = (n >> i) & 1;
        if(p->next[id] == NULL){
             p->next[id] = new TrieNode();
        }
        p = p->next[id];
    }
}

void Delete(TrieNode *T){
    if(T == NULL)
        return;
    for(int i=0;i<2;i++){
        if(T->next[i] != NULL){
            Delete(T->next[i]);
        }
    }
}

LL Match(LL m){
    m = ~m;
    LL ans = 0;
    TrieNode *p = root;
    for(int i = 31;i >= 0; i--){
        ans <<= 1;
        int bit = (m >> i) & 1;
        if(bit){
            if(p->next[1]){
                p = p->next[1];
                ans++;
            }
            else{
                p = p->next[0];
            }
        }
        else{
            if(p->next[0])
            {
                p = p->next[0];
            }
            else
            {
                p = p->next[1];
                ans++;
            }
        }
    }
    return ans;
}

int main(){
    int T, tt = 1;
    scanf("%d",&T);
    while(T--){
        int n,m;
        root = new TrieNode();
        scanf("%d%d",&n,&m);
        for(int i = 0; i < n; i++){
            LL val;
            scanf("%I64d",&val);
            Insert(val);
        }
        printf("Case #%d:\n",tt++);
        while(m--){
            LL val;
            scanf("%I64d",&val);
            printf("%I64d\n",Match(val));
        }
        Delete(root);
    }
    return 0;
}
