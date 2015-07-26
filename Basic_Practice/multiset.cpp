//File: multiset.cpp
//Author: lxw
//Time: 2015-07-26
//Usage: Demo for multiset.

#include <iostream>
#include <set>

using namespace std;

int main(void){
    multiset<int> msi;
    for(int i = 0; i < 10; ++i){
        msi.insert(i * 10); //0, 10, 20, ... 90
    }
    for(auto it = msi.begin(); it != msi.end(); ++it){
        cout << *it << endl;
    }
    cout << endl;
    //lower_bound 第一个>=的元素 upper_bound 第一个>的元素 所以中间的就是==的元素
    cout << *(msi.lower_bound(13)) << endl; //20
    cout << *(msi.upper_bound(13)) << endl; //20

    cout << *(msi.lower_bound(30)) << endl; //30
    cout << *(msi.upper_bound(30)) << endl; //40

    cout << *(msi.lower_bound(90)) << endl; //90
    if(msi.upper_bound(90) != msi.end())
        cout << *(msi.upper_bound(90)) << endl; //10
    else
        cout << "end()" << endl;

    if(msi.lower_bound(120) != msi.end())
        cout << *(msi.lower_bound(120)) << endl; //10
    else
        cout << "end()" << endl;
    if(msi.upper_bound(120) != msi.end())
        cout << *(msi.upper_bound(120)) << endl; //10
    else
        cout << "end()" << endl;

    if(msi.lower_bound(190) != msi.end())
        cout << *(msi.lower_bound(190)) << endl; //10
    else
        cout << "end()" << endl;
    if(msi.upper_bound(190) != msi.end())
        cout << *(msi.upper_bound(190)) << endl; //10
    else
        cout << "end()" << endl;
    return 0;
}
