// File: num060.cpp
// Author: lxw
// Date: 2015-06-26

/*
Num num060: Permutation Sequence
Source: https://leetcode.com/problems/permutation-sequence/

The set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.

Note: Given n will be between 1 and 9 inclusive.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

class Solution {
private:
    int factorial(int n){
        if(n == 0 || n == 1){
            return 1;
        }
        int result = 1;
        for(int i = 1; i <= n; ++i){
            result *= i;
        }
        return result;
    }
    void swap(char & ch1, char & ch2){
        char ch = ch1;
        ch1 = ch2;
        ch2 = ch;
    }
public:
    string getPermutation(int n, int k) {
        string target = "";
        for(int i = 1; i <= n; ++i){
            target += i+'0';
        }
        if(k < 0 || k > factorial(n))
            return "";
        if(k == 1)
            return target;
        for(int i = 0; i < n; ++i){
            if(k == 1){
                break;
            }
            int fact = factorial(n-i-1);
            int index = (k - 1) / fact;
            index += i;
            //not swap
            //swap(target[index], target[i]);
            target = target.substr(0, i) + target[index] + target.substr(i, index-i) + target.substr(index+1);
            k = (k - 1) % fact + 1;
        }
        return target;
    }
};

int main(void){
    Solution sol;
    cout << sol.getPermutation(9, 5) << endl;
    return 0;
}
