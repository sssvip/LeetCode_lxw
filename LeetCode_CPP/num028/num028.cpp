// File: num028.cpp
// Author: lxw
// Date: 2015-06-08

/*
Num 028:Implement strStr()
Source: https://leetcode.com/problems/implement-strstr/

Implement strStr().

Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Update (2014-11-02):
The signature of the function had been updated to return the index instead of the pointer. If you still see your function signature returns a char * or String, please click the reload button  to reset your code definition.
*/

#include <iostream>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int length1 = haystack.length();
        int length2 = needle.length();
        if(length2 <= 0){
            return 0;
        }
        else if(length1 < length2){
            return -1;
        }
        int i = 0;
        int j = 0;
        while(i <= length1 - length2){
            if(haystack[i] != needle[0]){
                ++i;
                continue;
            }
            int index = i + 1;
            for(j = 1; j < length2; ++j){
                if(haystack[index] != needle[j]){
                    break;
                }
                ++index;
            }
            if(j == length2){
                return i;
            }
            ++i;
        }
        return -1;
    }
};

int main(int argc, char ** argv){
    Solution sol;
    cout << sol.strStr("mississippi", "issi") << endl;
    return 0;
}
