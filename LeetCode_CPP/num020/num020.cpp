// File: num020.cpp
// Author: lxw
// Date: 2015-06-01

/*
Num 020: Valid Parentheses
Source: https://leetcode.com/problems/valid-parentheses/

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

#include <iostream>
#include <stack>
#include <map>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        map<char, char> mapping;
        mapping[')'] = '(';
        mapping[']'] = '[';
        mapping['}'] = '{';
        int length = s.length();
        for(int i = 0; i < length; ++i){
            char element = '\0';
            switch(s[i]){
                case '(':
                case '[':
                case '{':
                {
                    st.push(s[i]);
                    break;
                }
                case ')':
                case ']':
                case '}': 
                {
                    if(!st.empty()){
                        element = st.top();
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                default:
                    break;
            }
            if(element != '\0' && element != mapping[s[i]]){
                return false;
            }
        }
        if(st.empty()){
            return true;
        }
        else{
            return false;
        }
    }
};

int main(void)
{
    Solution sol;
    cout << sol.isValid("#include <iostream> using namespace std; void main(void){return 0;}") << endl;
    return 0;
}
