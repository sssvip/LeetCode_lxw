// File: num067.cpp
// Author: lxw
// Date: 2015-07-03

/*
Num 067: Add Binary
Source: https://leetcode.com/problems/add-binary/

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;


class Solution {
private:
    string reverse(string str){
	    int length = str.length();
	    if(length <= 1){
	        return str;
	    }
	    int mid = length / 2;
	    char ch;
	    for(int i = 0; i < mid; ++i){
	        ch = str[i];
	        str[i] = str[length-1-i];
	        str[length-1-i] = ch;
	    }
	    return str;
	}
public:
    string addBinary(string a, string b) {
        int length1 = a.length();
        int length2 = b.length();
        if(length1 == 0){
            return b;
        }
        if(length2 == 0){
            return a;
        }
        int i = length1 - 1, j = length2 - 1;
        int digit1 = 0, digit2 = 0, digit = 0, carry = 0;
        string result = "";
        while(i >= 0 || j >= 0 || carry){
            digit1 = i >= 0 ? a[i] - '0' : 0;
            digit2 = j >= 0 ? b[j] - '0' : 0;
            --i;
            --j;
            digit = digit1 + digit2 + carry;            
            if(digit >= 2){    //2 or 3
                digit -= 2;
                carry = 1;
            }
            else{
                carry = 0;
            }
            result += digit + '0';            
        }        
        return reverse(result);
    }
};

int main(void){
	Solution sol;
	cout << sol.addBinary("1010", "1011") << endl;
	return 0;
}
