// File: num279.cpp
// Author: lxw
// Date: 2015-09-16

/*
Num num279: Perfect Squares
Source: https://leetcode.com/problems/perfect-squares/

Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.

For example, given n = 12, return 3 because 12 = 4 + 4 + 4; given n = 13, return 2 because 13 = 4 + 9.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/*
//不能用贪心
NO:  19 = 16 + 1 + 1 + 1
YES: 19 = 9 + 9 + 1      
*/
//DP
//380ms
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 1; i * i <= n; ++i)
            dp[i*i] = 1;
        for(int i = 1; i <= n; ++i){
            for(int j = 1; i + j * j <= n; ++j){
                if(dp[i+j*j] == 0 || dp[i+j*j] > dp[i] + 1){
                    dp[i+j*j] = dp[i] + 1;
                }
            }
        }
        return dp[n];
    }
};

/*
//DP
//544 ms
//不好理解
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, 0);
        for(int i = 1; i <= n; ++i){
            dp[i] = i;
            for(int j = 1; j * j <= i; ++j){
                dp[i] = min(1+dp[i-j*j], dp[i]);
            }
        }
        return dp[n];
    }
};
*/