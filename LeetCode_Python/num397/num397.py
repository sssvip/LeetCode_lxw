#!/usr/bin/python2.7
# FileName: num397.py
# Author: lxw
# Date: 2016-10-09

"""
Num 397: Integer Replacement
Source: https://leetcode.com/problems/integer-replacement/

Given a positive integer n and you can do operations as follow:

If n is even, replace n with n/2.
If n is odd, you can replace n with either n + 1 or n - 1.
What is the minimum number of replacements needed for n to become 1?

Example 1:

Input:
8

Output:
3

Explanation:
8 -> 4 -> 2 -> 1
Example 2:

Input:
7

Output:
4

Explanation:
7 -> 8 -> 4 -> 2 -> 1
or
7 -> 6 -> 3 -> 2 -> 1
"""

class Solution(object):
    """
    Time: O(n)  48ms.
    Space: O(1)
    """
    def integerReplacement(self, n):
        """
        :type n: int
        :rtype: int
        """
        if n == 0:
            return 0

        result = 0
        while n != 1:
            if n & 0x01 == 1:  #n: odd
                #多看一步，贪心: 当前最优解
                if ((n + 1) >> 1) & 0x01 == 1: #(n + 1) >> 1: odd
                    n -= 1
                elif n == 3:
                    n = 2
                else:
                    n += 1
            else:
                n >>= 1
            result += 1
            #print n
        return result

def main():
    sol = Solution()
    num = 3 #Special case: 3, 65535, 65537
    print "minimum number of replacements needed for {0} is {1}".format(num, sol.integerReplacement(num))

if __name__ == "__main__":
    main()