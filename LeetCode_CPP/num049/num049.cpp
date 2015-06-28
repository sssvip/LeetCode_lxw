// File: num049.cpp
// Author: lxw
// Date: 2015-06-27

/*
Num num049: Anagrams
Source: https://leetcode.com/problems/anagrams/

Given an array of strings, return all groups of strings that are anagrams.

Note: All inputs will be in lower-case.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>

using namespace std;
class Solution {
public:
	vector<string> anagrams(vector<string> &strs) {
		int length = strs.size();
		vector<string> result;
		if(length <= 1){
			return result;
		}
		map<string, int> strIndex;
		for(int i = 0; i < length; ++i){
			string temp = strs[i];
			sort(temp.begin(), temp.end());
			if(strIndex.count(temp) == 0){
				strIndex[temp] = i;
			}
			else{
				if(strIndex[temp] >= 0){
					result.push_back(strs[strIndex[temp]]);
					strIndex[temp] = -1;
				}
				result.push_back(strs[i]);
			}
		}
		return result;
	}
};
void showVec(vector<string> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ",";
    }
    cout << vec[length-1] << endl;
}

int main(void){
	Solution sol;
	vector<string> strs;
	strs.push_back("hello");strs.push_back("lleo");strs.push_back("aello");strs.push_back("elalo");
    vector<string> result = sol.anagrams(strs);
	showVec(result);
	return 0;
}
