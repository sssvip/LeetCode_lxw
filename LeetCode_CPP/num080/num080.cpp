// File: num080.cpp
// Author: lxw
// Date: 2015-07-04

/*
Num 080: Remove Duplicates from Sorted Array II 
Source: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array nums = [1,1,1,2,2,3],

Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
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
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size();
        if(length < 1)
            return length;
        int index = 1;
        int last = nums[0];
        for(int i = 1; i < length; ++i){
            if(nums[i] == last){
                nums[index] = nums[i];
                ++index;
                ++i;
                while(i < length && nums[i] == last){
                    ++i;
                }
                --i;
            }
            else{
                nums[index] = nums[i];
                ++index;
                last = nums[i];
            }
        }
        return index;
    }
};
int main(void){
	Solution sol;
	vector<int> vi;
	vi.push_back(1);vi.push_back(1);vi.push_back(1);vi.push_back(1);
	vi.push_back(3);vi.push_back(3);
	cout << sol.removeDuplicates(vi) << endl;
    return 0;
}