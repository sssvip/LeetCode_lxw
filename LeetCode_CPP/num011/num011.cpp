// File: num011.cpp
// Author: lxw
// Date: 2015-05-23

/*
Num 011: Container With Most Water
Source:https://github.com/lxw0109/LeetCode_lxw/blob/master/

Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container.
*/
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    /*
    NO COMPLIE FOR THIS BLOCK.
    O(n^2) Time Limit Exceeded.*/
    int maxArea1(vector<int>& height) {
        int maxArea = 0;
        int tempArea = 0;
        int size = height.size();
        for(int i = 0; i < size; ++i){
            for(int j = i+1; j < size; ++j){
                tempArea = min(height[i], height[j]) * (j - i);
                if(tempArea > maxArea){
                    maxArea = tempArea;
                }
            }
        }
        return maxArea;
    }
    int maxArea(vector<int>& height) {
        int size = height.size();
        int left = 0;
        int right = size - 1;
        int maxArea = 0;
        int tempArea = 0;
        while(left < right){
            if(height[left] < height[right]){
                tempArea = (right - left) * height[left];
                ++left;
            }
            else{
                tempArea = (right - left) * height[right];
                --right;
            }
            if(tempArea > maxArea){
                maxArea = tempArea;
            }
        }
        return maxArea;
    }
};

int main(void){
	Solution sol;
	vector<int> vec;
	for(int i = 0; i < 100; ++i){
		vec.push_back(i * 2 + 1);
	}
	for(int i = 0; i < 100; ++i){
		cout << vec[i] << "\t";
	}
	cout << endl;
    //vector<int> vec1 = vector<int>(vec.begin()+1, vec.begin()+3);     //Slice of vector. [OK]
	cout << sol.maxArea(vec) << endl;
	cout << sol.maxArea1(vec) << endl;
	return 0;
}
