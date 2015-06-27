#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

int getMid(int start, int end){
    long long llStart = (long long)start;
    long long llEnd = (long long)end;
    return int((llStart + llEnd)/2);
}
void showVec(vector<int> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ",";
    }
    cout << vec[length-1] << endl;
}

void swap(int & num1, int & num2){
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

int main(void){
    //string
    string str = "hello world";
    cout << str << endl;

    //vector
    vector<int> vec;
    vec.push_back(1); vec.push_back(-1); vec.push_back(0); vec.push_back(8);
    showVec(vec);
    
    //sort
    sort(vec.begin(), vec.end());
    showVec(vec);

    //std::max
    cout << max(10, 90) << endl;

    cout << getMid(INT_MAX, INT_MAX) << endl;
    return 0;
}
