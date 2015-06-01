// File: num022.cpp
// Author: lxw
// Date: 2015-06-01

/*
Num 022:
Source:

Main Idea: 用DFS: 能加'('就加'('，能加')'就加')'
*/

class Solution{
public:
    vector<string> generateParenthesis(int n){
        vector<string> result;
        string str = "";
        generate(result, str, n, n); 
        return result;
    }
private:
    void generate(vector<string>& ret, string str, int left, int right){
        if(left > right)
            return;
        if(left < 0 || right < 0)
            return;
        if(left == 0 && right == 0){
            ret.push_back(str);
            return;
        }
        generate(ret, str + "(", left-1, right);
        generate(ret, str + ")", left, right - 1);
    }
};
