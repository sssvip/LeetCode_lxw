// File: num05&.cpp
// Author: lxw
// Date: 2015-07-02

/*
Num num057: Insert Interval 
Source: https://leetcode.com/problems/insert-interval/

Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).

You may assume that the intervals were initially sorted according to their start times.

Example 1:
Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].

Example 2:
Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].

This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
private:
    //static is essential here.
    //当comp作为类的成员函数时，默认拥有一个this指针，这样和sort函数所需要使用的排序函数类型不一样。
    //解决方法是将comp改为非成员函数，或者改用静态函数。
    static bool compare(const Interval & i1, const Interval & i2){
        return i1.start < i2.start;
    }
    vector<Interval> merge(vector<Interval>& intervals, int start) {
        vector<Interval> vi;
        int length = intervals.size();
        start = start < 0 ? 0 : start;
        for(int i = 0; i < start; ++i){
        	vi.push_back(intervals[i]);
        }        	
        Interval inter = intervals[start];        
        for(int i = start+1; i < length; ++i){
            if(intervals[i].start <= inter.end){
                //inter.start not change.
                inter.end = max(intervals[i].end, inter.end);                
            }
            else{
                vi.push_back(inter);
                inter = intervals[i];                
            }
        }
        vi.push_back(inter);        
        return vi;
    }
public:    
    void showVec(vector<Interval> & vec){
        int length = vec.size();
        if(length < 1)
            return;
        for(int i = 0; i < length; ++i){
            cout << "[" << vec[i].start << ", " << vec[i].end << "]" << endl;
        }
    }
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {    	
    	int length = intervals.size();
        if(length < 1){
        	intervals.push_back(newInterval);
            return intervals;
        }
        int i = 0;
        for(; i < length; ++i){
        	if(intervals[i].start > newInterval.start){
        		break;
        	}
        }
        if(i == length){
        	intervals.push_back(newInterval);        	
        }
        else{
        	intervals.insert(intervals.begin() + i, newInterval);        	
        }
        return merge(intervals, i-1);
    }    
};

int main(void){
    Solution sol;
    vector<Interval> intervals;
    /*
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(3, 5));
    intervals.push_back(Interval(6, 7));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(12, 16));
    */
    intervals.push_back(Interval(1, 2));
    intervals.push_back(Interval(6, 9));
    //sol.showVec(sol.merge(intervals));        //NOTE: no. difference between lvalue and rvalue for 'reference type';
    vector<Interval> vec = sol.insert(intervals, Interval(2, 5));
    sol.showVec(vec);
    return 0;
}
