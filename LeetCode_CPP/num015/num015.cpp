// g++ -std=c++11 num015.cpp
// File: num015.cpp
// Author: lxw
// Date: 2015-05-30

/*
Num 015: 3Sum
Source: https://leetcode.com/problems/3sum/
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
1. Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
2. The solution set must not contain duplicate triplets.
   For example, given array S = {-1 0 1 2 -1 -4},

   A solution set is:
   (-1, 0, 1)
   (-1, -1, 2)
*/

//Main Idea: Squeeze(先排序，再左右夹逼): j++ && k--.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void quickSort(vector<int>& nums, int start, int end){
        int length = end - start + 1;
        if(length < 2)
            return;
        else if(length == 2){
            if(nums[start] > nums[end]){
                int temp = nums[start];
                nums[start] = nums[end];
                nums[end] = temp;
            }
            return;
        }
        int i = start + 1;
        int j = end;
        while(i < j){
            while(nums[i] <= nums[start] && i <= end){
                ++i;
            }
            while(nums[j] > nums[start] && j >= start){
                --j;
            }
            if(i < j){
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }
        int temp = nums[start];
        nums[start] = nums[j];
        nums[j] = temp;
        quickSort(nums, start, j-1);
        quickSort(nums, j+1, end);
    }

    vector<vector<int> > threeSum(vector<int>& nums) {
        int length = nums.size();
        vector<vector<int> > result;
        if(length < 3)
            return result;

        //quickSort(nums, 0, length-1);
        sort(nums.begin(), nums.end());

        for(int i = 0; i < length - 2; ++i){
            int j = i + 1;
            int k = length - 1;
            while(j < k){
                if(nums[i] + nums[j] + nums[k] < 0){
                    ++j;
                }
                else if(nums[i] + nums[j] + nums[k] > 0){
                    --k;
                }
                else{
                    result.push_back({nums[i], nums[j], nums[k]});
                    ++j;
                    --k;
                    while(j < k && nums[j] == nums[j-1]){
                        ++j;
                    }
                    while(j < k && nums[k] == nums[k+1]){
                        --k;
                    }
                }
            }
            while(i < length -2 && nums[i+1] == nums[i]){
                ++i;
            }
        }
        return result;
    }
};

int main(void){
    vector<int> vec;
    vec.push_back(-1);
    vec.push_back(0);
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(-1);
    vec.push_back(-4);
    Solution sol;
    vector<vector<int> > result = sol.threeSum(vec);
    for(int j = 0; j < result.size(); ++j){
        for(int i = 0; i < result[j].size(); ++i){
            cout << result[j][i] << "\t";
        }
        cout << endl;
    }  
    
    return 0;
}
