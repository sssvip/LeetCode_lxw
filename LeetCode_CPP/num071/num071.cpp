// File: num071.cpp
// Author: lxw
// Date: 2015-07-03

/*
Num num071: Simplify Path
Source: https://leetcode.com/problems/simplify-path/
Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {        
        string dirName = "";
        int index = 0;
        int length = path.length();
        int count = 1;
        for(int i = 0; i < length; ++i){
        	if(path[i] == '/'){
        		++count;
        	}
        }
        vector<string> vs(count, "");
        for(int i = 0; i < length; ++i){
            if(path[i] == '/'){
                if(dirName != ""){
                    vs[index] = dirName;
                    dirName = "";
                    ++index;
                }
            }
            else if(path[i] == '.'){
                if(dirName == ""){
                    ++i;
                    if(i < length && path[i] == '.'){
                        ++i;
                        if(i >= length || (i < length && path[i] == '/')){
                            index = index < 1 ? 0 : index - 1;
                        }
                        else{
                        	//CANNOT BE dirName += ".." + path[i];                        	
                            dirName += "..";
                            dirName += path[i];
                        }
                    }
                    else if(i < length && path[i] == '/'){
                        continue;
                    }
                    else if(i < length){
                    	//CANNOT BE dirName += '.' + path[i];
                        dirName += '.';
                        dirName += path[i];
                    }
                }
                else{
                    dirName += path[i];
                }
            }
            else{
                dirName += path[i];
            }
        }
        if(dirName != ""){
            vs[index] = dirName;
            ++index;
        }
        if(index == 0)
            return "/";
        string result = "";
        for(int i = 0; i < index; ++i){
            result += "/" + vs[i];
        }
        return result;
    }
};

int main(void){
	Solution sol;
	string str;
	while(cin >> str){
		cout << sol.simplifyPath(str) << endl;
	}
	return 0;
}