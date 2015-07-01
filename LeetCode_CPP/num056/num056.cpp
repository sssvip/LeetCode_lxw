// File: num056.cpp
// Author: lxw
// Date: 2015-07-01

/*
Num num056: Merge Intervals 
Source: https://leetcode.com/problems/merge-intervals/

Given a collection of intervals, merge all overlapping intervals.

For example,
Given [1,3],[2,6],[8,10],[15,18],
return [1,6],[8,10],[15,18].
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

class Solution {
private:
    //static is essential here.
    //当comp作为类的成员函数时，默认拥有一个this指针，这样和sort函数所需要使用的排序函数类型不一样。
    //解决方法是将comp改为非成员函数，或者改用静态函数。
    static bool compare(const Interval & i1, const Interval & i2){
        return i1.start < i2.start;
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
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> vi;
        int length = intervals.size();
        if(length < 1){
            return vi;
        }
        sort(intervals.begin(), intervals.end(), compare);
        Interval inter = intervals[0];        
        for(int i = 1; i < length; ++i){
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
};

int main(void){
    Solution sol;
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(15, 18));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(2, 6));
    //sol.showVec(sol.merge(intervals));        //NOTE: no. difference between lvalue and rvalue for 'reference type';
    vector<Interval> vec = sol.merge(intervals);
    sol.showVec(vec);
    return 0;
}
