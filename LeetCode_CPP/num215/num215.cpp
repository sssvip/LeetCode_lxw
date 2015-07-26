// File: num215.cpp
// Author: lxw
// Date: 2015-07-26

/*
Num num215: Kth Largest Element in an Array
Source: 

Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

For example,
Given [3,2,1,5,6,4] and k = 2, return 5.

Note: 
You may assume k is always valid, 1 ≤ k ≤ array's length.

Credits:
Special thanks to @mithmatt for adding this problem and creating all test cases.
*/

//Quick Sort(Divide and Conquer)
class Solution {
private:
    int findKthLargest(vector<int> & nums, int k, int start, int end){
        int left = start + 1;
        int temp = 0;
        int right = end;
        while(left <= right){
            while(left <= right && nums[left] <= nums[start])
                ++left;
            while(right >= left && nums[right] > nums[start])
                --right;
            if(left < right){   //no need: left <= right
                temp = nums[left];
                nums[left] = nums[right];
                nums[right] = temp;
            }
        }
        temp = nums[right];
        nums[right] = nums[start];
        nums[start] = temp;
        if(end-right+1 == k)
            return nums[right];
        else if(end-right+1 > k)
            return findKthLargest(nums, k, right+1, end);
        else
            return findKthLargest(nums, k-end+right-1, start, right-1);
    }
public:
    int findKthLargest(vector<int>& nums, int k) {
        return findKthLargest(nums, k, 0, nums.size() - 1);
    }
};


//Heap
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(), nums.end());
        for(int i = 0; i < k-1; ++i){
            pop_heap(nums.begin(), nums.end());
            nums.pop_back();
        }
        pop_heap(nums.begin(), nums.end());
        return nums.back();
    }
};