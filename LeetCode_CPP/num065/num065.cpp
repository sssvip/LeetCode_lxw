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

class Solution {
public:
    bool isNumber(string s) {
        const char * charStr = s.c_str();
        char * end;
        strtod(charStr, &end);
        if(end == charStr){ // all spaces.
            return false;
        }
        for(; *end; ++end){
            if(!isspace(*end)){
                return false;
            }
        }
        return true;
    }
};