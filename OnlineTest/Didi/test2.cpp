// File: test2.cpp
// Author: lxw
// Date: 2015-09-25

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//return the end index.
int find(vector<int>& arr, int start, int length, int target){
	if(target == 0)
		return start-1;
	if(start == length)
		return -1;
	return find(arr, start+1, length, target-arr[start]);
}

int main(void){
	vector<int> arr;
	int num;
	string str;
	getline(cin, str);
	stringstream ss(str);	
	while(getline(ss, str, ' ')){
		//cout << str << endl;
        num = atoi(str.c_str());
       	arr.push_back(num);
    }	
	//cout << "end" << endl;
	int length = arr.size();
	int start, end;
	int startMax = -1;
	int endMax = -1;
	int maxLength = -1;
	for(int i = 0; i < length; ++i){
		start = i;
		if((end = find(arr, i+1, length, -arr[i])) != -1){
			if(end - start > maxLength){
				startMax = start;
				endMax = end;
				maxLength = end - start;
			}
		}
	}
	if(startMax != -1 && endMax != -1){
		for(int i = startMax; i <= endMax; ++i){
			cout << arr[i] << " ";
		}
		cout << endl;
	}
	
	return 0;
}