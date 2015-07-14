// File: num084.cpp
// Author: lxw
// Date: 2015-07-14

/*
Num num084: Largest Rectangle in Histogram
Source: https://leetcode.com/problems/largest-rectangle-in-histogram/

Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].


The largest rectangle is shown in the shaded area, which has area = 10 unit.

For example,
Given height = [2,1,5,6,2,3],
return 10.
*/

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        stack<int> indexStack;
        height.push_back(0);
        int length = height.size();
        int maxArea = 0;
        for(int i = 0; i < length;){//for(int i = 0; i < length; ++i){
            if(indexStack.empty() || height[i] >= height[indexStack.top()]){
                indexStack.push(i);
                ++i;
            }
            else{
                int index = indexStack.top();
                indexStack.pop();
                //int width = indexStack.empty() ? i : i - index; // not index ~ i but indexStack.top()+1 ~ i
                int width = indexStack.empty() ? i : i - indexStack.top() - 1;
                maxArea = max(maxArea, height[index]*width);
                /*
                //NO, special case [1, 2, 2]
                while(height[i] < height[indexStack.top()]){
                    index = indexStack.top();
                    indexStack.pop();
                    if(indexStack.empty())
                        break;
                }
                int width = indexStack.empty() ? i : i - index;
                maxArea = max(maxArea, height[index]*width);
                indexStack.push(i);
                */
            }
        }
        return maxArea;
    }
};