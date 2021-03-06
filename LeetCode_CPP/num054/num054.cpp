// File: num054.cpp
// Author: lxw
// Date: 2015-06-28

/*
Num num054: Spiral Matrix 
Source: https://leetcode.com/problems/spiral-matrix/

Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example,
Given the following matrix:

[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]
You should return [1,2,3,6,9,8,7,4,5].
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

void showVec(vector<int> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ",";
    }
    cout << vec[length-1] << endl;
}

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if(m == 0){
            return result;
        }
        int n = matrix[0].size();
        if(n == 0){
            return result;
        }
        int upBound = 0;
        int downBound = m - 1;
        int leftBound = 0;
        int rightBound = n - 1;
        while(1){
            //right
            for(int i = leftBound; i <= rightBound; ++i){
                result.push_back(matrix[upBound][i]);
            }
            ++upBound;
            if(upBound > downBound)
                break;
            //down
            for(int i = upBound; i <= downBound; ++i){
                result.push_back(matrix[i][rightBound]);
            }
            --rightBound;
            if(rightBound < leftBound)
                break;
            //left
            for(int i = rightBound; i >= leftBound; --i){
                result.push_back(matrix[downBound][i]);
            }
            --downBound;
            if(downBound < upBound)
                break;
            //up
            for(int i = downBound; i >= upBound; --i){
                result.push_back(matrix[i][leftBound]);
            }
            ++leftBound;
            if(leftBound > rightBound)
                break;
        }
        return result;
    }
};
int main(void){
    Solution sol;
	vector<vector<int> > matrix;
    vector<int> vec;
	vec.push_back(2);vec.push_back(5);vec.push_back(8);
	matrix.push_back(vec);
	vec.clear();
	vec.push_back(4);vec.push_back(0);vec.push_back(-1);
	matrix.push_back(vec);
    vector<int> result = sol.spiralOrder(matrix);
    showVec(result);
    return 0;
}
