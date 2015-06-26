// NOTE: THIS IS NOT A GOOD SOLUTION, 'j' MAY be OutOfBounds. such as: s="a", p="*"
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
	// NOTE: THIS IS NOT A GOOD SOLUTION, 'j' MAY be OutOfBounds. such as: s="a", p="*"
    bool isMatch(string s, string p){
    	int length = s.length();
    	int i = 0, j = 0;
    	int sPos = -1, pPos = -1;
    	while(i < length){
    		if(s[i] == p[j] || p[j] == '?'){
    			++i;
    			++j;
    			continue;
    		}
    		if(p[j] == '*'){
    			sPos = i;
    			pPos = j;
    			++j;
    			continue;
    		}
    		//if(sPos != -1 && pPos != -1){	//In this context: equal to the following expression.
    		if(sPos != -1){
    			i = ++sPos;	//sPos increase 1
    			j = pPos + 1;
    			continue;
    		}
    		return false;
    	}
    	while(p[j] == '*'){
    		++j;
    	}
    	return j == p.length();
    }
};

int main(void){
	Solution sol;
	cout << sol.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "*") << endl;
	return 0;
}
