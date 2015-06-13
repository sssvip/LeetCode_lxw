// Fast but not understand.
// File: num030.cpp
// Author: lxw
// Date: 2015-06-09

/*
Num num030: Substring with Concatenation of All Words
Source: https://leetcode.com/problems/substring-with-concatenation-of-all-words/

You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int word_len = words[0].size();
        int len = words.size()*word_len;
        int n = s.size();
        unordered_map<string, int> m;              // <单词,出现的次数>
        for(int i=0; i<words.size(); ++i)
        {
            if(m.count(words[i]) == 0)             // 注意count方法的使用
                m.insert(make_pair(words[i], 1));
            else
                ++m[words[i]];
        }

        vector<int> index;
        for(int i=0; i<word_len; ++i)
        {
            unordered_map<string, int> win;
            int left = i;                           // 窗口左边沿
            int count = 0;                          // 窗口中的单词数目
            for(int right=i; right<=n-word_len; right+=word_len)
            {
                string word = s.substr(right, word_len);
                if(m.find(word) != m.end())         // 在集合中
                {
                    if(win.find(word) == win.end()) // 不在窗口中，即添加
                        win[word] = 1;
                    else
                        ++win[word];                // 在窗口中

                    if(win[word] <= m[word])        // 还没出现相应的次数
                        ++count;
                    else  
                    {
                        // 单词在集合中，但是它已经在窗口中出现了相应的次数，不应该加入窗口
                        // 此时把窗口起始位置想左移动到，该单词第一次出现的位置的下一个单词位置
                        for(int k=left;  ; k+=word_len)
                        {
                            string temp = s.substr(k, word_len);
                            --win[temp];
                            if(temp == word)
                            {
                                left = k + word_len;
                                break;
                            }
                            --count;
                        }
                    }

                    if(count == words.size())
                        index.push_back(left);
                }
                else                                // 不在集合中，从窗口右侧重新开始
                {
                    left = right + word_len;
                    win.clear();
                    count = 0;
                }
            }
        }

        return index;
    }
};

int main(void){
    Solution sol;
    vector<string> words = {"fooo","barr","wing","ding","wing"};
    vector<int> result = sol.findSubstring("lingmindraboofooowingdingbarrwingmonkeypoundcake", words);
    //vector<int> result = sol.findSubstring("fooowingdingbarrwing", words);
    int length = result.size();
    for(int i = 0; i < length; ++i){
        cout << result[i] << endl;
    }
    return 0;
}
