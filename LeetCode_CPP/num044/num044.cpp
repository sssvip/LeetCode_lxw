// File: num044.cpp
// Author: lxw
// Date: 2015-06-25

/*
Num num044: Wildcard Matching
Source: https://leetcode.com/problems/wildcard-matching/

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int pPos = -1;
        int sPos = -1;
        int i = 0;
        int j = 0;
        while (i < s.size()) {
            if (s[i] == p[j] || p[j] == '?') {
                i ++;
                j ++;
                continue;
            }
            if (p[j] == '*') {
                pPos = j;
                sPos = i;
                j ++;
                continue;
            }
            if (pPos != -1 && sPos != -1) {
                i = sPos + 1;
                j = pPos + 1;
                sPos ++;
                continue;
            }
            return false;
        }
        while (p[j] == '*')
            j ++;
        return j == p.size();
    }
};

int main(void){
	Solution sol;
	cout << sol.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") << endl;
	return 0;
}
