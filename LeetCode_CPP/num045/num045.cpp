// File: num045.cpp
// Author: lxw
// Date: 2015-06-26

/*
Num num045: Jump Game II 
Source: https://leetcode.com/problems/jump-game-ii/

Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Your goal is to reach the last index in the minimum number of jumps.

For example:
Given array A = [2,3,1,1,4]

The minimum number of jumps to reach the last index is 2. (Jump 1 step from index 0 to 1, then 3 steps to the last index.)
*/

#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int jump(vector<int>& nums) {
        int length = nums.size();
        if(length < 2)
            return 0;
        int result = 0;
        int i = 0;
        while(i < length){
        	++result;
            int step = nums[i];
            if(i + step >= length-1){
                break;
            }
            int index = -1;
            int max = -1;
            int j = 0;
            while(j < step){
                int tempIndex = i + j + 1;
                if(nums[tempIndex] + tempIndex > max + index ){
                    max = nums[tempIndex];
                    index = tempIndex;
                }
                ++j;
            }
            i = index;            
        }
        return result;
    }
};

int main(void){
	Solution sol;
	vector<int> vec;
	vec.push_back(2);vec.push_back(3);vec.push_back(1);vec.push_back(1);vec.push_back(4);
	cout << sol.jump(vec) << endl;
	return 0;
}