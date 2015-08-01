// File: num097.cpp
// Author: lxw
// Date: 2015-08-01

/*
Num 097: Interleaving String
Source: https://leetcode.com/problems/interleaving-string/

Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

For example,
Given:
s1 = "aabcc",
s2 = "dbbca",

When s3 = "aadbbcbcac", return true.
When s3 = "aadbbbaccc", return false.
*/

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.length();
        int len2 = s2.length();
        int len3 = s3.length();
        if(len1 + len2 != len3)
            return false;
        if(len1 == 0)
            return s2 == s3;
        if(len2 == 0)
            return s1 == s3;
            
        vector<vector<bool> > dp(len1+1, vector<bool>(len2+1, 0));
        for(int i = 1; i <= len1; ++i){
            dp[i][0] = s1[i-1] == s3[i-1];
            if(!dp[i][0])
                break;
        }
        for(int j = 1; j <= len2; ++j){
            dp[0][j] = s2[j-1] == s3[j-1];
            if(!dp[0][j])
                break;
        }
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                dp[i][j] = (dp[i-1][j] && (s1[i-1] == s3[i+j-1])) || (dp[i][j-1] && (s2[j-1] == s3[i+j-1]));
            }
        }
        return dp[len1][len2];
    }
};