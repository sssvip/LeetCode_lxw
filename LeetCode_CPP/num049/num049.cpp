// File: num049.cpp
// Author: lxw
// Date: 2015-06-27

/*
Num num049: 
Source: 

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
        vector<string> ret;
        map<string, int> m;

        for(int i = 0; i < strs.size(); i ++) {
            string s = strs[i];
            sort(s.begin(), s.end());
            if(m.find(s) == m.end()) {
                m[s] = i;
            }
            else{
                if(m[s] >= 0) {
                    ret.push_back(strs[m[s]]);
                    m[s] = -1;
                }
                ret.push_back(strs[i]);
            }
        }
        return ret;
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
