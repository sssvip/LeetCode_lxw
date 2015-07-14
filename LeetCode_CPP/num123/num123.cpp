// File: num123.cpp
// Author: lxw
// Date: 2015-07-13

/*
Num num123: Best Time to Buy and Sell Stock III
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete at most two transactions.

Note:
You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

/*
解释：
首先，因为能买2次（第一次的卖可以和第二次的买在同一时间），但第二次的买不能在第一次的卖左边。
所以维护2个表，f1和f2，size都和prices一样大。
意义：
f1[i]表示 -- 截止到i下标为止，左边所做交易能够达到最大profit；
f2[i]表示 -- 截止到i下标为止，右边所做交易能够达到最大profit；
那么，对于f1 + f2，寻求最大即可。
maxProfit = max{f1(i) + f2(i)};
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if(length < 2){
            return 0;
        }
        vector<int> p1(length);
        vector<int> p2(length);
        int minPrice = prices[0];
        int maxPrice = prices[length-1];
        int profit1 = 0;
        int profit2 = 0;
        p1[0] = 0;
        p2[length-1] = 0;
        for(int i = 1; i < length; ++i){
            minPrice = min(minPrice, prices[i]);
            profit1 = max(profit1, prices[i]-minPrice);
            p1[i] = profit1;
            maxPrice = max(maxPrice, prices[length-1-i]);
            profit2 = max(profit2, maxPrice-prices[length-1-i]);
            p2[length-1-i] = profit2;
        }
        int maxProfit = p1[0] + p2[0];
        for(int i = 1; i < length; ++i){
            maxProfit = max(maxProfit, p1[i] + p2[i]);
        }
        return maxProfit;
    }
};