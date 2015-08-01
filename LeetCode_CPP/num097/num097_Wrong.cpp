// File: num097_Wrong.cpp
// Author: lxw
// Date: 2015-07-30

/*
Num 097: Interleaving String
Source: https://leetcode.com/problems/interleaving-string/

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {    //此方法错误(特例: aa ab  aaba)
        if(s1 == "")
            return s2 == s3;
        if(s2 == "")
            return s1 == s3;
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if(len1 + len2 != len3)
            return false;
        string::iterator it1 = s1.begin();
        string::iterator it2 = s2.begin();
        string::iterator it3 = s3.begin();
        while(it1 != s1.end() && it2 != s2.end()){
            if(*it1 == *it3){
                ++it1;
            }
            else if(*it2 == *it3){
                ++it2;
            }
            else{
                return false;
            }
            ++it3;
        }
        while(it1 != s1.end()){
            if(*it1 != *it3)
                return false;
            ++it1;
            ++it3;
        }
        while(it2 != s2.end()){
            if(*it2 != *it3)
                return false;
            ++it2;
            ++it3;
        }
        return true;
    }
};