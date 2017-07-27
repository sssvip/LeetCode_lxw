#!/usr/bin/python3.6
# FileName: num056.py
# Author: lxw
# Date: 2017-07-27

"""
Num 056: Merge Intervals
Source: https://leetcode.com/problems/merge-intervals/tabs/description

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
"""

# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        length = len(intervals)
        if length < 2:
            return intervals
        sorted_list = sorted(intervals, key=lambda x: x.start)
        result_list = [sorted_list[0]]
        for item in sorted_list[1:]:
            if item.start <= result_list[-1].end:
                result_list[-1].end = max(item.end, result_list[-1].end)
            else:
                result_list.append(item)
        return result_list