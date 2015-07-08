// File: num065.cpp
// Author: lxw
// Date: 2015-07-07

/*
Num num065: Valid Number 
Source: https://leetcode.com/problems/valid-number/

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true
Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.
*/

//Reference: http://www.cnblogs.com/x1957/p/3517617.html

enum Op{
    Operator, //0
    Digit, // 1
    E, // 2
    Dot, //3
    Space,// 4
    Invalid
};
int table[][5] = {
    {1,2,-1,8,-1},
    {-1,2,-1,8,-1},
    {-1,2,4,3,-1},
    {-1,7,4,-1,-1},
    {5,6,-1,-1,-1},
    {-1,6,-1,-1,-1},
    {-1,6,-1,-1,-1},
    {-1,7,4,-1,-1},
    {-1,9,-1,-1,-1},
    {-1,9,4,-1,-1}

};
class Solution {
public:
    bool trim(string& s) {
        int start = 0;
        int end = s.size() - 1;
        while(start <= end && s[start] == ' ') start++;
        while(end >= 0 && s[end] == ' ') end--;
        if(end >= start) s = s.substr(start , end - start + 1);
        else return false;
        return true;
    }
    Op getOp(char ch) {
        if(ch == '+' || ch == '-') return Operator;
        if(ch >= '0' && ch <= '9') return Digit;
        if(ch == 'e') return E;
        if(ch == '.') return Dot;
        if(ch == ' ') return Space;
        return Invalid;
    }
    bool isNumber(string s) {
        string str = s;
        if(!trim(str)) return false;
        int pos = 0;
        int size = str.size();
        int state = 0;
        while(pos < size) {
            char ch = str[pos];
            Op x = getOp(ch);
            if(x == Invalid) return false;
            state = table[state][(int)x];
            if(state == -1) return false;
            pos++;
        }
        return state == 2 || state == 6  || state == 7 || state == 3 || state == 9;
    }
};