#!/usr/bin/python2.7
# FileName: num071.py
# Author: lxw
# Date: 2015-07-03

"""
Num 071: Simplify Path 
Source: https://leetcode.com/problems/simplify-path/

Given an absolute path for a file (Unix-style), simplify it.

For example,
path = "/home/", => "/home"
path = "/a/./b/../../c/", => "/c"
click to show corner cases.

Corner Cases:
Did you consider the case where path = "/../"?
In this case, you should return "/".
Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
In this case, you should ignore redundant slashes and return "/home/foo".
"""

class Solution:
    # @param {string} path
    # @return {string}
    def simplifyPath(self, path):
        pathList = path.split('/')
        length = len(pathList)
        index = 0
        for i in xrange(length):
            if pathList[i] == '.' or pathList[i] == '':
                continue
            elif pathList[i] == '..':
                index -= 1
                if index < 0:
                    index = 0
            else:
                pathList[index] = pathList[i]
                index += 1
        return '/' + '/'.join(pathList[:index])

if __name__ == '__main__':
	sol = Solution()
	print(sol.simplifyPath('/'))