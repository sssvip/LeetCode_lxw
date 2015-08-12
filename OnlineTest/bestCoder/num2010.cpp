// File: num2010.cpp
// Author: lxw
// Date: 2015-08-10
// Source: http://acm.acmcoder.com/showproblem.php?pid=2010

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void){
	int a, b;
	int hundred, ten, one;
	bool flag;
	while(cin >> a >> b){
		flag = false;		
        //If the following 2 lines exist, Compilation Error on the OJ.
		//a = std::max(a, 100);
		//b = std::min(b, 999);
		if(a > b){
			cout << "no" << endl;
			continue;
		}
		for(int i = a; i <= b; ++i){
			hundred = i / 100;
			ten = (i % 100) / 10;
			one = (i % 100) % 10;
			if(hundred * hundred * hundred + ten * ten * ten + one * one * one == i){
                //NOTE: if the " " in the end of the line, presentation error.
				if(flag == false){				
					flag = true;
					cout << i;
				}
				else{
					cout << " " << i;
				}
			}
		}
		if(flag){
			cout << endl;
		}		
		else{
			cout << "no" << endl;
		}
	}
	return 0;
}
