// File: num208.cpp
// Author: lxw
// Date: 2015-08-09

/*
Num 208: Implement Trie (Prefix Tree)
Source: https://leetcode.com/problems/implement-trie-prefix-tree/

Implement a trie with insert, search, and startsWith methods.

Note:
You may assume that all inputs are consist of lowercase letters a-z.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class TrieNode {
private:
    vector<TrieNode *> children;
    bool flag;
public:
    // Initialize your data structure here.
    TrieNode() {
        this->flag = false;
        this->children.resize(26, NULL);
    }
    vector<TrieNode *> & getChildren(){ //Essential to return the reference type.
        return this->children;
    }
    bool getEndFlag(){
        return this->flag;
    }
    bool setEndFlag(bool flag){
         this->flag = flag;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
    void freeTrie(TrieNode * node){
        if(node == NULL)
            return;
        for(int i = 0; i < 26; ++i){
            if((node->getChildren())[i] != NULL){
                freeTrie((node->getChildren())[i]);
            }
        }
        delete node;
    }
    void freeTrie(){
        freeTrie(this->root);
    }
    ~Trie(){
        this->freeTrie();
    }
    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode * ptr = this->root;
        int length = word.size();
        for(int i = 0; i < length; ++i){
            //assert(ptr != NULL);
            if((ptr->getChildren())[word[i]-'a'] == NULL){
                (ptr->getChildren())[word[i]-'a'] = new TrieNode();
            }
            ptr = (ptr->getChildren())[word[i]-'a'];
        }
        ptr->setEndFlag(true); //getChildren() is essential to return the reference type. Otherwise, here will be error 6(110: user, r/w, not present).
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode * ptr = this->root;
        int length = word.size();
        for(int i = 0; i < length; ++i){
            if((ptr->getChildren())[word[i]-'a'] == NULL){
                return false;
            }
            ptr = (ptr->getChildren())[word[i]-'a'];
        }
        return ptr->getEndFlag();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode * ptr = this->root;
        int length = prefix.size();
        for(int i = 0; i < length; ++i){
            if((ptr->getChildren())[prefix[i]-'a'] == NULL){
                return false;
            }
            ptr = (ptr->getChildren())[prefix[i]-'a'];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main(void){
    Trie t;
    t.insert("a");
    cout << t.search("a") << endl;
    cout << t.startsWith("a") << endl;
    return 0;
}