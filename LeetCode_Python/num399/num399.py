#!/usr/bin/python2.7
# FileName: num399.py
# Author: lxw
# Date: 2016-09-12

"""
Num 399: Evaluate Division
Source: https://leetcode.com/problems/evaluate-division/

Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.

Example:
Given a / b = 2.0, b / c = 3.0. 
queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? . 
return [6.0, 0.5, -1.0, 1.0, -1.0 ].

The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

According to the example above:

equations = [ ["a", "b"], ["b", "c"] ],
values = [2.0, 3.0],
queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
"""

class Solution(object):
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        #dividend / divisor = quotient ... remainder
        charDictCharFloat = {}
        length = len(equations)
        for index in xrange(length):
            dividend, divisor = equations[index]
            if dividend not in charDictCharFloat:
                charDictCharFloat[dividend] = {}
            charDictCharFloat[dividend][divisor] = values[index] 

        print "charDictCharFloat:\n", charDictCharFloat
        length = len(queries)
        result = [-1.0] * length
        for index in xrange(length):
            dividend, divisor = queries[index]
            flag = False
            if dividend in charDictCharFloat and divisor in charDictCharFloat:
                print "Both"
                for key in charDictCharFloat[dividend]:
                    if key in charDictCharFloat[divisor]:
                        result[index] = charDictCharFloat[dividend][key] / charDictCharFloat[divisor][key]
                        flag = True
                        print "OK"
                        break
            elif dividend in charDictCharFloat and divisor not in charDictCharFloat: 
                pass
            elif dividend not in charDictCharFloat and divisor in charDictCharFloat: 
                pass
            else:
                for key in charDictCharFloat.iterkeys():
                    if divisor in charDictCharFloat[key] and dividend in charDictCharFloat[key]:
                        result[index] = charDictCharFloat[key][divisor] / charDictCharFloat[key][dividend]
                        flag = True
                        print "OK"
                        break
            if not flag:
                result[index] = -1.0;
                print "No"
                

        return result

def main():
    sol = Solution()
    equations = [ ["a", "b"], ["b", "c"] ]
    values = [2.0, 3.0] 
    queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ] 
    print "result:\n", sol.calcEquation(equations, values, queries)

if __name__ == "__main__":
    main()
