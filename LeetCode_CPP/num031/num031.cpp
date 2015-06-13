// File: num031.cpp
// Author: lxw
// Date: 2015-06-13

/*
Num 031: Next Permutation
Source: https://leetcode.com/problems/next-permutation/

Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int getDisOrder(vector<int> & nums){
        int length = nums.size();
        int i = length - 1;
        while(i > 0){
            if(nums[i] > nums[i-1]){
                break;
            }
            --i;
        }
        if(i > 0){
            return i - 1;
        }
        else{
            return -1;
        }
    }
    void adjust(vector<int> & nums, int begin){
        int length = nums.size();
        int index = begin + 1;
        //index must be smaller than length
        sort(nums.begin()+index, nums.end());
        int i = index;
        for(; i < length; ++i){
            if(nums[i] > nums[begin]){
                break;
            }
        }
        //i must be smaller than length
        int temp = nums[i];
        nums[i] = nums[begin];
        nums[begin] = temp;
    }
    void nextPermutation(vector<int>& nums) {
        int index = getDisOrder(nums);
        if(index == -1){
            reverse(nums.begin(), nums.end());
        }
        else{
            adjust(nums, index);
        }
    }
};

void showVector(vector<int> & nums){
    int length = nums.size();
    for(int i = 0; i < length; ++i){
        cout << nums[i] << "\t";
    }
    cout << endl;
}

int main(void){
    vector<int> v;
    v.push_back(2);
    v.push_back(0);
    v.push_back(0);
    v.push_back(0);
    showVector(v);
    Solution sol;
    sol.nextPermutation(v);
    showVector(v);
}
