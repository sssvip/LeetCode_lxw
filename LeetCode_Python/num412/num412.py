#!/usr/bin/python2.7
#coding: utf-8
# FileName: num412.py
# Author: lxw
# Date: 2016-10-23

"""
Num 412: Fizz Buzz
Source: https://leetcode.com/problems/fizz-buzz/

Write a program that outputs the string representation of numbers from 1 to n.

But for multiples of three it should output “Fizz” instead of the number and for the multiples of five output “Buzz”. For numbers which are multiples of both three and five output “FizzBuzz”.

Example:

n = 15,

Return:
[
    "1",
    "2",
    "Fizz",
    "4",
    "Buzz",
    "Fizz",
    "7",
    "8",
    "Fizz",
    "Buzz",
    "11",
    "Fizz",
    "13",
    "14",
    "FizzBuzz"
]
"""

class Solution(object):
    """
    Time: O(n) 65 ms
    Space: O(n)
    """
    def fizzBuzz(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        result = []
        if n < 1:
            return result
        for num in xrange(1, n+1):
            mod3 = num % 3
            mod5 = num % 5
            if mod3 == 0 and mod5 == 0:
                result.append("FizzBuzz")
            elif mod3 == 0:
                result.append("Fizz")
            elif mod5 == 0:
                result.append("Buzz")
            else:
                result.append(str(num))
        return result

def main():
    sol = Solution()
    print sol.fizzBuzz(15)

if __name__ == "__main__":
    main()
