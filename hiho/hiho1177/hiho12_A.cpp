// File: hiho12_A.cpp
// Author: lxw
// Date: 2015-06-14

/*
Num hiho12_A: 顺子
Source: http://hihocoder.com/problemset/problem/1177

时间限制:6000ms
单点时限:1000ms
内存限制:256MB
描述
你在赌场里玩梭哈，已经被发了4张牌，现在你想要知道发下一张牌后你得到顺子的概率是多少？

假定赌场使用的是一副牌，四种花色的A、2、3、...、J、Q、K共52张，这副牌只发给你了4张，你的剩下一张牌从剩下48张中任意取出一张。

顺子指的是点数连续的五张牌，包括10、J、Q、K、A这种牌型（不包含同花顺，即构成顺子的五张牌花色不能相同）。参见：https://zh.wikipedia.org/wiki/%E6%92%B2%E5%85%8B%E7%89%8C%E5%9E%8B#.E7.89.8C.E5.9E.8B

输入
一行四个被空格隔开的长度为2或3的字符串，XY，表示你手里的牌。

X为2~10、J、Q、K、A中一个，表示点数，Y为S、H、C、D分别表示黑桃、红心、梅花和方块。

输出
一行一个分数表示概率，注意你的分数需为最简分数，若答案为0输出0/1。

样例输入
10S JS QS KD
样例输出
1/6
*/

//NOTES:
//题意要理解对: A? 2? 3? 4? & J? Q? K? A? 的特殊情况要考虑到
//众多坑在代码中标注


#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int getIndex(char ch, int i){
    switch(ch){
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return ch - '1';
        case 'J':
            return 10;
        case 'Q':
            return 11;
        case 'K':
            return 12;
        case 'A':
            //Traps and Pitfalls. Special case(A): A 2 3 4 & J Q K A
            if(i == 2){
                return 0;
            }
            else{
                return 13;
            }
        default:
            return -1;
    }
}

void dealStr(const string& str, vector<char>& color){//const string & ?
    int length = str.length();
    //Traps and Pitfalls   4 instead of 3, because of strlen()
    vector<char> str1(4, '\0');
    int j = 0;
    int i = 0;
    for(; i < length; ++i){
        if(str[i] == ' '){
            if(strlen(&str1[0]) == 3){   // 10S 10H 10C 10D
                color[9] = str1[2];
            }
            else{ // other than 10
                color[getIndex(str1[0], i)] = str1[1];
            }
            j = 0;
            for(int k = 0; k < 3; ++k){
                str1[k] = '\0';
            }
        }
        else{
            str1[j++] = str[i];
        }
    }
    //The last one has no ' ' to assign for color
    if(strlen(&str1[0]) == 3){   // 10S 10H 10C 10D
        color[9] = str1[2];
    }
    else{ // other than 10
        color[getIndex(str1[0], i)] = str1[1];
    }
}

void span(vector<char>& color, int& length1, int& index1, int& length2, int& index2){
    for(int i = 0; i < 14; ++i){
        int length = 0;
        //Traps and Pitfalls. C/C++ array has no boundary.
        //while(color[i] != '\0'){
        while(color[i] != '\0' && i < 14){
            ++length;
            ++i;
        }
        if(length != 0){
            if(length1 != 0){
                length2 = length;
                index2 = i - length;
            }
            else{
                length1 = length;
                index1 = i - length;
            }
        }
    }
}

int main(void){
    string str;
    //color should NOT be here.
    //vector<char> color(14, '\0');
    int length1 = 0;
    int length2 = 0;
    int index1 = 0;
    int index2 = 0;
    while(getline(cin, str)){
        //Traps and Pitfalls. Color must be reset every time.
        vector<char> color(14, '\0');
        if(str == ""){
            break;
        }
        dealStr(str, color);
        length1 = 0;
        length2 = 0;
        index1 = 0;
        index2 = 0;
        span(color, length1, index1, length2, index2);
        if(length2 == 0){
            if(length1 == 4){
                bool sameColor = true;
                char ch = color[index1];
                for(int i = 1; i < length1; ++i){
                    if(color[index1+i] != ch){
                        sameColor = false;
                        break;
                    }
                }
                string result = "";
                if(index1 == 0 || index1 + length1 - 1 == 13){
                    result = sameColor ? "1/16" : "1/12";
                }
                else{
                    result = sameColor ? "1/8" : "1/6";
                }
                cout << result << endl;
            }
            else{
                //Traps and Pitfalls. "0/1" instead of "0".
                cout << "0/1" << endl;
                continue;
            }
        }
        else{
            if(index2 + length2 - 1 - index1 == 4){
                bool sameColor = true;
                char ch = color[index1];
                for(int i = 1; i < length1; ++i){
                    if(color[index1+i] != ch){
                        sameColor = false;
                        break;
                    }
                }
                if(sameColor){
                    for(int i = 0; i < length2; ++i){
                        if(color[index2+i] != ch){
                            sameColor = false;
                            break;
                        }
                    }
                }
                string result = sameColor ? "1/16" : "1/12"; 
                cout << result << endl;
            }
            else{
                //Traps and Pitfalls. "0/1" instead of "0".
                cout << "0/1" << endl;
                continue;
            }
        }
    }
    return 0;
}
