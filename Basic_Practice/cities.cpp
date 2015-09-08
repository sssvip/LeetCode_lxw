// File: cities.cpp
// Date: 2015-09-08

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>
#include <unordered_set>
#include <unordered_map>

using namespace std;

void showVec(vector<int> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ", ";
    }
    cout << vec[length-1] << endl;
}

void solution(vector<int> & distances, unordered_map<int, unordered_set<int> > & ism, int node, unordered_set<int> & used, int distance){
	unordered_set<int>::iterator it;
	for(it = ism[node].begin(); it != ism[node].end(); ++it){
		if(used.find(*it) == used.end()){
			++distances[distance];
			used.insert(*it);
			solution(distances, ism, *it, used, distance+1);
		}
	}
}

vector<int> solution(vector<int> &T){
	vector<int> distances;
	int length = T.size();
	if(length == 1){
		return distances;
	}
	distances.resize(length-1, 0);
	unordered_map<int, unordered_set<int> > intSetMap;
	int root = 0;
	for(int i = 0; i < length; ++i){
		if(T[i] == i)
			root = i;
		intSetMap[i].insert(T[i]);
		intSetMap[T[i]].insert(i);
	}
	
	unordered_set<int> used;
	used.insert(root);
	int distance = 0;
	unordered_set<int>::iterator it;
	for(it = intSetMap[root].begin(); it != intSetMap[root].end(); ++it){
		if(used.find(*it) == used.end()){
			used.insert(*it);
			solution(distances, intSetMap, *it, used, distance+1);
			++distances[distance];
		}
	}	
	return distances;
}

int main(void){
	//vector
    vector<int> vec;
    vec.push_back(9); vec.push_back(1); vec.push_back(4);
    vec.push_back(9); vec.push_back(0); vec.push_back(4);
    vec.push_back(8); vec.push_back(9); vec.push_back(0); vec.push_back(1);
    //showVec(vec);
	vector<int> result = solution(vec);
	showVec(result);
	return 0;
}