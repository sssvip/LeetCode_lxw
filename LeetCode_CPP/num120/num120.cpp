// File: num120.cpp
// Author: lxw
// Date: 2015-07-11

/*
Num num120: Triangle
Source: https://leetcode.com/problems/triangle/

Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
     [2],
    [3,4],
   [6,5,7],
  [4,1,8,3]
]
The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note:
Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/

/*
n: row number;   j: column number;
f(n, j) = min(f(n-1, j-1), f(n-1, j)) + rowArr[j];
j == 0:   f(n, j) = f(n-1, j) + rowArr[j];
j == n(上一行中,超出数组范围):  f(n, j) = f(n-1, j-1) + rowArr[j];
*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int rowCount = triangle.size();
        if(rowCount < 1)
            return 0;
        if(rowCount == 1)
            return triangle[0].size() == 1 ? triangle[0][0] : 0;
        vector<int> lastRow(rowCount);
        vector<int> currentRow(rowCount);
        //i == 0;
        lastRow[0] = triangle[0][0];
        //i == (1 ~ rowCount-2);
        for(int i = 1; i < rowCount-1; ++i){
            currentRow[0] = lastRow[0] + triangle[i][0];
            for(int j = 1; j < i; ++j){
                currentRow[j] = min(lastRow[j-1], lastRow[j]) + triangle[i][j];
            }
            currentRow[i] = lastRow[i-1] + triangle[i][i];
            for(int j = 0; j <= i; ++j){
                lastRow[j] = currentRow[j];
            }
        }
        //i == rowCount - 1;
        int minElement = lastRow[0] + triangle[rowCount-1][0];
        int tempMin;
        for(int j = 1; j < rowCount-1; ++j){
            tempMin = min(lastRow[j-1], lastRow[j]) + triangle[rowCount-1][j];
            if(tempMin < minElement)
                minElement = tempMin;
        }
        tempMin = lastRow[rowCount-2] + triangle[rowCount-1][rowCount-1];
        return tempMin < minElement ? tempMin : minElement;
    }
};