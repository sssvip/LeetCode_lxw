// Memory Limit Exceeded.
// I think "Memory cost on the heap seems being limited." (new is not allowed, while 'int array2 = int[1000][1000]' is allowed;
// File: num005_dp.cpp
// Author: lxw
// Date: 2015-05-20

/*
Num 005: Longest Palindromic Substring
Source: https://leetcode.com/problems/longest-palindromic-substring/

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/
#include <iostream>

class Solution {
    public:
        std::string longestPalindrome(std::string s) {
            int length = s.length();
            int** array2 = new int* [length];
            for(int i = 0; i < length; ++i){
                array2[i] = new int[length];
            }
            //[NO]std::string maxStr = std::string(s[0]);
            //[YES]std::string maxStr = "";
            //maxStr.insert(maxStr.begin(), s[0]);
            int maxStart = 0;
            int maxLength = 1;

            //length == 1
            //Is this operation essential? Yes. Note the calculation of the "blue line" in the picture. And so on.
            for(int i = 0; i < length; ++i){
                array2[i][i] = true;
            }
            //length == 2
            for(int i = 0; i < length-1; ++i){
                if(s[i] == s[i+1]){
                    array2[i][i+1] = true;
                    maxLength = 2;
                    //maxStr = s.substr(i, 2);
                    maxStart = i;
                    //std::cout << maxStr << std::endl;
                }
                else{
                    array2[i][i+1] = false;
                }
            }
            //length >= 3
            for(int curLength = 3; curLength <= length; ++curLength){
                for(int i = 0; i < length-curLength+1; ++i){
                    int j = i + curLength - 1;
                    if(array2[i+1][j-1] && s[i] == s[j]){
                        array2[i][j] = true;
                        maxLength = curLength;
                        //maxStr = s.substr(i, maxLength);
                        maxStart = i;
                        //std::cout << "array2[" << i+1 << "][" << j-1 << "]:" << array2[i+1][j-1] << "\ts[" << i << "]:" << s[i] << ", s[" << j << "]:" << s[j] << std::endl;
                        //std::cout << maxStr << std::endl;
                    }
                    else{
                        array2[i][j] = false;
                        //std::cout << "array2[" << i+1 << "][" << j-1 << "]:" << array2[i+1][j-1] << "\ts[" << i << "]:" << s[i] << ", s[" << j << "]:" << s[j] << std::endl;
                    }
                    //}
                }
            }

            for(int i = 0; i < length; ++i){
                delete[] array2[i];
            }
            delete[] array2;
            return s.substr(maxStart, maxLength);
        }
};

int main(int argc, char ** argv){
	Solution s;
	std::cout << s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << std::endl;
	return 0;
}
