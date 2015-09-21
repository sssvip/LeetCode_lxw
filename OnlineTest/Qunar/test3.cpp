/*
思路:
分别维护两个map:
map<int, int> holding; 持有锁的id和pid的对应关系(若一个pid持有多个锁,则将其分开)
map<int, vecotr<int> > waiting; 请求的锁id, pid数组(可能有多个线程等待同一个锁)
遍历waiting,取该锁在holding中是否被其他线程持有,如果没有则不存在死锁;否则若被其他线程持有,则递归查找该线程的等待的在waiting,直到找到环.
并且把这些锁id从map中删除.
*/
// File: test3.cpp
// Author: lxw
// Date: 2015-09-21

#include <iostream>
#include <string>
#include <set>

using namespace std;

int main(void){
	int count;
	int pid;
	int holding, waiting;
	while(cin >> count){
		string input;
		while(count-- > 0){
			cin >> input;
			stringstream ss(input);
    		string splitStr;    		
		    if(getline(ss, numStr, '\t')){
		    	stringstream pidss(numStr);
		        pidss >> pid;
		    }
		    if(getline(ss, numStr, '\t')){
		    	stringstream holdingss(numStr);
		    	vector<int> hVec;
		    	while(getline(holdingss, holding, ',')){
		    		stringstream temp(holding);
		    		int num;
		    		temp >> num;
		    		hVec.push_back(num);
		    	}
		    }
		    if(getline(ss, numStr, '\t')){
		    	waiting = numStr;
		    }
		    map<int, int> holding;
		    map<int, vecotr<int> > waiting;
		    //
		}
	}
	return 0;
}