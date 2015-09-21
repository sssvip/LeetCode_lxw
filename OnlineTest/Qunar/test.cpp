#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

int main(void){
	set<int> s;
	int arr[] = {10, 39, 45, 2, 1, 0, -1, 90};
	for(int i = 0; i < 8; ++i){
		s.insert(arr[i]);
	}
	set<int>::iterator it;
	for(it = s.begin(); it != s.end(); ++it){
		cout << *it << endl;
	}
	return 0;
}