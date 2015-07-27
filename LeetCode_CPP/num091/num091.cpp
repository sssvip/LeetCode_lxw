// File: num091.cpp
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

每次对于当前的字符判断是否属于1-9（0肯定不行，因为0不在1-26中），如果属于，那么当前的字符可以被decode，并且和f[n-1]组合，f[n] += f[n-1]
然后对于当前字符和前一个字符组成的字符串判断是否属于10-26，如果属于，那么这两个字符可以被decode，并且和f[n-2]组合，f[n] += f[n-2]
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if(length == 0)
            return 0;
        vector<int> dp(length, 0);
        if(s[0] >= '1' && s[0] <= '9')
            dp[0] = 1;
        int ten, one, num;
        for(int i = 1; i < length; ++i){
            ten = s[i-1] - '0';
            one = s[i] - '0';
            num = ten * 10 + one;
            //和前一个一起
            if(num >= 10 && num <= 26){
                if(i > 1)
                    dp[i] = dp[i-2];
                else
                    dp[i] = 1;
            }
            //自己单独
            if(one >= 1 && one <= 9){
                dp[i] += dp[i-1];   //NOTE: Neither "dp[i] += 1;" NOR "dp[i] = dp[i-1];"
            }
        }
        return dp[length-1];
    }
};

//OR

class Solution {
public:
    int numDecodings(string s) {
        int length = s.length();
        if(length == 0)
            return 0;
        vector<int> dp(length, 0);
        if(s[0] >= '1' && s[0] <= '9')
            dp[0] = 1;
        int ten, one, num;
        for(int i = 1; i < length; ++i){
            ten = s[i-1] - '0';
            one = s[i] - '0';
            num = ten * 10 + one;
            //自己单独
            if(one >= 1 && one <= 9){
                dp[i] = dp[i-1];
            }
            //和前一个一起
            if(num >= 10 && num <= 26){
                if(i > 1)
                    dp[i] += dp[i-2];
                else
                    dp[i] += 1;
            }            
        }
        return dp[length-1];
    }
};

int main(void){
    Solution sol = Solution();
    //cout << sol.numDecodings("1787897759966261825913315262377298132516969578441236833255596967132573482281598412163216914566534565") << endl;
    cout << sol.numDecodings("210") << endl;  //1
    //cout << sol.numDecodings("0125234234") << endl; //0
    cout << sol.numDecodings("100") << endl; //0
    return 0;
}
