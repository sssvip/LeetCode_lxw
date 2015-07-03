//File: intFloatDoubleBytes.cpp
//Author: lxw
//Time: 2015-06-27

#include <iostream>
#include <cstdio>
#include <cfloat>
#include <cstdlib>
#include <climits>
using namespace std;

int main(void){
	cout << "int 类型能存储的最大值和最小值" << endl;
	cout << "INT_MAX = " << INT_MAX << endl;
	cout << "INT_MIN = " << INT_MIN << endl;
	cout << "long 类型能存储的最大值和最小值" << endl;
	cout << "LONG_MAX = " << LONG_MAX << endl;
	cout << "LONG_MIN = " << LONG_MIN << endl;
	cout << "long long 类型能存储的最大值和最小值" << endl;
	cout << "LONG_LONG_MAX = " << LONG_LONG_MAX << endl;
	cout << "LONG_LONG_MIN = " << LONG_LONG_MIN << endl;
	cout << "float 类型能存储的最大值和最小值" << endl;
	cout << "FLT_MAX = " << FLT_MAX << endl;
	cout << "FLT_MIN = " << FLT_MIN << endl;
	
	if(FLT_MIN > 0)
		cout << "Pos" << endl;
	else
		cout << "Neg" << endl;

	cout << "double 类型能存储的最大值和最小值" << endl;
	cout << "DBL_MAX = " << DBL_MAX << endl;
	cout << "DBL_MIN = " << DBL_MIN << endl;
    long long num1 = INT_MAX;
    long long num2 = INT_MAX;
    cout << num1 * num2 << endl;
    num1 = INT_MIN;
    num2 = INT_MIN;
    cout << num1 * num2 << endl;

    return 0;
}
