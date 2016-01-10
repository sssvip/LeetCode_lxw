// File: num322.cpp
// Author: lxw
// Date: 2015-1-10

/*
Num num322: Coin Change
Source: https://leetcode.com/problems/coin-change/

You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

Example 1:
coins = [1, 2, 5], amount = 11
return 3 (11 = 5 + 5 + 1)

Example 2:
coins = [2], amount = 3
return -1.

Note:
You may assume that you have an infinite number of each kind of coin.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

/*
//Greedy
//CANNOT USE "Greedy" for this question.
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int length = coins.size();
        if(amount == 0)
            return 0;
        else if(length == 0)
            return -1;
            
        sort(coins.begin(), coins.end());
        if(amount < coins[0])
            return -1;
            
        int count = 0;
        for(int i = length-1; i >= 0;){
            if(coins[i] > amount){
                --i;
                continue;
            }
            amount -= coins[i];
            ++count;
            if(amount == 0)
                return count;
            if(amount < 0)
                return -1;
        }
        return -1;
    }
};
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

/*
//DP?
//The size of array depends on the variable "amount". So, this is not a good solution.
//Time Limit Exceed. & Memory Limit Exceed.
class Solution {
public:
	void showVec(queue<int> & q){
	    int length = q.size();
	    if(length < 1)
	    	return;
	   	int num;
	    for(int i = 0; i < length; ++i){
	    	num = q.front();
	        cout << num << ", ";
	        q.pop();
	        q.push(num);
	    }
	    cout << endl;
	}
    int coinChange(vector<int>& coins, int amount) {
        queue<int> states;
        int length = coins.size();
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        if(length == 0)
            return -1;
        
        for(int i = 0; i < length; ++i){
            if(coins[i] == amount)
                return 1;
            states.push(coins[i]);
        }
        states.push(-1);
        int count = 1;
        int state;
        while(1){
            if(states.front() == -1){
            	//showVec(states);
                ++count;
                states.pop();
                states.push(-1);
                if(states.front() == -1)
                    return -1;
            }
            
            for(int i = 0; i < length; ++i){
                state = states.front() + coins[i];
                if(state == amount)
                    return count + 1;   // + coins[i], so count + 1
                else if(state < amount)
                    states.push(state);
            }
            states.pop();
        }
    }
};*/

//DP
//Size of dp: amount + 1.
//dp[i+c] = min{dp[i] + 1, dp[i+c]};
    class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        //dp[i+c] = min{dp[i]+1, dp[i+c]}
        int length = coins.size();
        if(amount == 0)
            return 0;
        if(amount < 0)
            return -1;
        if(length == 0)
            return -1;
        
        vector<int> dp(amount+1, -1);
        dp[0] = 0;
        for(int i = 0; i < amount; ++i){
            for(int c = 0; c < length; ++c){
                int index = i + coins[c];
                if(dp[i] == -1)
                    continue;
                if(index <= amount){
                    if(dp[index] != -1)
                        dp[index] = min(dp[index], dp[i]+1);
                    else
                        dp[index] = dp[i] + 1;
                }
            }
        }
        return dp[amount];
    }
};
int main(void){
	Solution sol;
	vector<int> coins;
	coins.push_back(1);
	coins.push_back(2);
	coins.push_back(5);
	sol.coinChange(coins, 100);
	return 0;
}