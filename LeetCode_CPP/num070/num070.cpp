// File: num070.cpp
// Author: lxw
// Date: 2015-07-03

/*
Num 070: Climbing Stairs
Source: https://leetcode.com/problems/climbing-stairs/

You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        if(n < 3){
            return n;
        }
        int prev2 = 1;
        int prev1 = 2;
        int result = 0;
        for(int i = 3; i <= n; ++i){
            result = prev2 + prev1;
            prev2 = prev1;
            prev1 = result;
        }
        return result;
    }
};