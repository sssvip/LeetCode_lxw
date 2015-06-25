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
    int trap(vector<int>& height) {
        int result = 0;
        int length = height.size();
        
        int j;
        int k;
        for(j = 0; j < length-1; ++j){
            if(height[j] <= height[j+1]){
                continue;
            }
            else{
                break;
            }
        }
        //cout << "j: " << j << endl;
        bool flag = true;
        vector<int> block;
        int realBlock = 0;
        for(k = j+1; k < length; ++k){
            if(flag && height[k] <= height[k-1]){   //decrease
                block.push_back(height[k]);
                continue;
            }
            if(!flag && height[k] >= height[k-1]){   //increase
                block.push_back(height[k]);
                continue;
            }
            if(flag && height[k] > height[k-1]){    //lowest point
                flag = false;
                block.push_back(height[k]);
                continue;
            }
            else{
                int lower = min(height[j], height[k-1]);
                int size = block.size();
                int i = 0;
                for(; i < size; ++i){
                    if(block[i] < lower){
                        break;
                    }
                }
                int index = i;
                realBlock = 0;
                for(; i < size-1; ++i){
                    realBlock += block[i];
                }
                result += lower * (k-index-1) - realBlock;
                flag = true;
                block.clear();
                --k;
                j = k;
            }
        }
        cout << "flag: " << flag << ", j: " << j << ", k-1: " << k-1 << ", result: " << result << ", realBlock: " << realBlock << endl;
        cout << "------------------" << endl;
        if(!flag){
            int lower = min(height[j], height[k-1]);
            int size = block.size();
            int i = 0;
            for(; i < size; ++i){
                if(block[i] < lower){
                    break;
                }
            }
            int index = i + 1;
            int realBlock = 0;
            for(; i < size-1; ++i){
                realBlock += block[i];
            }
            result += lower * (k-index-1) - realBlock;    //(k-1-j-1)
            cout << "i: " << i << ", realBlock: " << realBlock << ", result: " << result << endl;
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
