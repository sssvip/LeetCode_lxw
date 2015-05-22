// File: num004_array.cpp
// Author: lxw
// Date: 2015-05-14

/*
Num 004: Median of Two Sorted Arrays
Source: https://leetcode.com/problems/median-of-two-sorted-arrays/

There are two sorted arrays nums1 and nums2 of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*/

#include <iostream>
#include <vector>
using std::min;
using std::cout;
using std::endl;

// [Recursively] Find the Kth minimium element in 2 arrays.
double findKthMin(int A[], int m, int B[], int n, int k) {
    // To ensure m is smaller than n.
    if (m > n)
        return findKthMin(B, n, A, m, k);

    // NOTE: 2 exit (more than one exit).
    if (m == 0)
       return B[k -1];
    if (k == 1)
        return min(A[0], B[0]);
    
    int posA = min(k/2, m);
    int posB = k - posA;
    if (A[posA - 1] < B[posB - 1])
        return findKthMin(A + posA, m - posA, B, n, k - posA);
    else if (A[posA - 1] > B[posB - 1])
        return findKthMin(A, m, B + posB, n - posB, k - posB);
    else
        return A[posA - 1];
}

double findMedianSortedArrays1(int A[], int m, int B[], int n) {
//double findMedianSortedArrays(vector<int>& A, vector<int>& B) {
    //int m = A.size();
    //int n = B.size();
    int total = m + n;
    //if (total % 2)
    if (total & 0x01)
        return findKthMin(A, m, B, n, total/2+1);
    else
        return (findKthMin(A , m, B, n, total/2) +
                 findKthMin(A, m, B, n, total/2+1)) / 2;
}

void showArray(int A[], int m, int B[], int n){
    cout << "First Array" << endl;
    for(int i = 0; i < m; ++i){
        cout << A[i] << "\t";
    }
    cout << endl;

    cout << "Second Array" << endl;
    for(int i = 0; i < n; ++i){
        cout << B[i] << "\t";
    }
    cout << endl;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    vector<int>:;iterator it1 = nums1.begin();
    vector<int>:;iterator it2 = nums2.begin();
    findMedianSortedArrays1(*it1, nums1.size(), *nums2, nums2.size());
}

int main(int argc, char ** argv){
    vector<int> r(0);
    vector<int> r0(1);
    r0.push_back(1);

    cout << "Median is 1 = " << findMedianSortedArrays(r, r0) << endl;
    return 0;
}
