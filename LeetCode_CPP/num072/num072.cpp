// File: num072.cpp
// Author: lxw
// Date: 2015-07-07

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
private:
    int minDistance(string & word1, int index1, int len1, string & word2, int index2, int len2, int count){
        if(index1 == len1)
            return count + len2 - index2;
        if(index2 == len2)
            return count + len1 - index1;
        if(word1[index1] == word2[index2]){
            ++index1;
            ++index2;
            return minDistance(word1, index1, len1, word2, index2, len2, count);
        }
        else{
            return min( minDistance(word1, index1, len1, word2, index2+1, len2, count+1),   //insert
                        min(minDistance(word1, index1+1, len1, word2, index2, len2, count+1),   //delete
                            minDistance(word1, index1+1, len1, word2, index2+1, len2, count+1))   //replace
                    );
        }
    }
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        if(len1 == 0)
            return len2;    //insert
        if(len2 == 0)
            return len1;    //delete
        return minDistance(word1, 0, len1, word2, 0, len2, 0);
    }
};

int main(void){
	Solution sol;
	cout << sol.minDistance("dinitrophenylhy", "acetylphenylhy") << endl;	
	return 0;
}