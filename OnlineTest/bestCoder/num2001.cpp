// File: num2001.cpp
// Author: lxw
// Date: 2015-08-10
// Source: http://acm.acmcoder.com/showproblem.php?pid=2001

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
using namespace std;

int main(void){
	double a, b, c, d;  //NOTE: be carefull. it's double not int;
	while(cin >> a >> b >> c >> d){
		printf("%.2f\n", sqrt((a-c)*(a-c)+(b-d)*(b-d)));
	}
	return 0;
}
