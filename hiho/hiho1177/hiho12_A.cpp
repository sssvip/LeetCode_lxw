// File: hiho12_A.cpp
// Author: lxw
// Date: 2015-06-14

/*
Num hiho12_A: 顺子
Source: http://hihocoder.com/contest/challenge12/solution/437014

*/


#include <iostream>
#include <string>
#include <cstring>
#include <vector>
using namespace std;

int getIndex(char ch){
    switch(ch){
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
            return ch - '2';
        case 'J':
            return 9;
        case 'Q':
            return 10;
        case 'K':
            return 11;
        case 'A':
            return 12;
        default:
            return -1;
    }
}

void dealStr(const string& str, vector<char>& color){//const string & ?
    int length = str.length();
    vector<char> str1(4, '\0');
    int j = 0;
    int i = 0;
    for(; i < length; ++i){
        if(str[i] == ' '){
            if(strlen(&str1[0]) == 3){   // 10S 10H 10C 10D
                color[8] = str1[2];
            }else{ // other than 10
                color[getIndex(str1[0])] = str1[1];
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
    if(strlen(&str1[0]) == 3){   // 10S 10H 10C 10D
        color[8] = str1[2];
    }else{ // other than 10
        color[getIndex(str1[0])] = str1[1];
    }
    j = 0;
    for(int k = 0; k < 3; ++k){
        str1[k] = '\0';
    }
}

void span(vector<char>& color, int& length1, int& index1, int& length2, int& index2){
    for(int i = 0; i < 13; ++i){
        int length = 0;
        while(color[i]){
            ++length;
            ++i;
        }
        if(length1 != 0){
            if(length != 0){
                length2 = length;
                index2 = i - length;
            }
        }
        else{
            length1 = length;
            index1 = i - length;
        }
    }
}

int main(void){
    string str;
    vector<char> color(13, '\0');
    int length1 = 0;
    int length2 = 0;
    int index1 = 0;
    int index2 = 0;
    while(getline(cin, str)){
        if(str == ""){
            break;
        }
        dealStr(str, color);
        /*
        for(int i = 0; i < 13; ++i){
            cout << color[i] << endl;
        }
        */
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
                if(index1 == 0 || index1 + length1 - 1 == 12){
                    result = sameColor ? "1/16" : "1/12";
                }
                else{
                    result = sameColor ? "1/8" : "1/6";
                }

                cout << result << endl;
            }
            else{
                cout << 0 << endl;
                continue;
            }
        }
        else{
            if(index2 + length2 - 1 - index1 == 4){
                //int index = index2 - 1;
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
                cout << 0 << endl;
                continue;
            }
        }
    }
    return 0;
}
