// File: num241.cpp
// Author: lxw
// Date: 2015-08-01

/*
Num num241: Valid Anagram
Source: https://leetcode.com/problems/valid-anagram/

Given two strings s and t, write a function to determine if t is an anagram of s.

For example,
s = "anagram", t = "nagaram", return true.
s = "rat", t = "car", return false.

Note:You may assume the string contains only lowercase alphabets.
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        /*//OK
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        return s == t;
        */
        
        vector<int> count(256, 0);
        int length1 = s.length();
        for(int i = 0; i < length1; ++i){
            ++count[s[i]];
        }
        int length2 = t.length();
        for(int i = 0; i < length2; ++i){
            --count[t[i]];
        }
        for(int i = 0; i < 256; ++i){
            if(count[i] != 0)
                return false;
        }
        return true;
    }
};