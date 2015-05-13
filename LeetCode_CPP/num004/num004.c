// Source : https://oj.leetcode.com/problems/median-of-two-sorted-arrays/
// Author : Hao Chen
// Date   : 2014-07-22

/********************************************************************************** 
* 
* There are two sorted arrays A and B of size m and n respectively. 
* Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
*               
**********************************************************************************/
#include <stdio.h>

int min(int num1, int num2){
    return num1 > num2 ? num2 : num1;
}

double findKthMin(int A[],int m,int B[],int n,int k) {
    if (m > n)                                  //A中的个数 始终小于 B 中的元素个数
        return findKthMin(B,n,A,m,k);
    if (m == 0)
       return B[k -1];                          //如果 A为空 则直接返回B中的第k小的数值
    if (k == 1)                                 //如果是第一小的数 只需比较两个数组的第一个元素
        return A[0] < B[0] ? A[0] : B[0];     
    
    int posA = min(k/2,m);                      //确定A数组中要找的第X小的数，防止其小于k/2
    int posB = k - posA;
    if (A[posA - 1] == B[posB - 1])            //两个k/2相等 则返回任意一个
        return A[posA - 1];
    if (A[posA - 1] < B[posB - 1])             //否则分两种情况返回
        return findKthMin(A + posA,m - posA,B,n,k - posA);
    else if (A[posA - 1] > B[posB - 1])
        return findKthMin(A,m,B + posB,n - posB,k - posB);
}
double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if ((m + n) % 2)
        return findKthMin(A,m,B,n,(m + n) / 2 + 1);
    else
        return ( findKthMin(A,m,B,n,(m + n) / 2) +
                 findKthMin(A,m,B,n,(m + n) / 2 + 1) ) / 2;
}

int main(int argc, char ** argv){
    int r1[] = {1};
    int r2[] = {2};
 
    int n1 = sizeof(r1)/sizeof(r1[0]);
    int n2 = sizeof(r2)/sizeof(r2[0]);

    printf("Median is 1.5 = %f\n", findMedianSortedArrays(r1, n1, r2, n2));

    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45, 50};
 
    n1 = sizeof(ar1)/sizeof(ar1[0]);
    n2 = sizeof(ar2)/sizeof(ar2[0]);

    printf("Median is 17 = %f\n", findMedianSortedArrays(ar1, n1, ar2, n2));

    int ar11[] = {1, 12, 15, 26, 38};
    int ar21[] = {2, 13, 17, 30, 45 };
 
    n1 = sizeof(ar11)/sizeof(ar11[0]);
    n2 = sizeof(ar21)/sizeof(ar21[0]);

    printf("Median is 16 = %f\n", findMedianSortedArrays(ar11, n1, ar21, n2));

    int a1[] = {1, 2, 5, 6, 8 };
    int a2[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a1)/sizeof(a1[0]);
    n2 = sizeof(a2)/sizeof(a2[0]);

    printf("Median is 10.5 = %f\n", findMedianSortedArrays(a1, n1, a2, n2));

    int a10[] = {1, 2, 5, 6, 8, 9, 10 };
    int a20[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a10)/sizeof(a10[0]);
    n2 = sizeof(a20)/sizeof(a20[0]);

    printf("Median is 9.5 = %f\n", findMedianSortedArrays(a10, n1, a20, n2));

    int a11[] = {1, 2, 5, 6, 8, 9 };
    int a21[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a11)/sizeof(a11[0]);
    n2 = sizeof(a21)/sizeof(a21[0]);

    printf("Median is 9 = %f\n", findMedianSortedArrays(a11, n1, a21, n2));

    int a12[] = {1, 2, 5, 6, 8 };
    int a22[] = {11, 13, 17, 30, 45, 50};
 
    n1 = sizeof(a12)/sizeof(a12[0]);
    n2 = sizeof(a22)/sizeof(a22[0]);

    printf("Median is 11 = %f\n", findMedianSortedArrays(a12, n1, a22, n2));

    int b1[] = {1 };
    int b2[] = {2,3,4};
 
    n1 = sizeof(b1)/sizeof(b1[0]);
    n2 = sizeof(b2)/sizeof(b2[0]);

    printf("Median is 2.5 = %f\n", findMedianSortedArrays(b1, n1, b2, n2));
    return 0;
}
