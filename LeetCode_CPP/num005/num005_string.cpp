// File: num005.cpp
// Author: lxw
// Date: 2015-05-20

/*
Num 005: Longest Palindromic Substring
Source: https://leetcode.com/problems/longest-palindromic-substring/

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include <iostream>
#include <string>
using std::string;	//If use string, this is essential. #include <string> alone is not enough.

class Solution {
    public:
        string getPalindrome(string s, int left, int right){
            int length = s.length();
            while(left >= 0 && right < length){
                if(s[left] != s[right]){
                    break;
                }
                --left;
                ++right;
            }
            return s.substr(left+1, right-left-1);
        }
        string longestPalindrome(string s) {
            int length = s.length();
            string longestStr = s.substr(0, 1);
            for(int i = 0; i < length-1; ++i){
                string retStr = getPalindrome(s, i, i);
                if(retStr.length() > longestStr.length()){
                    longestStr = retStr;
                }
                if(s[i] == s[i+1]){
                    retStr = getPalindrome(s, i, i+1);
                    if(retStr.length() > longestStr.length()){
                        longestStr = retStr;
                    }
                }
            }
            return longestStr;
        }
};

int main(int argc, char ** argv){
	Solution s;
	std::cout << s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << std::endl;
	return 0;
}
