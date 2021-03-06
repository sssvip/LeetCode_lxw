// File: num042.cpp
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

class Solution {
public:
	// 时间复杂度O(n)，空间复杂度O(1)
    int trap(vector<int> & vec){
        int length = vec.size();
        if(length < 1){
        	return 0;
        }
        //NOTE: Do you know why we need to find the maxIndex?
        int max = vec[0];
        int maxIndex = 0;
        for(int i = 1; i < length; ++i){
        	if(vec[i] > max){
        		max = vec[i];
        		maxIndex = i;
        	}
        }
        int result = 0;
        int peak = 0;
        //from left(0) to maxIndex
        for(int i = 0; i < maxIndex; ++i){
        	if(vec[i] > peak){
        		peak = vec[i];
        	}
        	else{
        		result += peak - vec[i];
        	}
        }        
        peak = 0;
        //from right(length-1) to maxIndex
        for(int i = length-1; i > maxIndex; --i){
        	if(vec[i] > peak){
        		peak = vec[i];
        	}
        	else{
        		result += peak - vec[i];
        	}
        }        
        return result;
    }
};

int main(void){
	Solution sol;
	vector<int> height;
	height.push_back(0);height.push_back(2);height.push_back(0);
	cout << sol.trap(height) << endl;
	return 0;
}
