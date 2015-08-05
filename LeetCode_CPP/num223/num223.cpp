// File: num223.cpp
// Author: lxw
// Date: 2015-08-05

/*
Num num223: Rectangle Area 
Source: https://leetcode.com/problems/rectangle-area/

Find the total area covered by two rectilinear rectangles in a 2D plane.

Each rectangle is defined by its bottom left corner and top right corner as shown in the figure.

Rectangle Area
Assume that the total area is never beyond the maximum possible value of int.

Credits:
Special thanks to @mithmatt for adding this problem, creating the above image and all test cases.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class Solution {
private:
    void assure(int & num1, int & num2){
        int temp = num1;
        if(num1 > num2){
            num1 = num2;
            num2 = temp;
        }
    }
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        assure(A, C);
        assure(B, D);
        assure(E, G);
        assure(F, H);
        //cout << "inter: " << intersect(A, B, C, D, E, F, G, H) << endl;
        return (C-A) * (D-B) + (G-E) * (H-F) - intersect(A, B, C, D, E, F, G, H);
    }
    int intersect(long long A, long long B, long long C, long long D, long long E, long long F, long long G, long long H){
        long long width = 0;
        long long height = 0;
        if(A <= E){
            width = min(C-E, G-E);
        }
        else{ //A > E
            width = min(G-A, C-A);
        }
        //cout << "width: " << width << endl;
        if(width <= 0)
            return 0;
        if(F <= B)
            height = min(H-B, D-B);
        else
            height = min(D-F, H-F);
        //cout << "height: " << height << endl;
        if(height <= 0)
            return 0;        
        return width * height;
    }
};

int main(void){
	Solution sol;
	cout << sol.computeArea(-1500000001, 0, -1500000000, 1, 1500000000, 0, 1500000001, 1) << endl;
    cout << (long long)((long long)(-1500000001) - (long long)(1500000000)) << endl;
	return 0;
}


//Better and Easier
class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int result = (D - B) * (C - A) + (H - F) * (G - E);
        int left = max(A, E);
        int bottom = max(B, F);
        int right = min(C, G);
        int top = min(D, H);
        if (top <= bottom || right <= left)
            return result;
        return result - (top - bottom) * (right - left);
    }
};