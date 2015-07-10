// File: num119.cpp
// Author: lxw
// Date: 2015-07-10

/*
Num num119: Pascal's Triangle II 
Source: https://leetcode.com/problems/pascals-triangle-ii/

Given an index k, return the kth row of the Pascal's triangle.

For example, given k = 3,
Return [1,3,3,1].

Note:
Could you optimize your algorithm to use only O(k) extra space?
*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vec1(rowIndex + 1);
        vec1[0] = 1;
        if(rowIndex == 0)
            return vec1;
        vector<int> vec2(rowIndex + 1);
        vec2[0] = 1;
        for(int i = 1; i <= rowIndex; ++i){
            int bound = i >> 1;
            vec2[i] = 1;
            for(int j = 1; j <= bound; ++j){
                vec2[j] = vec2[i-j] = vec1[j-1] + vec1[j];
            }
            for(int j = 1; j <= i; ++j){
                vec1[j] = vec2[j];
            }
        }
        return vec1;
    }
};