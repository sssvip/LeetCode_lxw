// File: num058.cpp
// Author: lxw
// Date: 2015-06-29

/*
Num num058: Length of Last Word 
Source: https://leetcode.com/problems/length-of-last-word/

Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word in the string.

If the last word does not exist, return 0.

Note: A word is defined as a character sequence consists of non-space characters only.

For example, 
Given s = "Hello World",
return 5.
*/

class Solution {
public:
    int lengthOfLastWord(string s) {
        int length = s.length();
        int lastLength = 0;
        int i = length - 1;
        while(s[i] == ' '){
            --i;
        }
        while(i >= 0){
            if(s[i] != ' '){
                --i;
                ++lastLength;
            }
            else{
                break;
            }
        }
        return lastLength;
    }
};