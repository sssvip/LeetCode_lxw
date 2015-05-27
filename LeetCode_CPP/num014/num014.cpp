// File: num014.cpp
// Author: lxw
// Date: 2015-05-27

/*
Num 013: Longest Common Prefix
Source: https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string compareTwoString(string str1, string str2){
        int length1 = str1.length();
        int length2 = str2.length();
        int index = 0;
        while(index < length1 && index < length2){
            if(str1[index] != str2[index])
                break;
            ++index;
        }
        return str1.substr(0, index);
    }
    string longestCommonPrefix(vector<string>& strs) {
        int size = strs.size();
        if(size == 0){      //Note the special cases.
            return "";
        }
        string str = strs[0];
        for(int i = 1; i < size; ++i){
            str = compareTwoString(str, strs[i]);
        }
        return str;
    }
};
