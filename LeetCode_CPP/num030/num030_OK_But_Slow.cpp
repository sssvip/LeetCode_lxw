// MUCH TOO SLOW.
// File: num030_OK_But_Slow.cpp
// Author: lxw
// Date: 2015-06-13
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
        vector<int> result;
        int wLength = words.size();
        //Hash words into Map.
        unordered_map<string, int> wordsMap;
        for(int i = 0; i < wLength; ++i){
            stringstream ss;
            string str;
            ss << i;
            ss >> str;
            if(wordsMap.count(words[i]) == 0){
                wordsMap.insert({words[i], 1});
            }
            else{
                ++wordsMap[words[i]];
            }
        }
        const int LETTERCOUNT = words[0].length();
        int sLength = s.length();
        int end = sLength - wLength * LETTERCOUNT;
        for(int i = 0; i <= end; ++i){
            string str = s.substr(i, LETTERCOUNT);
            if(wordsMap.count(str) == 0){
                continue;
            }
            int index = i;
            unordered_map<string, int> tempMap(wordsMap);
            --tempMap[str];
            //Match One;
            index += LETTERCOUNT;
            int count = 1;
            while(index <= sLength - LETTERCOUNT){
                str = s.substr(index, LETTERCOUNT);
                if(tempMap.count(str) == 0){
                    break;
                }
                else{
                    if(tempMap[str] > 0){
                        count += 1;
                        --tempMap[str];
                    }
                    else{
                        break;
                    }
                }
                index += LETTERCOUNT;
            }
                //cout << count << ", " << wLength << endl;
            if(count == wLength){
                result.push_back(i);
            }
        }
        return result;
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
