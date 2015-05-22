// Time Limit Exceeded.
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
            int maxLength = 1;
            //std::string maxStr = std::string(s[0]);
            std::string maxStr = "";
            maxStr.insert(maxStr.begin(), s[0]);
            for(int i = 0; i < length; ++i){
                array2[i] = new int[length];
            }

            //length == 1
            //Is this operation essential? Yes. Note the calculation of the "blue line" in the picture.
            for(int i = 0; i < length; ++i){
                array2[i][i] = true;
            }
            //length == 2
            for(int i = 0; i < length-1; ++i){
                if(s[i] == s[i+1]){
                    array2[i][i+1] = true;
                    maxLength = 2;
                    maxStr = s.substr(i, 2);
                    //If we use maxStr to save the temporary longest string, we will get the TLE.
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
                        maxStr = s.substr(i, maxLength);
                        //If we use maxStr to save the temporary longest string, we will get the TLE.
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
            return maxStr;
        }
};

int main(int argc, char ** argv){
	Solution s;
	std::cout << s.longestPalindrome("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa") << std::endl;
	return 0;
}
