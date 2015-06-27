// function utilities.

#include <iostream>
#include <vector>
using namespace std;


void swap(int & num1, int & num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}
void show(vector<int> & arr){
	int length = arr.size();
	for(int i = 0; i < length; ++i){
		cout << arr[i] << ", ";
	}
	cout << endl;
}

int main(void){
	vector<int> vec;
	vec.push_back(1);vec.push_back(2);vec.push_back(3);vec.push_back(4);
	show(vec);
	swap(vec[1], vec[2]);	// OK and right.
	show(vec);
	//swap(10, 20);	//NO: right-value CANNOT be reference type.
	return 0;
}
