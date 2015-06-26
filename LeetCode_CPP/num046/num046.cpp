// File: num046.cpp
// Author: lxw
// Date: 2015-06-26

/*
Num num046:
Source:

*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > vvi;
    void permute(vector<int> & nums, int begin, int end){
        if(begin == end){
            this->vvi.push_back(nums);
            return;
        }
        //begin < end
        permute(nums, begin+1, end);
        int tempBegin = begin+1;
        while(tempBegin <= end){
            int temp = nums[begin];
            nums[begin] = nums[tempBegin];
            nums[tempBegin] = temp;
            permute(nums, begin+1, end);
            temp = nums[begin];
            nums[begin] = nums[tempBegin];
            nums[tempBegin] = temp;
            ++tempBegin;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
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
	vec.push_back(1);vec.push_back(2);vec.push_back(3);vec.push_back(4);
	Solution sol;
	vector<vector<int> > vvi = sol.permute(vec);	
	for(vector<vector<int> >::iterator iter = vvi.begin(); iter != vvi.end(); ++iter){
		//(*iter): parenthesis is essential in the following line.
		for(vector<int>::iterator iter1 = (*iter).begin(); iter1 != (*iter).end(); ++iter1){
			cout << *iter1 << ",";
		}
		cout << endl;
	}
    return 0;
}