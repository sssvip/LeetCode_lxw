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
#include <vector>
using namespace std;

class Solution {
public:
    //Better
    void dfs1(string & digits, int start, int end, vector<string> & result, string & prefix){
        string digStr = this->vec[digits[start]-'0'];
        int length = digStr.length();
        if(start == end){
            for(int i = 0; i < length; ++i){
                result.push_back(prefix + digStr[i]); 
            }
        }
        else{
            for(int i = 0; i < length; ++i){
                prefix.push_back(digStr[i]);  //OK
                dfs1(digits, start + 1, end, result, prefix);
                prefix.pop_back();
            }
        }
    }

    //OK
    void dfs(string & digits, int start, int end, vector<string> & result, string prefix){
        string digStr = this->vec[digits[start]-'0'];
        int length = digStr.length();
        if(start == end){
            for(int i = 0; i < length; ++i){
                result.push_back(prefix + digStr[i]); 
            }
        }
        else{
            for(int i = 0; i < length; ++i){
                dfs(digits, start + 1, end, result, prefix+digStr[i]);
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> result;
        int length = digits.length();
        if(length < 1){
            return result;
        }
        string prefix = "";
        dfs1(digits, 0, length - 1, result, prefix); // Better
        dfs(digits, 0, length - 1, result, "");  // OK
        return result;
    }
private:
    vector<string> vec = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};

int main(void)
{
    Solution sol;
    vector<string> result = sol.letterCombinations("29");
    int length = result.size();
    for(int i = 0; i < length; ++i){
        cout << result[i] << endl;
    }
    return 0;
}
