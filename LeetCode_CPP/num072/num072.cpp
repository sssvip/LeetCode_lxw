// File: num072.cpp
// Author: lxw
// Date: 2015-07-08

/*
Num num072: Edit Distance
Source: https://leetcode.com/problems/edit-distance/
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2. (each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 == 0)
            return len2;    //insert
        if(len2 == 0)
            return len1;    //delete
        vector<vector<int> > vvi(len1+1, vector<int>(len2+1, 0));
        //Index begins with 1.  0 points to no letter.
        for(int i = 0; i <= len1; ++i){
            vvi[i][0] = i;
        }
        for(int j = 0; j <= len2; ++j){
            vvi[0][j] = j;
        }
        for(int i = 1; i <= len1; ++i){
            for(int j = 1; j <= len2; ++j){
                // index begins with 0. not word1[i] but word1[i-1].
                vvi[i][j] = word1[i-1] == word2[j-1] ? vvi[i-1][j-1] : vvi[i-1][j-1] + 1; // replace
                                //replace       insert          delete
                vvi[i][j] = min(vvi[i][j], min(vvi[i-1][j]+1, vvi[i][j-1]+1));
            }
        }
        return vvi[len1][len2];
    }
};


int main(void){
	Solution sol;
	cout << sol.minDistance("dinitrophenylhydrazine", "acetylphenylhydrazine") << endl;
	return 0;
}