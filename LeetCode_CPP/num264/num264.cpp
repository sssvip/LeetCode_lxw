// File: num264.cpp
// Author: lxw
// Date: 2015-08-22

/*
Num num264: Ugly Number II
Source: https://leetcode.com/problems/ugly-number-ii/

Write a program to find the n-th ugly number.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Note that 1 is typically treated as an ugly number.

Hint:

The naive approach is to call isUgly for every number until you reach the nth one. Most numbers are not ugly. Try to focus your effort on generating only the ugly ones.
An ugly number must be multiplied by either 2, 3, or 5 from a smaller ugly number.
The key is how to maintain the order of the ugly numbers. Try a similar approach of merging from three sorted lists: L1, L2, and L3.
Assume you have Uk, the kth ugly number. Then Uk+1 must be Min(L1 * 2, L2 * 3, L3 * 5).
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/
class Solution {
public:
    int nthUglyNumber(int n) {
        if(n < 7)
            return n;
        queue<int> two;
        queue<int> three;
        queue<int> five;
        int last = 1;
        int front2, front3, front5;
        for(int i = 1; i < n; ++i){
            two.push(last * 2);
            three.push(last * 3);
            five.push(last * 5);
            front2 = two.front();
            front3 = three.front();
            front5 = five.front();
            if(front2 <= front3 && front2 <= front5){
                last = front2;
                two.pop();
                if(front3 == front2)    //front2 == front3 <= front5
                    three.pop();
                if(front5 == front2)    //front2 == front5 <= front3
                    five.pop();
                continue;
            }
            if(front3 <= front2 && front3 <= front5){
                last = front3;
                three.pop();
                /*
                if(front2 == front3)    //front2 == front3 <= front5   must be in the firt case, must not be here.
                    two.pop();
                */
                if(front5 == front3)    //front3 == front5 <= front2.
                    five.pop();
                continue;
            }
            if(front5 <= front3 && front5 <= front2){
                last = front5;
                five.pop();
                /*
                if(front2 == front5)    //front2 == front5 <= front3    must be in the firt case, must not be here.
                    two.pop();
                if(front3 == front5)    //front3 == front5 <=front2     must be in the second case, must not be here.
                    three.pop();
                */
            }
        }
        return last;
    }
};