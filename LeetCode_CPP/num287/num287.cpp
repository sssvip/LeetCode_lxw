// File: num287.cpp
// Author: lxw
// Date: 2015-10-09

/*
Num num287: Find the Duplicate Number
Source: https://leetcode.com/problems/find-the-duplicate-number/

Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Note:
You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

//Method 2:
//二分查找, 1..10, 小于等于5(1+(10-1)/2)的一定有5个,如果多于5个,就在lower part, 等于5个就是upper part. 
class Solution {
private:
    int getCount(vector<int>& nums, int target, int length){
        int count = 0;
        for(int i = 0; i < length; ++i){
            if(nums[i] <= target)
                ++count;
        }
        return count;
    }
public:
    int findDuplicate(vector<int>& nums) {
        int length = nums.size();
        if(length < 3)
            return 1;
        int low = 1;
        int high = length - 1;
        int mid = 0;
        while(low < high){
            mid = low + ((high - low) >> 1);
            if(getCount(nums, mid, length) > mid)
                high = mid;
            else
                low = mid + 1;
        }
        return low;
    }
};

/*
//Method 1:
//想出来了这种方法,但不能证明是对的!
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int length = nums.size();
        if(length < 3)
            return 1;
        int temp;
        for(int i = 0; i < length; ++i){
            while(nums[i] != i+1){
                 if(nums[i] == nums[nums[i]-1]){
                     return nums[i];
                 }
                 temp = nums[i];
                 nums[i] = nums[temp-1];
                 nums[temp-1] = temp;
            }
        }
    }
};
*/