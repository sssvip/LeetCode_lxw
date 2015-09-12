// File: num278.cpp
// Author: lxw
// Date: 2015-09-12

/*
Num num278: First Bad Version
Source: https://leetcode.com/problems/first-bad-version/

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

/*
This expression int temp = (begining + end) / 2; should be rewritten as
int temp = beginning + (end - beginning)/2; because when n is very large,
(begining + end) may overflow, unexpected result may happen.
*/
/*NOTE:
"mid = start + ((end - start) >> 1);"  parenthesis is essential here.
1. NOT: "mid = start + (end - start) >> 1;"
Priority: '+' is higher than '>>'
2. NOT: mid = (start + end) >> 1;
When start and end is very big, the result may overflow, unexpected result may happen.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version){
	switch(version){
		case 1:
			return false;
		case 2:
		case 3:
			return true;
	}
}

class Solution {
public:
    int firstBadVersion(int n) {
        if(n <= 0)
            return -1;
        if(!isBadVersion(n)){
            return n + 1;
        }
        int start = 1;  // not zero
        int end = n;
        int mid;
        while(start < end){
            mid = start + ((end - start) >> 1);            
            if(isBadVersion(mid)){            	
                end = mid;
            }
            else{
                start = mid + 1;
            }
        }
        return end;
    }
};

int main(void){
	Solution sol;
	cout << sol.firstBadVersion(3) << endl;
	return 0;
}