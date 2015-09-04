// File: num274.cpp
// Author: lxw
// Date: 2015-09-04

/*
Num num274: H-Index 
Source: https://leetcode.com/problems/h-index/

Given an array of citations (each citation is a non-negative integer) of a researcher, write a function to compute the researcher's h-index.

According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each, and the other N − h papers have no more than h citations each."

For example, given citations = [3, 0, 6, 1, 5], which means the researcher has 5 papers in total and each of them had received 3, 0, 6, 1, 5 citations respectively. Since the researcher has 3 papers with at least 3 citations each and the remaining two with no more than 3 citations each, his h-index is 3.

Note: If there are several possible values for h, the maximum one is taken as the h-index.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int length = citations.size();
        int result = 0;
        int count;  // <
        int equal;  // = 
        while(result < length){
            count = 0;
            equal = 0;
            for(int i = 0; i < length; ++i){
                if(citations[i] < length - result){
                    ++count;
                    if(count > result)
                        break;
                }
                else if(citations[i] == length - result){
                    ++equal;
                }
            }
            if(count == result || (count < result && count + equal >= result))
                return length - result;
            ++result;
        }
        return 0;
    }
};