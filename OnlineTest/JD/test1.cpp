// File: test1.cpp
// Author: lxw
// Date: 2015-09-18

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){
	int N;	//number of bears.
	int count;
	int j;
	bool flag = true;
	while(cin >> N){
		j = 1;
		flag = true;
		while(1){
			count = N * j + 1;
			for(int i = N-1; i > 0; --i){
				if(count * N % (N - 1) != 0){	//can not divide exactly.
					flag = false;
					break;
				}
				count = count * N / (N - 1) + 1;
			}
			if(flag){
				cout << count << endl;
				break;
			}
			else{
				flag = true;
				++j;
			}
		}
	}
	return 0;
}