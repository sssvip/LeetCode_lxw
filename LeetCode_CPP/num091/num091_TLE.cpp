// File: num091_TLE.cpp(Wrong Answer) e.g.: 210
// Author: lxw
// Date: 2015-07-27

/*
Num 091: Decode Ways
Source: https://leetcode.com/problems/decode-ways/ 

A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given an encoded message containing digits, determine the total number of ways to decode it.

For example,
Given encoded message "12", it could be decoded as "AB" (1 2) or "L" (12).

The number of ways decoding "12" is 2.
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
    void numDecodings(string & s, int start, int end, int & count){
        if(start >= end){
            ++count;
            return;
        }
        //"start < end" means "end - start >= 1"
        int ten = s[start] - '0';
        int one = s[start + 1] - '0';
        int number = ten * 10 + one;
        //ten should never be 0.
        //assert ten != 0;
        if(number == 20 || number == 10){
            numDecodings(s, start + 2, end, count);
        }
        else if(number <= 26){
            numDecodings(s, start + 1, end, count);
            numDecodings(s, start + 2, end, count);
        }
        else{
            numDecodings(s, start + 1, end, count);
        }
    }
public:
    int numDecodings(string s) {
        int length = s.length();
        if(length <= 1)
            return length;
        int count = 0;
        numDecodings(s, 0, length-1, count);
        return count;
    }
};

int main(void){
	Solution sol = Solution();
	/*cout << sol.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565") << endl;
     */
	cout << sol.numDecodings("210") << endl;
	return 0;
}
