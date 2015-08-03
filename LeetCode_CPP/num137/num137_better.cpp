// File: num137.cpp
// Author: lxw
// Date: 2015-08-03

/*
Num num137: Single Number II
Source: https://leetcode.com/problems/single-number-ii/

Given an array of integers, every element appears three times except for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

//Time: O(n)    Space: O(1)
// int 数据共有32位，可以用32变量存储 这 N 个元素中各个二进制位上  1  出现的次数，最后 在进行 模三 操作，如果为1，那说明这一位是要找元素二进制表示中为 1 的那一位。
//时间：O(32*N)，这是一个通用的解法，如果把出现3次改为 k 次，那么只需模k就行了。
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        int count = 0;
        int result = 0;
        for(int i = 0; i < 32; ++i){
            count = 0;
            for(int j = 0; j < length; ++j){
                if((nums[j] >> i) & 0x01 == 1){
                    ++count;
                }
            }
            result |= (count % 3) << i; //OK: result += (count % 3) << i;
        }
        return result;
    }
};