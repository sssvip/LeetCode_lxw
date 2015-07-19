// File: num238.cpp
// Author: lxw
// Date: 2015-07-19

/*
Num num238: Product of Array Except Self
Source: https://leetcode.com/problems/product-of-array-except-self/

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
*/

//维持两个数组, left[] right[].
//分别记录 第i个元素 左边相乘的结果left[i], 右边相乘的结果right[i].
//output[i]即为 left[i] * right[i].
//由于要求O(1)空间. 利用返回的结果数组, 先存right数组. 再从左边计算left, 同时计算结果值, 这样可以不需要额外的空间.

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int length = nums.size();
        if(length == 0)
            return nums;
        vector<int> output(length);
        
        //left
        output[0] = 1;
        for(int i = 1; i < length; ++i){
            output[i] = output[i-1] * nums[i-1];
        }
        //right
        int last = 1;
        for(int i = length-2; i >= 0; --i){
            last *= nums[i+1];
            output[i] *= last;
        }
        return output;
    }
};