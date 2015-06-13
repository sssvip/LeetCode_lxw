// File: num033.cpp
// Author: lxw
// Date: 2015-06-13

/*
Num 033: Search in Rotated Sorted Array
Source: https://leetcode.com/problems/search-in-rotated-sorted-array/

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int binSearch(vector<int>& nums, int begin, int end, int target){
        int middle = 0;
        while(begin <= end){
            middle = (begin + end) / 2;
            if(nums[middle] == target){
                return middle;
            }
            else if(nums[middle] > target){
                end = middle - 1;
            }
            else{
                begin = middle + 1;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int length = nums.size();
        if(length < 0){
            return -1;
        }
        if(length == 1){
            return target == nums[0] ? 0 : -1;
        }
        //find the pivot
        int pivot = -1;
        for(int i = 1; i < length; ++i){
            if(nums[i] < nums[0]){
                pivot = i;
                break;
            }
        }
        //cout << pivot << endl;
        if(pivot == -1){
            //binary search in 2 parts
            return binSearch(nums, 0, length-1, target);
        }
        else{
            if(target == nums[0]){
                return 0;
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

int main(void){
    int A[] = {5, 1, 3};
    vector<int> v(A, A+3);
    Solution sol;
    cout << sol.search(v, 1) << endl;
    return 0;
}
