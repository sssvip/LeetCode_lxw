// File: practice1.cpp
// Author: lxw
// Date: 2015-09-18

#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(void){
	double result = 0;
	int n, m;
	double temp;
	while(cin >> n >> m){
		result = n;
		temp = n;
		for(int i = 1; i < m; ++i){
			temp = sqrt(temp);
			result += temp;
		}
		cout << setprecision(2) << fixed << result << endl;
	}
	return 0;
}