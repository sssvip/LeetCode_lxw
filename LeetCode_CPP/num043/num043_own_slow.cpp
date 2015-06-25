// File: num043_own_slow.cpp
// Author: lxw
// Date: 2015-06-25

/*
Num num043: Multiply Strings
Source: https://leetcode.com/problems/multiply-strings/

Given two numbers represented as strings, return multiplication of the numbers as a string.

Note: The numbers can be arbitrarily large and are non-negative.
*/

#include <iostream>
using namespace std;

class Solution {
private:
    string reverseStr(string str){
        int length = str.length();
        int middle = length / 2;
        for(int i = 0; i < middle; ++i){
            char temp = str[i];
            str[i] = str[length-1-i];
            str[length-1-i] = temp;
        }
        return str;
    }
    string multiplyDigit(string num1, string digit){
        if(digit[0] == '0'){
            return "0";
        }
        if(digit[0] == '1'){
            return num1;
        }
        //cout << "num1: " << num1 << ", digit: " << digit << endl;
        int length = num1.length();
        int digit1 = 0;
        int digit2 = digit[0] - '0';
        int product = 0; 
        int carry = 0;
        string result = "";
        for(int i = length-1; i >= 0; --i){
            digit1 = num1[i] - '0';
            product = digit1 * digit2 + carry;
            //cout << "product: " << product << endl;
            result += product % 10 + '0';
            carry = product / 10;
        }
        if(carry != 0){
            result += carry + '0';
        }
        //cout << "result: " << result << endl;
        //cout << "reverseStr(result): " << reverseStr(result) << endl;
        return reverseStr(result);
    }
    string add2StrNum(string num1, string num2){
        num1 = reverseStr(num1);
        num2 = reverseStr(num2);
        int i = 0, j = 0, digit1, digit2, carry = 0, tempSum;
        int length1 = num1.length(), length2 = num2.length();
        string result = "";
        while(i < length1 || j < length2 || carry != 0){
            digit1 = i < length1 ? num1[i] - '0' : 0;
            digit2 = j < length2 ? num2[i] - '0' : 0;
            tempSum = digit1 + digit2 + carry;
            result += tempSum % 10 + '0';
            carry = tempSum / 10;
            ++i;
            ++j;
        }
        return reverseStr(result);
    }
public:
    string multiply(string num1, string num2) {
        if(num1 == "0"){
            return "0";
        }
        if(num1 == "1"){
            return num2;
        }
        int length = num2.length();
        string result = "0";
        string digitResult = "";
        string zeros = "";
        for(int i = length-1; i >= 0; --i){
            digitResult = multiplyDigit(num1, string(1, num2[i])) + zeros;
            //cout << "digitResult: " << digitResult << endl;
            zeros += "0";
            result = add2StrNum(result, digitResult);
        }
        return result;
    }
};

int main(void) {
	Solution sol;
	cout << sol.multiply("123", "456") << endl;
    return 0;
}
