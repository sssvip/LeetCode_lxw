// File: num081.cpp
// Author: lxw
// Date: 2015-07-06

/*
Num 081: Search in Rotated Sorted Array II
Source: https://leetcode.com/problems/search-in-rotated-sorted-array-ii/

Follow up for "Search in Rotated Sorted Array":
What if duplicates are allowed?

Would this affect the run-time complexity? How and why?

Write a function to determine if a given target is in the array.
*/
class Solution {
private:
    bool binSearch(vector<int>& nums, int begin, int end, int target){
        int middle = 0;
        while(begin <= end){
            middle = ((long long)begin + (long long)end) / 2;
            if(nums[middle] == target){
                return true;
            }
            else if(nums[middle] < target){
                begin = (long long)middle + (long long)1;
            }
            else{
                end = middle - 1;
            }
        }
        return false;
    }
public:
    bool search(vector<int>& nums, int target) {
        int length = nums.size();
        if(length < 0){
            return false;
        }
        if(length == 1){
            return target == nums[0];
        }
        //find the pivot
        int pivot = -1;
        for(int i = 1; i < length; ++i){
            if(nums[i] < nums[i-1]){    //the difference between num081 and num033.
                pivot = i;
                break;
            }
        }
        if(pivot == -1){
            return binSearch(nums, 0, length-1, target);
        }
        else{
            if(target == nums[0]){
                return true;
            }
            else if(target > nums[0]){
                return binSearch(nums, 0, pivot-1, target);
            }
            else{
                return binSearch(nums, pivot, length-1, target);
            }
        }
    }
};