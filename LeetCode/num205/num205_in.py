#!/usr/bin/python2.7
#File: num205_in.py
#Author: lxw
#Time: 2015-04-29
#Usage: Num 205: Isomorphic Strings.
#Note:
#No two characters may map to the same character but a character may map to itself. e.g.
#"ab", "aa"

class Solution(object):
    def __init__(self):
        pass

    def isIsomorphic(self, s, t):
        mapDict = {}   # "alphabet mapping Dict"
        length = len(s)
        result = True
        for index in xrange(length):
            if s[index] in mapDict.keys():    #compare this with get() method.
                value = mapDict[s[index]]
                if value != t[index]:
                    result = False
                    break
            else:
                if t[index] in mapDict.values():
                    result = False
                    break
                else:
                    mapDict[s[index]] = t[index]
        return result


def main():
    s = Solution()
    isomDict = {"egg":"add", "foo":"bar", "paper":"title", "ab":"aa"}
    for item in isomDict:
        print item, isomDict[item], " : ",
        print(s.isIsomorphic(item, isomDict[item]))


if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")
