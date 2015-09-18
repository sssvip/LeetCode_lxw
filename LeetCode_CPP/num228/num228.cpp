// File: num228.cpp
// Author: lxw
// Date: 2015-09-18

/*
Num 228: Summary Ranges
Source: https://leetcode.com/problems/summary-ranges/

Given a sorted integer array without duplicates, return the summary of its ranges.

For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

void showVecInt(vector<int> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ", ";
    }
    cout << vec[length-1] << endl;
}

void showVecStr(vector<string> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ", ";
    }
    cout << vec[length-1] << endl;
}

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int length = nums.size();
        vector<string> result;
        if(length == 0)
            return result;
        int start;        
        for(int i = 0; i < length; ++i){
            start = i;
            while(i < length-1 && nums[i+1] == nums[i]+1)
                ++i;
            if(start == i){
            	stringstream temp;
            	temp << nums[start];
                result.push_back(temp.str());
            }
            else{
            	stringstream temp;
            	temp << nums[start];
            	temp << "->";
            	temp << nums[i];
                result.push_back(temp.str());
            }
        }
        return result;
    }
};

int main(void){
    vector<int> vec;
	vec.push_back(0); vec.push_back(1); vec.push_back(2); vec.push_back(4); vec.push_back(5); vec.push_back(7);
    showVecInt(vec);
    Solution sol;
    vector<string> vs = sol.summaryRanges(vec);
    showVecStr(vs);
    return 0;
}