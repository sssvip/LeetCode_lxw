// File: num038.cpp
// Author: lxw
// Date: 2015-06-17

/*
Num num038: Count and Say
Source: https://leetcode.com/problems/count-and-say/

The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
*/

class Solution {
public:
    string say(string number){
        int length = number.length();
        string result = "";
        char ch = number[0];
        int  count = 1;
        for(int i = 1; i < length; ++i){
            if(number[i] == ch){
                ++count;
            }
            else{
            	/*
            	//stringstream is very slow.
                stringstream ss;
                ss << count;
                ss << ch;
                result += ss.str();
                */
                result += count + '0';
                result += ch;
                ch = number[i];
                count = 1;
            }
        }
        /*
        //stringstream is very slow.
        stringstream ss;
        ss << count;
        ss << ch;
        result += ss.str();*/
        result += count + '0';
        result += ch;
        return result;
    }
    string countAndSay(int n) {
        string result = "1";
        for(int i = 1; i < n; ++i){
            result = say(result);
        }
        return result;
    }
};