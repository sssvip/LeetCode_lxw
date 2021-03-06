// File: num049_TLE.cpp
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
#include <unordered_set>
using namespace std;;

class Solution {
private:
    bool isAnagram(string& str1, string& str2){
        sort(str2.begin(), str2.end());
        return str1 == str2;
    }
public:
    vector<string> anagrams(vector<string>& strs) {
        int length = strs.size();
        unordered_set<string> us;
        vector<string> result;
        string temp = "";
        for(int i = 0; i < length; ++i){
            temp = strs[i];
            sort(temp.begin(), temp.end());
            if(us.count(temp) > 0){
                continue;
            }
            bool flag = false;
            for(int j = i + 1; j < length; ++j){
                if(isAnagram(temp, strs[j])){
                    flag = true;
                    result.push_back(strs[j]);
                }
            }
            if(flag){
                us.insert(temp);
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
	strs.push_back("hello");strs.push_back("llheo");strs.push_back("aello");strs.push_back("elalo");
    vector<string> result = sol.anagrams(strs);
	showVec(result);
	return 0;
}
