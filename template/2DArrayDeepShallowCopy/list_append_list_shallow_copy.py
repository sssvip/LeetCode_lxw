#!/usr/bin/python2.7
# FileName: list_append_list_shallow_copy.py
# Author: lxw
# Date: 2015-07-10

def test1():
    aList = [1, 2, 4]
    bLList = []
    bLList.append(aList)     #difference    //shallow copy
    print("aList: {0}".format(aList))
    print("bLList: {0}".format(bLList))
    aList[0] = 5
    print("aList: {0}".format(aList))
    print("bLList: {0}".format(bLList))
    bLList[0][0] = 6
    print("aList: {0}".format(aList))
    print("bLList: {0}".format(bLList))

def test2():
    aList = [1, 2, 4]
    bLList = []
    bLList.append(aList[:])     #difference
    print("aList: {0}".format(aList))
    print("bLList: {0}".format(bLList))
    aList[0] = 5
    print("aList: {0}".format(aList))
    print("bLList: {0}".format(bLList))
    bLList[0][0] = 6
    print("aList: {0}".format(aList))
    print("bLList: {0}".format(bLList))

def main():
    test1()
    print ""
    test2()
    '''
    Output:
    lxw num117$ python test.py
    aList: [1, 2, 4]
    bLList: [[1, 2, 4]]
    aList: [5, 2, 4]
    bLList: [[5, 2, 4]]
    aList: [6, 2, 4]
    bLList: [[6, 2, 4]]

    aList: [1, 2, 4]
    bLList: [[1, 2, 4]]
    aList: [5, 2, 4]
    bLList: [[1, 2, 4]]
    aList: [5, 2, 4]
    bLList: [[6, 2, 4]]
    '''

if __name__ == '__main__':
    main()
