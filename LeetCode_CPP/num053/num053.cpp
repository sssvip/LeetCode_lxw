// File: num053.cpp
// Author: lxw
// Date: 2015-06-28

/*
Num num053: Maximum Subarray
Source: https://leetcode.com/problems/maximum-subarray/

Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
the contiguous subarray [4,−1,2,1] has the largest sum = 6.
*/
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int length = nums.size();
        if(length < 1){
            return INT_MIN;
        }
        else if(length == 1){
            return nums[0];
        }
        
        int sum = 0;
        int max = INT_MIN;
        for(int i = 0; i < length; ++i){
            sum += nums[i];
            if(sum > max){
                max = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        return max;
    }
};