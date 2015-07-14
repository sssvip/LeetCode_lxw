// File: num121.cpp
// Author: lxw
// Date: 2015-07-12

/*
Num num121: Best Time to Buy and Sell Stock
Source: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock), design an algorithm to find the maximum profit.
*/

//当前价格之前的最低价买入,当前价卖是最好的，然后取这些的最大值

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int length = prices.size();
        if(length < 2)
            return 0;
        int minPrice = prices[0];
        int maxProfit = 0;
        for(int i = 1; i < length; ++i){
            minPrice = min(minPrice, prices[i]);
            maxProfit = max(maxProfit, prices[i]-minPrice);
        }
        return maxProfit;
    }
};