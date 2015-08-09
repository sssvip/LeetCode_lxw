// File: num211.cpp
// Author: lxw
// Date: 2015-08-09

/*
Num num211: Add and Search Word - Data structure design
Source: https://leetcode.com/problems/add-and-search-word-data-structure-design/

Design a data structure that supports the following two operations:

void addWord(word)
bool search(word)
search(word) can search a literal word or a regular expression string containing only letters a-z or .. A . means it can represent any one letter.

For example:

addWord("bad")
addWord("dad")
addWord("mad")
search("pad") -> false
search("bad") -> true
search(".ad") -> true
search("b..") -> true
Note:
You may assume that all words are consist of lowercase letters a-z.

click to show hint.

You should be familiar with how a Trie works. If not, please work on this problem: Implement Trie (Prefix Tree) first.
*/

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
    bool search(string & word, int index, int end, TrieNode * node){
        if(index > end){
            return node->getEndFlag();
        }
        if(word[index] == '.'){
            for(int i = 0; i < 26; ++i){
                if((node->getChildren())[i] != NULL){
                    if(search(word, index+1, end, (node->getChildren())[i]))
                        return true;
                }
            }
        }
        else if((node->getChildren())[word[index]-'a'] != NULL){
            if(search(word, index+1, end, (node->getChildren())[word[index]-'a']))
                return true;
        }
        return false;
    }
    TrieNode * getRoot(){
        return this->root;
    }
private:
    TrieNode* root;
};

class WordDictionary {
private:
    Trie trie;
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        this->trie.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return this->trie.search(word, 0, word.size()-1, trie.getRoot());
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");