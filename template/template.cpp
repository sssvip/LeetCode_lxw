#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

using namespace std;

//-----------------------------------------------------------------------
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//-----------------------------------------------------------------------
//Ignore the 'float' method.
int getMid(int start, int end){
    long long llStart = (long long)start;
    long long llEnd = (long long)end;
    return int((llStart + llEnd)/2);
}

void showVec(vector<int> & vec){
    int length = vec.size();
    if(length < 1)
    	return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ", ";
    }
    cout << vec[length-1] << endl;
}
void showVecVec(vector<vector<int>> & vvi){
    int length = vvi.size();
    if(length < 1)
        return;
    for(int i = 0; i < length; ++i){
        showVec(vvi[i]);
    }
}

void swap(int & num1, int & num2){
	int temp = num1;
	num1 = num2;
	num2 = temp;
}

void showList(ListNode * head){
    if(head == NULL){
        return;
    }
    while(head->next){
        cout << head->val << ", ";
        head = head->next;
    }
    cout << head->val << endl;
}
//-----------------------------------------------------------------------
int main(void){
    //string
    string str = "hello world";
    cout << str << endl;

    //vector
    vector<int> vec;
    vec.push_back(1); vec.push_back(-1); vec.push_back(0); vec.push_back(8);
    showVec(vec);
    
    //sort
    sort(vec.begin(), vec.end());
    showVec(vec);

    //std::max
    cout << "max: " << max(10, 90) << endl;

    cout << getMid(INT_MAX, INT_MAX) << endl;

    //2 dimensions vecotr
	vector<vector<int> > matrix;
    vec.clear();
	vec.push_back(1);vec.push_back(2);
	matrix.push_back(vec);
	vec.clear();
	vec.push_back(5);vec.push_back(6);
	matrix.push_back(vec);
    showVecVec(matrix);

    //LinkedList
    ListNode ln1 = ListNode(1);
    ListNode ln2 = ListNode(2);
    ln1.next = &ln2;
    showList(&ln1);
    return 0;
}
