// File: num047.cpp
// Author: lxw
// Date: 2015-06-26

/*
Num num047: Permutations II 
Source: https://leetcode.com/problems/permutations-ii/
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].
*/

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
private:
    vector<vector<int> > vvi;

	void swap(int & num1, int & num2){
	    int temp = num1;
	    num1 = num2;
	    num2 = temp;
	}

    void permute(vector<int> & nums, int begin, int end){
        if(begin == end){
            this->vvi.push_back(nums);
            return;
        }
        //begin < end
        unordered_set<int> us;
        us.insert(nums[begin]);
        permute(nums, begin+1, end);
        int tempBegin = begin+1;
        while(tempBegin <= end){
            if(us.count(nums[tempBegin]) == 0){
	            swap(nums[begin], nums[tempBegin]);
	            permute(nums, begin+1, end);
	            swap(nums[begin], nums[tempBegin]);
                us.insert(nums[tempBegin]);
        	}
            ++tempBegin;
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int length = nums.size();
        if(length == 0){
            this->vvi.push_back(nums);
        }
        else{
            permute(nums, 0, length-1);
        }
        return this->vvi;
    }
};

int main(void){
	vector<int> vec;
	vec.push_back(3);vec.push_back(3);vec.push_back(0);vec.push_back(0);vec.push_back(2);vec.push_back(3);vec.push_back(2);
	Solution sol;
	vector<vector<int> > vvi = sol.permuteUnique(vec);	
	for(vector<vector<int> >::iterator iter = vvi.begin(); iter != vvi.end(); ++iter){
		//(*iter): parenthesis is essential in the following line.
		for(vector<int>::iterator iter1 = (*iter).begin(); iter1 != (*iter).end(); ++iter1){
			cout << *iter1 << ",";
		}
		cout << endl;
	}
    return 0;
}
