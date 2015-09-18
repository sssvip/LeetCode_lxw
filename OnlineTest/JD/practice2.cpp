// File: practice2.cpp
// Author: lxw
// Date: 2015-09-18

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

bool isFlower(int num){
	int temp = num;
	int hundred = temp / 100;
	temp = temp % 100;
	int ten = temp / 10;
	int one = temp % 10;
	temp = hundred * hundred * hundred + ten * ten * ten + one * one * one;
	return temp == num;
}

int main(void){
	int m, n;
	bool flag;
	while(cin >> m >> n){
		flag = false;
		for(int i = m; i <= n; ++i){
			if(isFlower(i)){
				flag = true;
				cout << i << " ";
			}
		}
		if(flag)
			cout << endl;
		else
			cout << "no" << endl;
	}
	return 0;
}