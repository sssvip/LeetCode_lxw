// File: num172.cpp
// Author: lxw
// Date: 2015-10-30

/*
Num num172: Factorial Trailing Zeroes
Source: https://leetcode.com/problems/factorial-trailing-zeroes/

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

Credits:
Special thanks to @ts for adding this problem and creating all test cases.

Subscribe to see which companies asked this question
*/

#include <iostream>
using namespace std;

int main(void){
	long long  result = 1;
	for(int i = 21; i <= 30; ++i){
		result *= i;
		cout << "i: " << i << ", result: " << result << endl;
	}
	return 0;
}