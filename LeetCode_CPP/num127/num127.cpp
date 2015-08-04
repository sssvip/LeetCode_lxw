// File: num128.cpp
// Author: lxw
// Date: 2015-08-03

/*
Num num127: Word Ladder
Source: https://leetcode.com/problems/word-ladder/

Given two words (beginWord and endWord), and a dictionary, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the dictionary
For example,

Given:
start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.

Note:
Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
*/

//Reference:
//http://blog.csdn.net/doc_sgl/article/details/13290909

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
        if(beginWord == endWord)
            return 0;
        if(beginWord == "" || endWord == "")
            return 0;
            
        queue<string> strQue;
        strQue.push(beginWord);
        wordDict.erase(beginWord);
        int count = 1;
        int level = 0;
        int length = beginWord.length();
        while(!strQue.empty() && !wordDict.empty()){
            string item = strQue.front();
            strQue.pop();
            --count;
            for(int i = 0; i < length; ++i){
                for(int j = 0; j < 26; ++j){
                    string temp = item;
                    temp[i] = 'a' + j;
                    if(temp == endWord)
                        return level + 2;
                    if(wordDict.find(temp) != wordDict.end()){
                        strQue.push(temp);
                        wordDict.erase(temp);
                    }
                }
            }
            if(count == 0){
                count = strQue.size();
                ++level;
            }
        }
        return 0;
    }
};