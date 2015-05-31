// File: num017.cpp
// Author: lxw
// Date: 2015-05-31

/*
Num 017: Letter Combinations of a Phone Number
Source: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters is just like that on the telephone buttons.

Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.

*/

#include <iostream>
using namespace std;

int main(void)
{
    string str = "hello";
    cout << &str << ", " << str << endl;
    str[1] = 'a';
    cout << &str << ", " << str << endl;
    return 0;
}
