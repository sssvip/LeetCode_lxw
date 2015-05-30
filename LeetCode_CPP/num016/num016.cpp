// File: num016.cpp
// Author: lxw
// Date: 2015-05-30

/*
Num 016: 3Sum Closest 
Source: https://leetcode.com/problems/3sum-closest/
Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. Return the sum of the three integers. You may assume that each input would have exactly one solution.

    For example, given array S = {-1 2 1 -4}, and target = 1.
    The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

class Solution{
public:
    int threeSumClosest(vector<int>& nums, int target){
        sort(nums.begin(), nums.end());
        int result = nums[0] + nums[1] + nums[2];
        bool flag = false;
        int length = nums.size();
        for(int i = 0; i < length - 2; ++i){
            //cout << "i: "<< i << endl;
            int j = i + 1;
            int k = length - 1;
            while(j < k){
                int sum =  nums[i] + nums[j] + nums[k];
                if(abs(sum - target) < abs(result - target)){
                    result = sum;
                }
                if(sum < target){
                    ++j;
                }
                else if(sum > target){
                    --k;
                }
                else{
                    flag = true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        return result;
    }
};

int main(void)
{
    vector<int> vec;
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(1);
    vec.push_back(0);
    Solution sol;
    cout << sol.threeSumClosest(vec, 100) << endl;
    return 0;
}
