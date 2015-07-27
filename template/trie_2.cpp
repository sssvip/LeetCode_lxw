//File: trie_2.cpp
//Author: lxw
//Time: 2015-07-27
//Usage: Trie Tree Demo 2.

/*
Description
给定一些数，求这些数中两个数的异或值最大的那个值

Input
第一行为数字个数n，1 <= n <= 10 ^ 5。接下来n行每行一个32位有符号非负整数。

Output
任意两数最大异或值

Sample Input
3
3
7
9
Sample Output
14
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

void insert(int n, TrieNode * root){
    TrieNode *p = root;
    for(int i = 31; i >= 0; i--){
        int id = (n >> i) & 1;
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

int match(int val, TrieNode * root){
    val = ~val;
    int ans = 0;
    TrieNode * p = root;
    for(int i = 31; i >= 0; i--){
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

int main(){
    int n;
    while(cin >> n){
	    TrieNode * root = new TrieNode();
	    int * array = new int[n];
	    for(int i = 0; i < n; ++i){
	    	cin >> array[i];
	        insert(array[i], root);
	    }
	    int result = INT_MIN;
	    for(int i = 0; i < n; ++i){
	    	result = max(result, array[i] ^ match(array[i], root));
	    }
	    delTrieNode(root);
	    delete[] array;
	    cout << result << endl;
	}
    return 0;
}
