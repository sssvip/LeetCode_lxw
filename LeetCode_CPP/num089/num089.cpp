// File: num089.cpp
// Author: lxw
// Date: 2015-07-05

/*
Num 089: Gray Code 
Source: https://leetcode.com/problems/gray-code/

The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

class Solution {
public:
	/*
	1位格雷码有两个码字
	(n+1)位格雷码中的前2^n个码字等于n位格雷码的码字，按顺序书写，加前缀0
	(n+1)位格雷码中的后2^n个码字等于n位格雷码的码字，按逆序书写，加前缀1
	*/
    vector<int> grayCode(int n) {
        vector<int> mid;
        mid.push_back(0);
        if(n == 0){
            return mid;
        }
        mid.push_back(1);
        if(n == 1){
            return mid;
        }
        int count = 1;
        int length = 2;
        while(count < n){
            for(int i = length-1; i >= 0; --i){
                mid.push_back(mid[i] + (1 << count));
            }
            ++count;
            length <<= 1;
        }
        return mid;
    }
    //much too abstract.
    vector<int> grayCode1(int n) {
        vector<int> gray;
        int length = pow(2, n);
        for(int i = 0; i < length; ++i){
            gray.push_back((i / 2) ^ i);
        }
        return gray;
    }
};
void showVec(vector<int> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ", ";
    }
    cout << vec[length-1] << endl;
}
int main(void){
	Solution sol;
	vector<int> vi = sol.grayCode(2);
	showVec(vi);
    return 0;
}