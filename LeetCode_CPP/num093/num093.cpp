// File: num093.cpp
// Author: lxw
// Date: 2015-08-08

/*
Num 093: Restore IP Addresses
Source: https://leetcode.com/problems/restore-ip-addresses/

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

For example:
Given "25525511135",

return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)
*/

class Solution {
private:
    vector<string> result;
    bool isNum(string & s, int start, int end){
        int num = 0;
        for(int i = start; i <= end; ++i){
            num = num * 10 + s[i] - '0';
        }
        if(num >= 0 && num <= 255)
            return true;
        else
            return false;
    }
    
    void restore(string & s, int start, int end, int count, vector<string> & vs){
        if(start > end){
            if(count == 4){
                this->result.push_back(join(vs));
            }
            return;
        }
        for(int i = start; i <= end; ++i){
            if(isNum(s, start, i)){
                vs.push_back(s.substr(start, i-start+1));
                restore(s, i+1, end, count+1, vs);
                vs.pop_back();
            }
            else{
                break;
            }
        }
    }
    
    string join(vector<string> & vs){
        string str = vs[0];
        for(int i = 1; i < 4; ++i){
            str += "." + vs[i];
        }
        return str;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        int length = s.size();
        vector<string> vs;
        if(length < 4 || length > 12)
            return vs;
        restore(s, 0, length-1, 0, vs);
        return this->result;
    }
};