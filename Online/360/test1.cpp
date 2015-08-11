// File: test1.cpp
// Author: lxw
// Date: 2015-08-11

#include <iostream>
#include <vector>
using namespace std;

int main(void){
	int T, n, m, n1, n2, length;
	cin >> T;
	while(T-- > 0){
		cin >> n >> m;
		int arr1[100001] = {0};
		int arr2[100001] = {0};
		vector<int> result;
		while(m-- > 0){
			cin >> n1 >> n2;
			if(n1 != n2){
				++arr1[n2];				
				++arr2[n1];
			}
		}		
		for(int i = 0; i < 100001; ++i){
			if(arr1[i] == n-1 && arr2[i] == 0)
				result.push_back(i);
		}
		length = result.size();
		cout << length << endl;
		if(length > 0){
			for(int i = 0; i < length-1; ++i){
				cout << result[i] << " ";
			}
			cout << result[length-1] << endl;
		}
		else{
			cout << endl;
		}
	}
	return 0;
}