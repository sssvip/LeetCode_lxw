// File: vec_push_back_vec_deep_copy.cpp
// Author: lxw
// Date: 2015-07-10
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

void showVec(vector<int> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ", ";
    }
    cout << vec[length-1] << endl;
}
void showVecVec(vector<vector<int>> & vvi){
    int length = vvi.size();
    if(length < 1)
        return;
    for(int i = 0; i < length; ++i){
        showVec(vvi[i]);
    }
}
int main(void){
    vector<vector<int> > vvi;
    vector<int> vi;
    vi.push_back(1); vi.push_back(-1); 
    vvi.push_back(vi);	//deep copy
    showVec(vi);		//1, -1
    showVecVec(vvi);    //1, -1

    vi.push_back(2);vi.push_back(3);
    showVec(vi);        //1, -1, 2, 3
    showVecVec(vvi);    //1, -1
    vvi[0].push_back(-1);vvi[0].push_back(-1);
    showVec(vi);        //1, -1, 2, 3
    showVecVec(vvi);    //1, -1, -1, -1
    return 0;
}

/*
Output:
1, -1
1, -1
1, -1, 2, 3
1, -1
1, -1, 2, 3
1, -1, -1, -1
*/