// File: num520.cpp
// Author: lxw
// Date: 2017-03-11

/*
Num num520: Detect Capital
Source: https://leetcode.com/problems/detect-capital/?tab=Description

Given a word, you need to judge whether the usage of capitals in it is right or not.

We define the usage of capitals in a word to be right when one of the following cases holds:

All letters in this word are capitals, like "USA".
All letters in this word are not capitals, like "leetcode".
Only the first letter in this word is capital if it has more than one letter, like "Google".
Otherwise, we define that this word doesn't use capitals in a right way.
Example 1:
Input: "USA"
Output: True
Example 2:
Input: "FlaG"
Output: False
Note: The input will be a non-empty word consisting of uppercase and lowercase latin letters.
*/


class Solution {
public:
    bool detectCapitalUse(string word) {
        int length = word.size();
        if(length < 2)
            return true;
        if(word[length-1] < 97){    //uppercase
            for(int i = length-2; i >= 0; --i){
                if(word[i] > 96)   //lowercase
                    return false;
            }
        }
        else{   //lowercase
            for(int i = length-2; i > 0; --i){
                if(word[i] < 97)   //uppercase
                    return false;
            }
        }
        return true;
    }
};