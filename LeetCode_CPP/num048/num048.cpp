// File: num048.cpp
// Author: lxw
// Date: 2015-06-26

/*
Num num048: Rotate Image 
Source: https://leetcode.com/problems/rotate-image/

You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;;

class Solution {
private:
	void showVec(vector<int> & vec){
	    int length = vec.size();
	    if(length < 1)
	    	return;
	    for(int i = 0; i < length-1; ++i){
	        cout << vec[i] << ",";
	    }
	    cout << vec[length-1] << endl;
	}	
public:
    void rotate(vector<vector<int>>& matrix) {
        int length = matrix.size();
        int temp = 0;
        int start = 0;
        int end = length - 1;
        while(start < end){
            int inStart = start;
            int inEnd = end;
            while(inStart < inEnd){
                temp = matrix[start][inStart];
                matrix[start][inStart] = matrix[length - 1 - inStart][start];
                matrix[length - 1 - inStart][start] = matrix[length - 1 - start][length - 1 - inStart];
                matrix[length - 1 - start][length - 1 - inStart] = matrix[inStart][end];
                //cout << matrix[start + inStart][end] << endl;
                matrix[inStart][end] = temp;
                ++inStart;
            }
            ++start;
            --end;
        }
    }
    void showVecVec(vector<vector<int>> & vvi){
		int length = vvi.size();
	    if(length < 1)
	    	return;
	    for(int i = 0; i < length; ++i){
	    	showVec(vvi[i]);
	    }
	}
};
int main(void){
	Solution sol;
	vector<int> vec;
	vector<vector<int> > matrix;
	vec.push_back(1);vec.push_back(2);vec.push_back(3);vec.push_back(4);
	matrix.push_back(vec);
	vec.clear();
	vec.push_back(5);vec.push_back(6);vec.push_back(7);vec.push_back(8);
	matrix.push_back(vec);
	vec.clear();
	vec.push_back(9);vec.push_back(10);vec.push_back(11);vec.push_back(12);
	matrix.push_back(vec);
	vec.clear();
	vec.push_back(13);vec.push_back(14);vec.push_back(15);vec.push_back(16);
	matrix.push_back(vec);
	
	sol.showVecVec(matrix);
	cout << endl << endl;
	sol.rotate(matrix);
	sol.showVecVec(matrix);
    return 0;
}
