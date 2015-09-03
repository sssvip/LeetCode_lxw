// File: num273.cpp
// Author: lxw
// Date: 2015-09-03

/*
Num num273: Integer to English Words
Source: https://leetcode.com/problems/integer-to-english-words/

Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

For example,
123 -> "One Hundred Twenty Three"
12345 -> "Twelve Thousand Three Hundred Forty Five"
1234567 -> "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"
Hint:

Did you see a pattern in dividing the number into chunk of words? For example, 123 and 123000.
Group the number by thousands (3 digits). You can write a helper function that takes a number less than 1000 and convert just that chunk to words.
There are many edge cases. What are some good test cases? Does your code work with input such as 0? Or 1000010? (middle chunk is zero and should not be printed out)
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class Solution {
private:
    string threeDigits(int num){
        if(num == 0)
            return "";
        string num10to20[] = {"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};   //10
        string tens[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}; //10
        string ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"}; //10
        string result = "";
        int hundred = num / 100;
        if(hundred != 0){
            result += ones[hundred] + " Hundred";
        }
        num = num % 100;
        if(num < 20){
            if(num < 10){
                if(num != 0 && hundred != 0)
                    result += " ";
                result += ones[num];
            }
            else{
                if(hundred != 0)
                    result += " ";
                result += num10to20[num-10];
            }
        }
        else{   //num >= 20
            if(hundred != 0)
                result += " ";
            int ten = num / 10;
            result += tens[ten];
            int one = num % 10;
            if(one != 0)
                result += " " + ones[one];
        }
        return result;
    }
public:
    string numberToWords(int num) {
        if(num < 0)
            return "";
        if(num == 0)
            return "Zero";
        int billion = 0;
        int million = 0;
        int thousand = 0;
        int one = 0;
        string result = "";
        billion = num / 1000000000;
        num = num % 1000000000;
        million = num / 1000000;
        num = num % 1000000;
        thousand = num / 1000;
        one = num % 1000;
        string bil = threeDigits(billion);
        if(bil != ""){
            result += bil + " Billion";
        }
        string mil = threeDigits(million);
        if(mil != ""){
            if(result != "")
                result += " ";
            result += mil + " Million";
        }
        string th = threeDigits(thousand);
        if(th != ""){
            if(result != "")
                result += " ";
            result += th + " Thousand";
        }
        string one1 = threeDigits(one);
        if(one1 != ""){
            if(result != "")
                result += " ";
            result += one1;
        }
        return result;
    }
};

int main(void){
	Solution sol;
	cout << sol.numberToWords(123) << endl;
	return 0;
}
