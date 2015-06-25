// File: num044_TLE.cpp
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
private:
    bool isMatch(string s, int begin1, int end1, string p, int begin2, int end2){
    	//cout << "begin1: " << begin1 << ", end1: " << end1 << ", begin2: " << begin2 << ", end2: " << end2 << endl;
        if(begin1 > end1 && begin2 <= end2){
            while(begin2 <= end2){
                if(p[begin2] !=  '*'){
                    return false;
                }
                ++begin2;
            }
            return true;
        }
        if(begin1 <= end1 && begin2 > end2){
            return false;
        }
        if(begin1 > end1 && begin2 > end2){
            return true;
        }
        
        if(s[begin1] == p[begin2] || p[begin2] == '?'){
            ++begin1;
            ++begin2;
            return isMatch(s, begin1, end1, p, begin2, end2);
        }
        else if(p[begin2] == '*'){
            if(begin2 == end2){
                return true;
            }
            else{
            	++begin2;
            	while(begin1 <= end1){
                	if(isMatch(s, begin1, end1, p, begin2, end2)){
                		return true;
                	}
                	else{                		
                		++begin1;
                	}
                }
                return false;
            }            
        }
        else{
            return false;
        }        
    }
public:
    bool isMatch(string s, string p) {
        int length1 = s.length();
        int length2 = p.length();
        return isMatch(s, 0, length1-1, p, 0, length2-1);
    }
};

int main(void){
	Solution sol;
	//cout << sol.isMatch("aaabbbaabaaaaababaabaaabbabbbbbbbbaabababbabbbaaaaba", "a*******b") << endl;
	cout << sol.isMatch("aaabbbaabababbbbbbbbbbbaaaaba", "a*******b") << endl;
	//cout << sol.isMatch("aaabba", "a**?*****b**???") << endl;
	return 0;
}
