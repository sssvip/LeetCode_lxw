#!/usr/bin/python2.7
# FileName: num388.py
# Author: lxw
# Date: 2016-09-01

"""
Num 388: Longest Absolute File Path
Source: https://leetcode.com/problems/longest-absolute-file-path/

Suppose we abstract our file system by a string in the following manner:

The string "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext" represents:

dir
    subdir1
    subdir2
        file.ext
The directory dir contains an empty sub-directory subdir1 and a sub-directory subdir2 containing a file file.ext.

The string "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext" represents:

dir
    subdir1
        file1.ext
        subsubdir1
    subdir2
        subsubdir2
            file2.ext
The directory dir contains two sub-directories subdir1 and subdir2. subdir1 contains a file file1.ext and an empty
second-level sub-directory subsubdir1. subdir2 contains a second-level sub-directory subsubdir2 containing a file
file2.ext.

We are interested in finding the longest (number of characters) absolute path to a file within our file system.
For example, in the second example above, the longest absolute path is "dir/subdir2/subsubdir2/file2.ext", and its
length is 32 (not including the double quotes).

Given a string representing the file system in the above format, return the length of the longest absolute path to
file in the abstracted file system. If there is no file in the system, return 0.

Note:
The name of a file contains at least a . and an extension.
The name of a directory or sub-directory will not contain a ..
Time complexity required: O(n) where n is the size of the input string.

Notice that a/aa/aaa/file1.txt is not the longest file path, if there is another path aaaaaaaaaaaaaaaaaaaaa/sth.png.
"""

class Solution(object):
    """
    Time: O(n)
    Space: O(height)
    48ms
    """
    def lengthLongestPath(self, input):
        """
        :type input: str
        :rtype: int
        """
        maxLength = 0
        length = len(input)
        index = 0
        i = 0
        layer = 0
        array = []
        while i < length:
            if input[i] == '\n':
                fileName = input[index:i]
                #print "fileName: ", fileName
                if layer > 0:
                    if layer < len(array):
                        array[layer] = array[layer - 1] + len(fileName) + 1
                    else:
                        array.append(array[layer - 1] + len(fileName) + 1)
                else:
                    if layer < len(array):
                        array[layer] = len(fileName)
                    else:
                        array.append(len(fileName))
                if '.' in fileName:  #file, and not dir
                    maxLength = array[layer] if array[layer] > maxLength else maxLength

                i += 1
                layer = 0
                while i < length:
                    if input[i] == '\t':
                        layer += 1
                        i += 1
                    else:
                        index = i
                        break
            else:
                i += 1
        fileName = input[index:]
        #print "fileName: ", fileName
        if layer > 0:
            if layer < len(array):
                array[layer] = array[layer - 1] + len(fileName) + 1
            else:
                array.append(array[layer - 1] + len(fileName) + 1)
        else:
            if layer < len(array):
                array[layer] = len(fileName)
            else:
                array.append(len(fileName))
        if '.' in fileName:  #file, and not dir
            maxLength = array[layer] if array[layer] > maxLength else maxLength
        return maxLength

def main():
    sol = Solution()
    string = "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"
    print "string:", string
    print sol.lengthLongestPath(string)

    string = "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"
    print "string:", string
    print sol.lengthLongestPath(string)

if __name__ == "__main__":
    main()
