// File: num220.cpp
// Author: lxw
// Date: 2015-07-26

/*
Num num220: Contains Duplicate III
Source: https://leetcode.com/problems/contains-duplicate-iii/

Given an array of integers, find out whether there are two distinct indices i and j in the array such that the difference between nums[i] and nums[j] is at most t and the difference between i and j is at most k.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class Solution {
public:
    void showVec(vector<int> & vec){
        int length = vec.size();
        if(length < 1)
            return;
        for(int i = 0; i < length-1; ++i){
            cout << vec[i] << ", ";
        }
        cout << vec[length-1] << endl;
    }
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(k == 0)
            return false;
        int length = nums.size();
        //if(length == 1)
        //    return false;
        int i = 0;
        int bound = min(length, k + 1);
        vector<int> temp(nums.begin(), nums.begin()+bound);
        sort(temp.begin(), temp.end());
        int j = 0;
        for(; j < k && j < length - 1; ++j){
            if(temp[j+1] - temp[j] <= t){
                return true;
            }
        }
        if(j == length - 1)
            return false;
        ++i;
        while(i < length - k){
            vector<int> temp(nums.begin()+i, nums.begin()+i+k+1);
            sort(temp.begin(), temp.end());
            //showVec(temp);
            for(int m = 0; m < k; ++m){
                if(temp[m+1] - temp[m] <= t){
                    //cout << "no" << endl;
                    //cout << i+m+1 << "," << temp[i+m+1] << endl;
                    //cout << i+m << "," << temp[i+m] << endl;
                    return true;
                }
            }
            ++i;
        }
        return false;
    }
};

int main(void){
    Solution sol = Solution();
    //vector
    vector<int> vec;
    //vec.push_back(10); vec.push_back(100); vec.push_back(11); vec.push_back(9);
    vec.push_back(1); vec.push_back(3); vec.push_back(1);
    sol.showVec(vec);    
    cout << sol.containsNearbyAlmostDuplicate(vec, 1, 1) << endl;
    return 0;
}
