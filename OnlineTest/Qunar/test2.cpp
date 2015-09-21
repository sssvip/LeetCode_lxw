// File: test2.cpp
// Author: lxw
// Date: 2015-09-21

#include <iostream>
#include <set>

using namespace std;

int main(void){
	int len1, len2, len3;
	int num;
	while(cin >> len1){
		set<int> s1;
		set<int> s2;
		set<int> s3;
		while(len1-- > 0){
			cin >> num;
			s1.insert(num);
		}
		cin >> len2;
		while(len2-- > 0){
			cin >> num;
			if(s1.find(num) != s1.end()){
				s2.insert(num);
			}
		}
		cin >> len3;
		while(len3-- > 0){
			cin >> num;
			if(s2.find(num) != s2.end()){
				s3.insert(num);
			}
		}
		set<int>::iterator it;
		for(it = s3.begin(); it != s3.end(); ++it){
			cout << *it << " ";
		}
		cout << endl;
	}	
	return 0;
}