// File: num013.cpp
// Author: lxw
// Date: 2015-05-24

/*
Num 013: Roman to Integer
Source: https://leetcode.com/problems/roman-to-integer/

Given a roman numeral, convert it to an integer.
Input is guaranteed to be within the range from 1 to 3999.
*/


#include <iostream>
using namespace std;

class Solution {
public:
    //[OK] Method 1. 32ms
    int romanToInt1(string s) {
        //string symbol[] = {"M",    "CM", "D", "CD", "C",   "XC", "L", "XL", "X",  "IX", "V", "IV", "I"};
        //int value[] = {1000,   900, 500, 400, 100,     90, 50, 40, 10,     9, 5, 4, 1};
        int length = s.length();
        int i = 0;
        int result = 0;
        //Thousand
        while(s[i] == 'M'){
            result += 1000;
            ++i;
        }
        if(i >= length)
            return result;
            
        //Hundred    
        string substring = s.substr(i, 2);
        if(substring == "CM"){
            result += 900;
            i += 2;
        }
        else if(s[i] == 'D'){
            result += 500;
            ++i;
        }
        else if(substring == "CD"){
            result += 400;
            i += 2;
        }
        if(i >= length)
            return result;
        while(s[i] == 'C'){
            result += 100;
            ++i;
        }
        if(i >= length)
            return result;
        
        //Ten
        substring = s.substr(i, 2);
        if(substring == "XC"){
            result += 90;
            i += 2;
        }
        else if(s[i] == 'L'){
            result += 50;
            ++i;
        }
        else if(substring == "XL"){
            result += 40;
            i += 2;
        }
        if(i >= length)
            return result;
        while(s[i] == 'X'){
            result += 10;
            ++i;
        }
        if(i >= length)
            return result;
        
        //One    
        substring = s.substr(i, 2);
        if(substring == "IX"){
            result += 9;
            i += 2;
        }
        else if(s[i] == 'V'){
            result += 5;
            ++i;
        }
        else if(substring == "IV"){
            result += 4;
            i += 2;
        }
        if(i >= length)
            return result;
        while(s[i] == 'I'){
            result += 1;
            ++i;
        }
        return result;
    }

    //[OK] Method 2. 24ms
    int romanToInt(string s){
        int length = s.length();
        if(length == 0){
            return 0;
        }
        int result = 0;
        for(int i = 0; i < length-1; ++i){
            int si = getValue(s[i]);
            int si1 = getValue(s[i+1]);
            if(si < si1){
                result -= si;
            }
            else{
                result += si;
            }
        }
        result += getValue(s[length-1]);
        return result;
    }
    int getValue(char ch){
        switch(ch){
            case 'M':
                return 1000;
            case 'D':
                return 500;
            case 'C':
                return 100;
            case 'L':
                return 50;
            case 'X':
                return 10;
            case 'V':
                return 5;
            case 'I':
                return 1;
            default:
                return 0;
        }
    }
};

int main(void){
    Solution sol;
    int value[] = {100, 1, 101, 1000, 3424, 1111};
    string testStr[] = {"C", "I", "CI", "M", "MMMCDXXIV", "MCXI"};
    for(int i= 0; i < 6; ++i){
        int result = sol.romanToInt(testStr[i]);
        cout << "result: " << result << ", value: " << value[i] << ", " << (result == value[i] ? true : false) << endl;    //NOTE: Here "(", ")" is essential.
    }
}
