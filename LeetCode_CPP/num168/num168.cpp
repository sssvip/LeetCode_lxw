// File: num168.cpp
// Author: lxw
// Date: 2015-07-31

/*
Num num168: Excel Sheet Column Title
Source: https://leetcode.com/problems/excel-sheet-column-title/

Given a positive integer, return its corresponding column title as appear in an Excel sheet.

For example:

    1 -> A
    2 -> B
    3 -> C
    ...
    26 -> Z
    27 -> AA
    28 -> AB 
Credits:
Special thanks to @ifanchu for adding this problem and creating all test cases.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

/*
//Method 1: OK
class Solution {
public:
    string convertToTitle(int n) {
        if(n <= 0)
            return "";
        string title = "";
        while(n){
            title.push_back((n - 1) % 26 + 'A');
            n = (n - 1) / 26;
        }
        reverse(title.begin(), title.end());
        return title;
    }
};
*/

//Method 2: OK
class Solution {
public:
    string convertToTitle(int n) {
        if(n <= 0)
            return "";
        string title = "";
        while(n){
            //NO: title = ((n - 1) % 26 + 'A') + title; //NO: int + string
            title = char((n - 1) % 26 + 'A') + title;
            n = (n - 1) / 26;
        }
        //reverse(title.begin(), title.end());
        return title;
    }
};

int main(void){
	Solution sol;
	cout << sol.convertToTitle(26) << endl;
	return 0;
}
