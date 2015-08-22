// File: num260.cpp
// Author: lxw
// Date: 2015-08-22

/*
Num num260: Single Number III
Source: https://leetcode.com/problems/single-number-iii/

Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.

For example:

Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
The order of the result is not important. So in the above example, [5, 3] is also correct.
Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;


void showVec(const vector<int> & vec){
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
    vector<int> singleNumber(vector<int>& nums) {
        int length = nums.size();
        int twoXOR = 0;
        for(int i = 0; i < length; ++i){
            twoXOR ^= nums[i];
        }
        vector<int> nums1;
        vector<int> nums2;
        for(int i = 0; i < 32; ++i){
            if((twoXOR >> i)&0x01 == 1){
                for(int j = 0; j < length; ++j){
                    if((nums[j] >> i)&0x01 == 1){
                        nums1.push_back(nums[j]);
                    }
                    else{
                        nums2.push_back(nums[j]);
                    }
                }
                break;
            }
        }
        //showVec(nums1);
        //showVec(nums2);
        vector<int> result;
        length = nums1.size();
        twoXOR = 0;
        for(int i = 0; i < length; ++i){
            twoXOR ^= nums1[i];
        }
        result.push_back(twoXOR);
        
        length = nums2.size();
        twoXOR = 0;
        for(int i = 0; i < length; ++i){
            twoXOR ^= nums2[i];
        }
        result.push_back(twoXOR);
        return result;
    }
};

int main(void){
    Solution sol;
    vector<int> vec;
    vec.push_back(1); vec.push_back(2); vec.push_back(1); vec.push_back(3);vec.push_back(5);vec.push_back(2);
    //vec.push_back(1); vec.push_back(1); vec.push_back(0); vec.push_back(2);
    showVec(vec);
    showVec(sol.singleNumber(vec));
    return 0;
}
