// File: num085.cpp
// Author: lxw
// Date: 2015-07-15

/*
Num num085: Maximal Rectangle
Source: https://leetcode.com/problems/maximal-rectangle/

Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing all ones and return its area.
*/

//Reference: http://blog.csdn.net/doc_sgl/article/details/11832965 直接看代码和图
class Solution {
private:
    int largestRectangleArea(vector<int>& height) {
        stack<int> indexStack;
        height.push_back(0);
        int length = height.size();
        int maxArea = 0;
        for(int i = 0; i < length;){
            if(indexStack.empty() || height[i] >= height[indexStack.top()]){
                indexStack.push(i);
                ++i;
            }
            else{
                int index = indexStack.top();
                indexStack.pop();
                int width = indexStack.empty() ? i : i - indexStack.top() - 1;
                maxArea = max(maxArea, height[index]*width);
            }
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int rows = matrix.size();
        if(rows == 0)
            return 0;
        int cols = matrix[0].size();
        if(cols == 0)
            return 0;
        vector<vector<int> > vvi(rows, vector<int>(cols+1, 0));
        for(int j = 0; j < cols; ++j){
            if(matrix[0][j] == '1')
                vvi[0][j] = 1;
        }
        for(int i = 1; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                if(matrix[i][j] == '1')
                    vvi[i][j] = vvi[i-1][j] + 1;
            }
        }
        
        int maxArea = 0;
        int temp = 0;
        for(int i = 0; i < rows; ++i){
            temp = largestRectangleArea(vvi[i]);
            if(temp > maxArea)
                maxArea = temp;
        }
        return maxArea;
    }
};