// File: num077.cpp
// Author: lxw
// Date: 2015-07-04

/*
Num 077: Combinations
Source: https://leetcode.com/problems/combinations/

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
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
        cout << vec[i] << ", ";
    }
    cout << vec[length-1] << endl;
}
void showVecVec(vector<vector<int>> & vvi){
    int length = vvi.size();
    if(length < 1)
        return;
    for(int i = 0; i < length; ++i){
        showVec(vvi[i]);
    }
}
class Solution {
private:
    vector<vector<int> > vvi;
    void combine(vector<int> & vi, int start, int end, int count){
        if(count == 0){
            this->vvi.push_back(vi);
            return;
        }
        if(start > end){
            return;
        }
        for(int i = start; i <= end-count+1; ++i){
            vi.push_back(i);
            combine(vi, i+1, end, count-1);
            vi.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> vi;
        combine(vi, 1, n, k);
        return this->vvi;
    }
};
 
int main(void){
	Solution sol;
	vector<vector<int> > vvi = sol.combine(2, 1);
	showVecVec(vvi);
    return 0;
}