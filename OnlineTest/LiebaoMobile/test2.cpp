#include <iostream>
#include <string>
using namespace std;

int main(void){
	int count;
	cin >> count;
	string word;	
	for(int i = 0; i < count; ++i){
		cin >> word;
		int arr[255] = {0};
		int length = word.length();
		for(int i = 0; i < length; ++i){
			if(arr[word[i]] == 0){
				cout << word[i];
				arr[word[i]] = 1;
			}
		}
		cout << endl;
	}	
	return 0;
}