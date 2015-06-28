// File: num049.cpp
// Author: lxw
// Date: 2015-06-27

/*
Num num049: 
Source: 

*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;;

bool isAnagram(string& str1, string& str2){
    sort(str1.begin(), str1.end());
    sort(str2.begin(), str2.end());
    //cout << &str1 << ", " << &str2 << endl; // Even the 2 strings are equal, their address are not equal.
    return str1 == str2;
}

bool isAnagram1(string& str1, string& str2){
    vector<int> letters1(26, 0);
    vector<int> letters2(26, 0);
    int length = str1.length();
    for(int i = 0; i < length; ++i){
        ++letters1[str1[i] - 'a'];
    }
    length = str2.length();
    for(int i = 0; i < length; ++i){
        ++letters2[str2[i] - 'a'];
    }
    for(int i = 0; i < 26; ++i){
        if(letters1[i] != letters2[i])
            return false;
    }
    return true;
}

int main(void){
    string str1 = "hello";
    string str2 = "lhloe";
    cout << isAnagram(str1, str2) << endl;
    cout << isAnagram1(str1, str2) << endl;
    return 0;
}
