#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

bool compare(int i1, int i2){
    return i1 < i2;
}
void showVec(vector<int> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ", ";
    }
    cout << vec[length-1] << endl;
}
int main(void){	
    vector<int> vec;
    vec.push_back(1); vec.push_back(-1); vec.push_back(0); vec.push_back(8);
    showVec(vec);
    sort(vec.begin(), vec.end(), compare);
    showVec(vec);
    return 0;
}