// File: num118.cpp
// Author: lxw
// Date: 2015-07-10

/*
Num num118: Pascal's Triangle
Source: https://leetcode.com/problems/pascals-triangle/

Given numRows, generate the first numRows of Pascal's triangle.

For example, given numRows = 5,
Return

[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]
*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > vvi;
        if(numRows == 0)
            return vvi;
        vector<int> vi(1, 1);
        vvi.push_back(vi);
        if(numRows == 1){
            return vvi;
        }
        for(int i = 2; i <= numRows; ++i){
            vi.resize(i);
            vi[0] = vi[i-1] = 1;
            int bound = (i - 1) >> 1;
            for(int j = 1; j <= bound; ++j){
                vi[j] = vi[i-1-j] = vvi[i-2][j-1] + vvi[i-2][j];
            }
            vvi.push_back(vi);
        }
        return vvi;
    }
};