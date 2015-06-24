// File: num041_1.cpp
// Author: lxw
// Date: 2015-06-24

/*
Num num041: First Missing Positive
Source: https://leetcode.com/problems/first-missing-positive/
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space.
*/

//myself
class Solution {
public:
    //in-place
    int firstMissingPositive(vector<int>& nums){
        int length = nums.size();
        for(int i = 0; i < length; ++i){
            if(nums[i] > 0){
                if(nums[i] < i+1){
                    nums[nums[i]-1] = nums[i];
                }
                else if(nums[i] > i+1 && nums[i] <= length){
                    int temp = nums[nums[i]-1];
                    if(temp != nums[i]){
                        nums[nums[i]-1] = nums[i];
                        nums[i] = temp;
                        --i;
                    }
                }
            }
        }
        for(int i = 0; i < length; ++i){
            if(nums[i] != i+1)
                return i+1;
        }
        return length+1;
    }
};
