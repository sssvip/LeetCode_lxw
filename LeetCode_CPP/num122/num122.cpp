// File: num122.cpp
// Author: lxw
// Date: 2015-07-13

/*
Num num122: Best Time to Buy and Sell Stock II
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
*/

//所有的单调递增区间

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if(length < 2)
            return 0;
        int i = 0;
        int start;
        int profit = 0;
        while(i < length){
            start = i;
            while(1){
                if(i == length - 1)
                    break;
                if(prices[i+1] >= prices[i]){
                    ++i;
                }
                else{
                    break;
                }
            }
            profit += prices[i] - prices[start];
            ++i;
        }
        return profit;
    }
};