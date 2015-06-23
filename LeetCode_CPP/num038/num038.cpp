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
#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
using namespace std;

class Solution {
private:
    char * reverse(char * arr){
        int length = strlen(arr);
        int middle = length / 2;
        char ch;
        for(int i = 0; i < middle; ++i){
            ch = arr[i];
            arr[i] = arr[length-1-i];
            arr[length-1-i] = ch;
        }
        return arr;
    }

    string int2String(int number){
        char t[24];
        int i = 0;	 
        while (number) {
            t[i++] = (number % 10) + '0';
            number /= 10;
        }
        t[i] = 0;	 
        //char* -> string
        return string(reverse(t));
    }
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
            	//stringstream is much too slow.
                stringstream ss;
                ss << count;
                ss << ch;
                result += ss.str();
                */
                //result += count + '0';// if count > 9, wrong Answer.
                result += int2String(count);
                result += ch;
                ch = number[i];
                count = 1;
            }
        }
        /*
        //stringstream is much too slow.
        stringstream ss;
        ss << count;
        ss << ch;
        result += ss.str();
        */
        //result += count + '0'; // if count > 9, wrong Answer.
        result += int2String(count);
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

int main(void){
	Solution sol;
    clock_t start, end;
    start = clock();
	cout << sol.countAndSay(50) << endl;
    end = clock();
    cout << "Run time: " << (double)(end-start)/CLOCKS_PER_SEC << "S" << endl;
	return 0;
}
