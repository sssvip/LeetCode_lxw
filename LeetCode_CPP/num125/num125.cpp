// File: num125.cpp
// Author: lxw
// Date: 2015-07-14

/*
Num num125: Valid Palindrome
Source: https://leetcode.com/problems/valid-palindrome/

Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.
*/

class Solution {
public:
	//slow
    bool isPalindrome(string s) {
        int length = s.length();
        int head = 0;
        int tail = length - 1;
        while(head < tail){
            if(s[head] >= 'A' && s[head] <= 'Z')
                s[head] = s[head] - 'A' + 'a';
            if(!isalpha(s[head]) && !isdigit(s[head])){
                ++head;
                continue;
            }
            if(s[tail] >= 'A' && s[tail] <= 'Z')
                s[tail] = s[tail] - 'A' + 'a';
            if(!isalpha(s[tail]) && !isdigit(s[tail])){
                --tail;
                continue;
            }
            if(s[head] == s[tail]){
                ++head;
                --tail;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }

    //optimize
    bool isPalindrome(string s) {
        int length = s.length();
        int head = 0;
        int tail = length - 1;
        while(head < tail){
            if(!isalpha(s[head]) && !isdigit(s[head])){
                ++head;
                continue;
            }
            if(s[head] >= 'A' && s[head] <= 'Z')
                s[head] = s[head] - 'A' + 'a';
            while(!isalpha(s[tail]) && !isdigit(s[tail])){
                --tail;
            }
            if(s[tail] >= 'A' && s[tail] <= 'Z')
                s[tail] = s[tail] - 'A' + 'a';
            if(s[head] == s[tail]){
                ++head;
                --tail;
                continue;
            }
            else{
                return false;
            }
        }
        return true;
    }
//test case: ""  is OK.
};