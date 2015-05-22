// File: num005_dp.cpp
// Author: lxw
// Date: 2015-05-22

/*
Num 005: Longest Palindromic Substring
Source: https://leetcode.com/problems/longest-palindromic-substring/

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include <iostream>

class Solution {
    public:
        std::string longestPalindrome(std::string s) {
            int length = s.length();
            int array2[1000][1000] = {false};
            int maxStart = 0;
            int maxLength = 1;
            for(int i = 0; i < length; ++i){
                array2[i][i] = true;
            }
            //length == 2
            for(int i = 0; i < length-1; ++i){
                if(s[i] == s[i+1]){
                    array2[i][i+1] = true;
                    maxLength = 2;
                    maxStart = i;
                }
            }
            //length >= 3
            for(int curLength = 3; curLength <= length; ++curLength){
                for(int i = 0; i < length-curLength+1; ++i){
                    int j = i + curLength - 1;
                    if(array2[i+1][j-1] && s[i] == s[j]){
                        array2[i][j] = true;
                        maxLength = curLength;
                        maxStart = i;
                    }
                }
            }
            return s.substr(maxStart, maxLength);
        }
};

int main(int argc, char ** argv){
	Solution s;
	std::cout << s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << std::endl;
	return 0;
}
