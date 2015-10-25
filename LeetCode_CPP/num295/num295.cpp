// File: num295.cpp
// Author: lxw
// Date: 2015-10-25
// References: http://blog.csdn.net/zhangxiao93/article/details/49285469
//             http://www.bubuko.com/infodetail-1151393.html

/*
Num num295: Find Median from Data Stream
Source: https://leetcode.com/problems/find-median-from-data-stream/ 

Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.

Examples: 
[2,3,4] , the median is 3

[2,3], the median is (2 + 3) / 2 = 2.5

Design a data structure that supports the following two operations:

void addNum(int num) - Add a integer number from the data stream to the data structure.
double findMedian() - Return the median of all elements so far.
For example:

add(1)
add(2)
findMedian() -> 1.5
add(3) 
findMedian() -> 2
Credits:
Special thanks to @Louis1992 for adding this problem and creating all test cases.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <queue>

using namespace std;

class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>> maxHeap;
    priority_queue<int, vector<int>, less<int>> minHeap;
public:
    // Adds a number into the data structure.
    void addNum(int num) {
        maxHeap.push(num);
        int mid = maxHeap.top();
        maxHeap.pop();
        minHeap.push(mid);
        int maxSize = maxHeap.size();
        int minSize = minHeap.size();
        if(minSize > maxSize){
            mid = minHeap.top();
            minHeap.pop();
            maxHeap.push(mid);
        }
    }

    // Returns the median of current data stream
    double findMedian() {
        int maxSize = maxHeap.size();
        int minSize = minHeap.size();
        if(maxSize == 0)
            return 0;
        else if(maxSize > minSize){
            return maxHeap.top();
        }
        else{
            return (maxHeap.top() + minHeap.top()) / 2.0;
        }cout << "Current Median: " << mf.findMedian() << endl;
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

int main(void){
    MedianFinder mf;
    /*
    mf.addNum(2);
    cout << "Current Median: " <<  mf.findMedian() << endl;
    mf.addNum(3);
    cout << "Current Median: " <<  mf.findMedian() << endl;*/
    cout << "Current Median: " << mf.findMedian() << endl;
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(6);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(10);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(2);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(6);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(5);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(0);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(6);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(3);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(1);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(0);
    cout << "Current Median: " << mf.findMedian() << endl;
    mf.addNum(0);
    cout << "Current Median: " << mf.findMedian() << endl;
    return 0;
}