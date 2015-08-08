// File: num131.cpp
// Author: lxw
// Date: 2015-08-08

/*
Num num131: Palindrome Partitioning
Source: https://leetcode.com/problems/palindrome-partitioning/

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]
*/

class Solution {
private:
    vector<vector<string>> vvs;
    bool isPalindrome(string & s, int start, int end){
        while(start < end){
            if(s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void partition(string & s, int start, int end, vector<string> & vs){
        if(start > end){
            this->vvs.push_back(vs);
            return;
        }
        for(int i = start; i <=end; ++i){
            if(isPalindrome(s, start, i)){
                vs.push_back(s.substr(start, i-start+1));
                partition(s, i+1, end, vs);
                vs.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        int length = s.size();
        vector<string> vs;
        partition(s, 0, length-1, vs);
        return this->vvs;
    }
};