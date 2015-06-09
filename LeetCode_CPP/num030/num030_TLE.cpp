// Time Limit Exceeded.
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
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        int wLength = words.size();
        //Hash words into Map.
        unordered_map<string, string> wordsMap;
        for(int i = 0; i < wLength; ++i){
            stringstream ss;
            string str;
            ss << i;
            ss >> str;
            if(wordsMap.count(words[i]) == 0){
                wordsMap.insert({words[i], str});
            }
            else{
                wordsMap[words[i]] += "," + str;
            }
        }
        /*
        for(auto& item: wordsMap){
            cout << item.first << ": " << item.second << endl;
        }*/
        const int LETTERCOUNT = words[0].length();
        int sLength = s.length();
        int end = sLength - wLength * LETTERCOUNT;
        for(int i = 0; i <= end; ++i){
            string str = s.substr(i, LETTERCOUNT);
            if(wordsMap.count(str) == 1){   //return value of count(): found -> 1; not found -> 0;
                //The index of word has been dealt in words.
                unordered_set<string> dealtCount;
                int index = i;
                string value="";
                while(dealtCount.size() < wLength){
                    if(wordsMap.count(str) == 1){   //In wordsMap.
                        value = wordsMap[str];
                        if(dealtCount.count(value) == 1){ //Already appeared.(no ',')
                            break;
                        }
                        else{   //Not appeard or with ','
                            // With ",".
                            if(value.find(",") < 11){   //string.find() is different from unordered_map & unordered_set. The max number's length is less than 10.
                                bool flag = false;
                                string token = "";
                                istringstream f(value);
                                while(getline(f, token, ',')){
                                    if(dealtCount.count(token) == 1){
                                        continue;
                                    }
                                    else{
                                        dealtCount.insert(token);
                                        flag = true;
                                        break;
                                    }
                                }
                                if(flag == false){
                                    break;
                                }
                            }
                            else{ // Without ",".
                                dealtCount.insert(value);
                            }
                        }
                        index += LETTERCOUNT;
                    }
                    else{   //Not in wordsMap.
                        break;
                    }
                    str = s.substr(index, LETTERCOUNT);
                }//while outmost
                if(dealtCount.size() == wLength){
                    result.push_back(i);
                }
            }//if outmost
        }//for outmost
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
