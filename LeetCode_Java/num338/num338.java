/**
 * @Author: lxw
 * @Date: 2014-12-30
 * @URL: https://leetcode.com/problems/counting-bits/
 */

import java.util.Map;
import java.util.HashMap;
import java.util.Iterator;

class Solution {
	/*
	time: O(32 * n). 4ms.
	*/
	private int numOf1(int num) {
		int count = 0;
		while(num != 0) {
			num &= (num - 1);
			++count;
		}
		return count;
	}

	public int[] countBits1(int num) {
		if(num < 0)
			//return [];	//NO
			//return {};	//NO
			return new int[0];
		int bitCount[] = new int[num + 1];
		for(int i = 0; i <= num; ++i) {
			bitCount[i] = numOf1(i);
		}
		return bitCount;
    }

	/*
	time: O(n). 3ms.
	*/
	public int[] countBits2(int num) {
		if(num < 0)
			return new int[0];
		if(num == 0)
		    return new int[]{0};
		if(num == 1)
			return new int[]{0, 1};
		if(num == 2)
			return new int[]{0, 1, 1};
			
		int bitCount[] = new int[num + 1];
		bitCount[0] = 0;
		bitCount[1] = 1;
		bitCount[2] = 1;
		int criterion = 2;
		for(int i = 3; i <= num; ++i) {
			if(i == (criterion << 1)) {
				bitCount[i] = 1;
				criterion <<= 1;
			}
			else {
				bitCount[i] = bitCount[criterion] + bitCount[i - criterion];
			}
		}
		return bitCount;
	}

	/*
	time: O(n). 4ms.
	*/
	public int[] countBits(int num) {
		if(num < 0)
			return new int[0];
		int bitCount[] = new int[num + 1];
		for(int i = 0; i <= num; ++i) {
			if((i & 0x01) == 0) {	//even	//NOTE: parenthesis is essential here.
				bitCount[i] = bitCount[i/2];
			}
			else {	//odd
				bitCount[i] = bitCount[i/2] + 1;
			}
		}
		return bitCount;
	}
}
public class num338 {
	public static void main(String[] args) {
		Solution sl = new Solution();
		int result[] = sl.countBits(1005);
		int len = result.length;
		for(int i = 0; i < len; ++i) {
			System.out.format("%d, ", result[i]);
		}
		System.out.println();
		result = sl.countBits1(1005);
		len = result.length;
		for(int i = 0; i < len; ++i) {
			System.out.format("%d, ", result[i]);
		}
		System.out.println();
	}
}
