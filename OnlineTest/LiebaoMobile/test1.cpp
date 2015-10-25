#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void splitCount(string & str, int start, int end, int & count, unordered_set<string> & dict){
	//cout << "start: " << start << ", end: " << end << endl;
	if(start > end){
		++count;
		count = count >= 10000 ? count % 10000 : count;
		return;
	}
	string word;	
	for(int i = start; i <= end; ++i){
		word = str.substr(start, i-start+1);
		if(dict.find(word) != dict.end()){
			splitCount(str, i+1, end, count, dict);
		}
		else
			break;
	}
}

int main(void){
	int dictSize;
	cin >> dictSize;
	string word;
	unordered_set<string> dict;
	for(int i = 0; i < dictSize; ++i){
		cin >> word;
		dict.insert(word);
	}
	string targetStr;
	cin >> targetStr;
	int length = targetStr.length();
	int count = 0;
	splitCount(targetStr, 0, length-1, count, dict);	
	cout << count << endl;
	return 0;
}