// File: num004_vector.cpp
// Author: lxw
// Date: 2015-05-22

/*
Num 004: Median of Two Sorted Arrays
Source: https://leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <vector>
using namespace std;

// [Recursively] Find the Kth minimium element in 2 arrays.
//double findKthMin(int A[], int m, int B[], int n, int k) {
double findKthMin(vector<int> A, vector<int> B, int k) {
    int m = A.size();
    int n = B.size();
    // To ensure m is smaller than n.
    if (m > n)
        return findKthMin(B, A, k);

    // NOTE: 2 exit (more than one exit).
    if (m == 0)
        return B[k -1];
    if (k == 1)
        return min(A[0], B[0]);
    
    int posA = min(k/2, m);
    int posB = k - posA;
    //NOTE: The following block has something wrong. And not good enough, a lot of temporary vector is needed?
    if (A[posA - 1] < B[posB - 1])
        return findKthMin(A(A.begin() + posA, A.end()), B, k - posA);
    else if (A[posA - 1] > B[posB - 1])
        return findKthMin(A, B(B.begin() + posB, B.end()), k - posB);
    else
        return A[posA - 1];
}

//double findMedianSortedArrays(int A[], int m, int B[], int n) {
double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    int total = A.size() + B.size();
    //if (total % 2)
    if (total & 0x01)
        return findKthMin(A, B, total/2+1);
    else
        return (findKthMin(A, B, total/2) +
                 findKthMin(A, B, total/2+1)) / 2;
}

int main(int argc, char ** argv){
    /*
    int r[] = {};
    int r0[] = {1};
 
    int n = sizeof(r)/sizeof(r[0]);
    int n0 = sizeof(r0)/sizeof(r0[0]);

    showArray(r, n, r0, n0);
    */
    vector<int> r;
    vector<int> r0;
    r0.push_back(1);

    cout << "Median is 1 = " << findMedianSortedArrays(r, r0) << endl;
    return 0;
}
