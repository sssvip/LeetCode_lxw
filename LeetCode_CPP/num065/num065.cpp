// File: num065.cpp
// Author: lxw
// Date: 2015-07-02

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

//split by 'e' then judge each part?
class Solution {
private:

public:
    bool isNumber(string s) {
        int length = s.length();
        bool dot = false;
        bool e = false;
        bool digit1 = false;
        bool digit2 = false;
        bool digit3 = false;
        bool digit4 = false;
        for(int i = 0; i < length; ++i){
            if(s[i] >= '0' && s[i] <= '9'){
                digit1 = true;
                if(dot)
                    digit2 = true;
                if(e)
                    digit4 = true;
                continue;
            }
            else if(s[i] == '.'){
                if(!dot && digit1)
                    dot = true;
                else
                    return false;
            }
            else if(s[i] == 'e'){
                if(!e && digit1)
                    e = true;
                else
                    return false;
            }
            else if(s[i] == '+' || s[i] == '-'){
                continue;
            }
            else if(isspace(s[i])){
                continue;
            }
            else{
                return false;
            }
        }
        if(e && !digit2){
            return false;
        }
        if(dot && !digit2)
        return ;
    }
};