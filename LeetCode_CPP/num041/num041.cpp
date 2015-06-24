// File: num041.cpp
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


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //in-place
    int firstMissingPositive(vector<int>& nums){
        int length = nums.size();
        for(int i = 0; i < length; ++i){
        	//cout << i << "\t";
        	if(nums[i] > 0 && nums[i] <= length && nums[nums[i]-1] != nums[i]){
        		int temp = nums[nums[i]-1];
        		nums[nums[i]-1] = nums[i];
        		nums[i] = temp;
        		/*
        		//NOTE: trips and pitfalls
        		int temp = nums[i];
        		nums[i] = nums[nums[i]-1];	//NOTE: this is a really bad expression.
        		//nums[nums[i]-1] = temp;	//NOTE: nums[i] has been modified.
        		nums[temp-1] = temp;
        		*/
        		--i;
        	}
        }
        for(int i = 0; i < length; ++i){
            if(nums[i] != i+1)
                return i+1;
        }
        return length+1;
    }
};
int main(void){
	vector<int> vec;
	vec.push_back(2);vec.push_back(1);
	Solution sol;
	sol.firstMissingPositive(vec);
	return 0;
}