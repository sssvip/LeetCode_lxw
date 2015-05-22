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
using namespace std;

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

double findMedianSortedArrays(int A[], int m, int B[], int n) {
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


int main(int argc, char ** argv){
    int r[] = {};
    int r0[] = {1};
 
    int n = sizeof(r)/sizeof(r[0]);
    int n0 = sizeof(r0)/sizeof(r0[0]);

    showArray(r, n, r0, n0);
    cout << "Median is 1 = " << findMedianSortedArrays(r, n, r0, n0) << endl;

    int r1[] = {1};
    int r2[] = {2};
 
    int n1 = sizeof(r1)/sizeof(r1[0]);
    int n2 = sizeof(r2)/sizeof(r2[0]);

    showArray(r1, n1, r2, n2);
    cout << "Median is 1.5 = " << findMedianSortedArrays(r1, n1, r2, n2) << endl;

    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45, 50};
 
    n1 = sizeof(ar1)/sizeof(ar1[0]);
    n2 = sizeof(ar2)/sizeof(ar2[0]);

    showArray(ar1, n1, ar2, n2);
    cout << "Median is 17 = " << findMedianSortedArrays(ar1, n1, ar2, n2) << endl << endl;

    int ar11[] = {1, 12, 15, 26, 38};
    int ar21[] = {2, 13, 17, 30, 45 };
 
    n1 = sizeof(ar11)/sizeof(ar11[0]);
    n2 = sizeof(ar21)/sizeof(ar21[0]);

    showArray(ar11, n1, ar21, n2);
    cout << "Median is 16 = " << findMedianSortedArrays(ar11, n1, ar21, n2) << endl << endl;

    int a1[] = {1, 2, 5, 6, 8 };
    int a2[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a1)/sizeof(a1[0]);
    n2 = sizeof(a2)/sizeof(a2[0]);

    showArray(a1, n1, a2, n2);
    cout << "Median is 10.5 = " << findMedianSortedArrays(a1, n1, a2, n2) << endl << endl;

    int a10[] = {1, 2, 5, 6, 8, 9, 10 };
    int a20[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a10)/sizeof(a10[0]);
    n2 = sizeof(a20)/sizeof(a20[0]);

    showArray(a10, n1, a20, n2);
    cout << "Median is 9.5 = " << findMedianSortedArrays(a10, n1, a20, n2) << endl << endl;

    int a11[] = {1, 2, 5, 6, 8, 9 };
    int a21[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a11)/sizeof(a11[0]);
    n2 = sizeof(a21)/sizeof(a21[0]);

    showArray(a11, n1, a21, n2);
    cout << "Median is 9 = " << findMedianSortedArrays(a11, n1, a21, n2) << endl << endl;

    int a12[] = {1, 2, 5, 6, 8 };
    int a22[] = {11, 13, 17, 30, 45, 50};
 
    n1 = sizeof(a12)/sizeof(a12[0]);
    n2 = sizeof(a22)/sizeof(a22[0]);

    showArray(a12, n1, a22, n2);
    cout << "Median is 11 = " << findMedianSortedArrays(a12, n1, a22, n2) << endl << endl;

    int b1[] = {1 };
    int b2[] = {2,3,4};
 
    n1 = sizeof(b1)/sizeof(b1[0]);
    n2 = sizeof(b2)/sizeof(b2[0]);

    showArray(b1, n1, b2, n2);
    cout << "Median is 2.5 = " << findMedianSortedArrays(b1, n1, b2, n2) << endl << endl;
    /*
    */
    return 0;
}
