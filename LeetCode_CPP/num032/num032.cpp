// File: num032.cpp
// Author: lxw
// Date: 2015-06-13

/*
Num num032: Longest Valid Parentheses
Source: https://leetcode.com/problems/longest-valid-parentheses/

Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.
*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> charStack;
        int length = s.length();
        vector<bool> result(length, false);
        for(int i = 0; i < length; ++i){
            switch(s[i]){
                case '(':
                    charStack.push(i);
                    break;
                case ')':
                    if(!charStack.empty()){
                        int index = charStack.top();
                        charStack.pop();
                        result[i] = true;
                        result[index] = true;
                    }
                    break;
            }
        }
        int maxLength = 0;
        int tempLength = 0;
        for(int i = 0; i < length; ++i){
            if(result[i]){
                ++tempLength;
                maxLength = max(maxLength, tempLength);
            }
            else{
                tempLength = 0;
            }
        }
        return maxLength;
    }
};

int main(void){
    Solution sol;
    string str = "(()()(()(()))()((()))((()(()())()(()))())))()(()()))())))))))()()()()))(((()())((()()(((())))()(()()(())((()))))))(()(()))(((()())()))(()))((((()(()()()())()()(()))(()()(())()((()()())))(())()())()(";
    cout << sol.longestValidParentheses(str) << endl;
    return 0;
}
