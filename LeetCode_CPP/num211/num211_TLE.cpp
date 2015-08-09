// File: num211_TLE.cpp
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

class WordDictionary {
private:
    unordered_set<string> dict;
public:
    // Adds a word into the data structure.
    void addWord(string word) {
        this->dict.insert(word);
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        if(word.find('.') != string::npos){
            unordered_set<string>::iterator it;
            int length = 0;
            int wordLen = word.size();
            for(it = this->dict.begin(); it != this->dict.end(); ++it){
                length = (*it).length();
                if(length == wordLen){
                    int i;
                    for(i = 0; i < length; ++i){
                        if(word[i] == '.' || (*it)[i] == word[i])
                            continue;
                        else
                            break;
                    }
                    if(i == length){
                        return true;
                    }
                }
            }
            return false;
        }
        else{
            return dict.find(word) != dict.end();
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");