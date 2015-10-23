// File: num290.cpp
// Author: lxw
// Date: 2015-10-23

/*
Num num290: Word Pattern
Source: https://leetcode.com/problems/word-pattern/

Given a pattern and a string str, find if str follows the same pattern.

Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.

Examples:
pattern = "abba", str = "dog cat cat dog" should return true.
pattern = "abba", str = "dog cat cat fish" should return false.
pattern = "aaaa", str = "dog cat cat dog" should return false.
pattern = "abba", str = "dog dog dog dog" should return false.
Notes:
You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.

Credits:
Special thanks to @minglotus6 for adding this problem and creating all test cases.
*/

class Solution {
private:
    void split(string& str, vector<string> & strVec, string & deli, int start){
        int index = 0;
        while(1){
            index = str.find(deli, start);
            if(index == -1)
                break;
            strVec.push_back(str.substr(start, index - start));
            start = index + 1;
        }
        int length = str.length();
        if(start < length){
            strVec.push_back(str.substr(start));
        }
    }
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<char, string> patternMap;
        unordered_map<string, char> strMap;
        int length = pattern.length();
        vector<string> strVec;
        string deli = " ";
        split(str, strVec, deli, 0);
        if(strVec.size() != length)
            return false;
        for(int i = 0; i < length; ++i){
            if(patternMap.find(pattern[i]) == patternMap.end()){
                patternMap[pattern[i]] = strVec[i];
                if(strMap.find(strVec[i]) != strMap.end())
                    return false;
                strMap[strVec[i]] = pattern[i];
            }
            else{
                if(patternMap[pattern[i]] != strVec[i])
                    return false;
                if(strMap[strVec[i]] != pattern[i])
                    return false;
            }
        }
    }
};