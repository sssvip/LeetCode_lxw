// File: num042_1.cpp
// Author: lxw
// Date: 2015-06-24

/*
Num num042: Trapping Rain Water 
Source: https://leetcode.com/problems/trapping-rain-water/
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, 
Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. 
Thanks Marcos for contributing this image!
*/

#include <iostream>
#include <vector>
using namespace std;

// 时间复杂度O(n)，空间复杂度O(n)
class Solution {
public:
    int trap(vector<int> & vec){
        int length = vec.size();
        vector<int> maxLeft(length, 0);
        vector<int> maxRight(length, 0);
        for(int i = 1; i < length; ++i){
            maxLeft[i] = max(maxLeft[i-1], vec[i-1]);
            //maxRight[length-1-i] = max(maxRight[length-1-i+1], vec[length-1-i+1]);
            maxRight[length-1-i] = max(maxRight[length-i], vec[length-i]);
        }
        int result = 0;
        for(int i = 0; i < length; ++i){
            int lower = min(maxLeft[i], maxRight[i]);
            if(lower > vec[i]){
                result += lower - vec[i];
            }
        }
        return result;
    }
};

int main(void){
	Solution sol;
	vector<int> height;
	height.push_back(5);height.push_back(2);height.push_back(1);height.push_back(2);height.push_back(1);height.push_back(5);
	cout << sol.trap(height) << endl;
	return 0;
}
