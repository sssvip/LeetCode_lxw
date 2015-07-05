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

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        int length = s.length();
        bool dot = false;
        bool e = false;
        bool digit1 = false;
        bool digit2 = false;
        bool space = false;
        for(int i = 0; i < length; ++i){
            if(s[i] >= '0' && s[i] <= '9'){
           		//cout << "space: " << space << ", s[i]: " << s[i] << endl;
            	if(space){
            		return false;
            	}
            	space = false;
            	if(!dot){
            		digit1 = true;
            	}
            	else{
            		digit2 = true;
            	}
            }
            else if(s[i] == '.'){
            	if(dot){
            		return false;
            	}
            	dot = true;
            	if(space && digit1){
            		return false;
            	}
            }
            else if(s[i] == 'e'){
            	if(dot && (digit2 || digit1)){
            		digit1 = digit2 = dot = space = false;
            		continue;            		
            	}
            	else if(dot){
            		return false;
            	}
            	else if(!dot && digit1){
            		digit1 = digit2 = dot = space = false;
            		continue;
            	}
            	else if(!dot && !digit1){
            		return false;
            	}
            }
            else if(s[i] == '+' || s[i] == '-'){
                continue;
            }
            else if(isspace(s[i])){            	
            	if(digit1 || dot)
                	space = true;
                //cout << "digit1: " << digit1 << ", space: " << space << endl;
            }
            else{
                return false;
            }
        }
        //cout << "dot: " << dot << ", digit1: " << digit1 << ", digit2: " << digit2 << endl;
        if(dot && (digit2 || digit1)){
    		return true;
    	}
    	else if(dot){
    		return false;
    	}
    	else if(!dot && digit1){
    		return true;
    	}
    	else if(!dot && !digit1){
    		return false;
    	}
    }
};

int main(void){
	Solution sol;
	string str;
	while(getline(cin, str)){
		cout << sol.isNumber(str) << endl;
	}
	return 0;
}