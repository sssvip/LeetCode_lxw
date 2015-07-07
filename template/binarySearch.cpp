#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

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

//return the index.
int binSearchIndex(vector<int>& nums, int begin, int end, int target){
    int middle = 0;
    while(begin <= end){
        middle = ((long long)begin + (long long)end) / 2;
        if(nums[middle] == target){
            return middle;
        }
        else if(nums[middle] > target){
            end = middle - 1;
        }
        else{
            begin = (long long)middle + (long long)1;
        }
    }
    return -1;
}

//return bool(true/false).
bool binSearchBool(vector<int>& nums, int begin, int end, int target){
    int middle = 0;
    while(begin <= end){
        middle = ((long long)begin + (long long)end) / 2;
        if(nums[middle] == target){
            return true;
        }
        else if(nums[middle] < target){
            begin = (long long)middle + (long long)1;
        }
        else{
            end = middle - 1;
        }
    }
    return false;
}
int main(void){
	vector<int> vec;
	//[-1, 0, 1, 5, 8] must be ordered.
    vec.push_back(-1); vec.push_back(0); vec.push_back(1); vec.push_back(5); vec.push_back(8);
    showVec(vec);
    cout << binSearchIndex(vec, 0, 3, 1) << endl; //2
    cout << binSearchIndex(vec, 0, 1, 1) << endl; //-1
    cout << binSearchIndex(vec, 2, 4, 8) << endl; //4
    cout << binSearchBool(vec, 1, 3, 1) << endl; //true: 1
    cout << binSearchBool(vec, 1, 3, -1) << endl; //false: 0
    return 0;
}
