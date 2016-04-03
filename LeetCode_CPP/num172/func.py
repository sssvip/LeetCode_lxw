#!/usr/bin/python2.7
# FileName: func.py
# Author: lxw
# Date: 2016-04-03

import sys

def factorial(num):
    result = 1
    for item in xrange(num):
        result *= (item + 1)
    return result

def main():
    print factorial(int(sys.argv[1]))

if __name__ == '__main__':
    main()
else:
    print("Being imported as a module.")

