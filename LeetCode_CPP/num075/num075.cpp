// File: num075.cpp
// Author: lxw
// Date: 2015-07-04

/*
Num num075: Sort Colors
Source: https://leetcode.com/problems/sort-colors/

Given an array with n objects colored red, white or blue, sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.

Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.

Note:
You are not suppose to use the library's sort function for this problem.

click to show follow up.

Follow up:
A rather straight forward solution is a two-pass algorithm using counting sort.
First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.

Could you come up with an one-pass algorithm using only constant space?
*/
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int length = nums.size();
        if(length < 1)
            return;
        int index0 = 0;
        int index2 = length - 1;
        for(int i = 0; i <= index2; ++i){
            switch(nums[i]){
                case 0:
                {
                    nums[index0] = 0;
                    ++index0;
                    break;
                }
                case 1:
                    break;
                case 2:
                {
                    nums[i] = nums[index2];
                    nums[index2] = 2;
                    --index2;
                    --i;
                    break;
                }
            }
        }
        for(int i = index0; i <= index2; ++i){
            nums[i] = 1;
        }
    }
};