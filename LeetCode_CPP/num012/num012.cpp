// File: num012.cpp
// Author: lxw
// Date: 2015-05-24

/*
Num 012: Integer to Roman
Source: https://leetcode.com/problems/integer-to-roman/

Given an integer, convert it to a roman numeral.
Input is guaranteed to be within the range from 1 to 3999.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    //[OK]Method 1: 32ms
    string intToRoman1(int num) {
        string symbol[][10] = {
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},   //1-9
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}, //10-90
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}, //100-900
            {"", "M", "MM", "MMM"}  //1000-3000
        };
        int index = 0;
        string retStr = "";
        while(num != 0){
            int curBit = num % 10;
            retStr = symbol[index][curBit] + retStr;
            ++index;
            num /= 10;
        }
        return retStr;
    }

    //[OK]Method 2: 24ms
    string intToRoman2(int num){
        string symbol[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        int intValue[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string retStr = ""; 
        int arrLength = sizeof(symbol) / sizeof(symbol[0]);
        for(int i = 0; i < arrLength; ++i){
            while(num >= intValue[i]){  //NOTE: ">=" instead of ">"
                num = num - intValue[i];
                retStr += symbol[i];
            }   
            if(num == 0){ 
                break;
            }   
        }   
        return retStr;
    }

    //[OK]Method 3: 24ms
    string intToRoman(int num){
         //Thousand
         int thousand = num / 1000;
         string result = "";
         for(int i = 0; i < thousand; ++i){
             result += "M";
         }
         //Hundred 
         int hundred = (num % 1000) / 100;
         result += getSymbol(hundred, "M", "D", "C");
         //Ten
         int ten = (num % 100) / 10;
         result += getSymbol(ten, "C", "L", "X");
         //One
         int one = num % 10;
         result += getSymbol(one, "X", "V", "I");
         return result;
    }           
     
    string getSymbol(int num, string a, string b, string c){
        switch(num){
            case 9:
                return c + a;
            case 8:
                return b + c + c + c;
            case 7:
                return b + c + c;
            case 6:
                return b + c;
            case 5:
                return b;
            case 4:
                return c + b;
            case 3:
                return c + c + c;
            case 2:
                return c + c;
            case 1:
                return c;
            default:
                return ""; 
        }   
    }
};

int main(int argc, const char * argv[])
{
    Solution sol;
    int intArr[] = {100, 1, 101, 1000, 3424, 1111, 9};
    for(int i = 0; i < 7; ++i){
        cout << intArr[i] << ": " << sol.intToRoman(intArr[i]) << endl;
    }
    return 0;
}
