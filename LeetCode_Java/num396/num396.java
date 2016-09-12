/**
 * @Author: lxw
 * @Date: 2014-12-30
 * @URL: https://leetcode.com/problems/is-subsequence/
 */

/*
Given an array of integers A and let n to be its length.

Assume Bk to be an array obtained by rotating the array A k positions clock-wise, we define a "rotation function" F on A as follow:

F(k) = 0 * Bk[0] + 1 * Bk[1] + ... + (n-1) * Bk[n-1].

Calculate the maximum value of F(0), F(1), ..., F(n-1).

Note:
n is guaranteed to be less than 105.

Example:

A = [4, 3, 2, 6]

F(0) = (0 * 4) + (1 * 3) + (2 * 2) + (3 * 6) = 0 + 3 + 4 + 18 = 25
F(1) = (0 * 6) + (1 * 4) + (2 * 3) + (3 * 2) = 0 + 4 + 6 + 6 = 16
F(2) = (0 * 2) + (1 * 6) + (2 * 4) + (3 * 3) = 0 + 6 + 8 + 9 = 23
F(3) = (0 * 3) + (1 * 2) + (2 * 6) + (3 * 4) = 0 + 2 + 12 + 12 = 26

So the maximum value of F(0), F(1), F(2), F(3) is F(3) = 26.
*/

/*
*/
class Solution {
	private int getF_k_(int[] A, int k, int length) {
		int F_k_ = 0;
		for(int i = 0; i < length; ++i) {
			F_k_ += ((k + i) % length) * A[i];
		}
		return F_k_;
	}

	//TLE: Time: O(n^2)
    public int maxRotateFunction_1(int[] A) {
    	//TLE
    	int len = A.length;
    	if(len < 2)	//0 || 1
    		return 0;
    	int maxValue = getF_k_(A, 0, len);
    	int temp;
    	for(int k = 1; k < len; ++k) {
    		temp = getF_k_(A, k, len);
    		maxValue = maxValue > temp ?  maxValue : temp;
    	}
    	return maxValue;
    }

    //Accepted. Time: O(n). 5 ms.
    public int maxRotateFunction(int[] A) {
    	//TLE
    	int len = A.length;
    	if(len < 2)	//0 || 1
    		return 0;

    	int maxValue = 0;
    	int sumA = 0;
    	for(int i = 0; i < len; ++i) {
			maxValue += i * A[i];
    		sumA += A[i];
		}
    	int last = maxValue;
    	int temp;
    	for(int k = 1; k < len; ++k) {
    		temp = last + sumA - len * A[len - k];
    		last = temp;
    		maxValue = maxValue > temp ?  maxValue : temp;
    	}
    	return maxValue;
    }
}

public class num396 {
	public static void main(String[] args) {
		Solution sl = new Solution();
		int[] array = {4, 3, 2, 6};
			System.out.format("result = %d\n", sl.maxRotateFunction(array));
	}
}
