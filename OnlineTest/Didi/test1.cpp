// File: test1.cpp
// Author: lxw
// Date: 2015-09-25

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

int main(void){
	vector<vector<int> > arr;
	int num;
	string str;
	getline(cin, str);
	stringstream ss(str);	
	while(getline(ss, str, ' ')){
		//cout << str << endl;
        num = atoi(str.c_str());
       	arr.push_back(num);
    }	
	
	
	return 0;
}