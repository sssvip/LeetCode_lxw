// File: num069.cpp
// Author: lxw
// Date: 2015-07-03

/*
Num num069:
Source:

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

class Solution {
/*
private:
    //OK, but we can avoid calling the function.
    int getMid(int start, int end){
        long long llStart = (long long)start;
        long long llEnd = (long long)end;
        return int((llStart + llEnd)/2);
    }*/
public:
    int mySqrt(int x) {
        if(x <= 0){
            return 0;
        }
        if(x == 1)
            return 1;
        int i = 1;
        //(long long) here is essential. int is NOT OK.
        long long product = 0;
        long long start = 0;
        long long end = x;
        long long mid = 0;
        while(start < end - 1){
            mid = (start + end) / 2;
            product = mid * mid;            
            if(product == x){
                return mid;
            }
            else if(product < x){
                start = mid;
            }
            else{
                end = mid;
            }
        }
        return start;
    }
};

int main(void){
	Solution sol;
	cout << sol.mySqrt(2147395599) << endl;
	return 0;
}