#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
    //string
    string str = "hello world";
    cout << str << endl;

    //vector
    vector<int> vec;
    vec.push_back(1); vec.push_back(-1); vec.push_back(0); vec.push_back(8);
    int length = vec.size();
    for(int i = 0; i < length; ++i){
        cout << vec[i] << "\t";
    }
    cout << endl;
    
    //sort
    sort(vec.begin(), vec.end());
    for(int i = 0; i < length; ++i){
        cout << vec[i] << "\t";
    }
    cout << endl;

    //std::max
    cout << max(10, 90) << endl;
    return 0;
}
