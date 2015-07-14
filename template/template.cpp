#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
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

int getMin(vector<int> & vec){
    int length = vec.size();
    if(length == 0)
        return INT_MIN;
    if(length == 1)
        return vec[0];
    int min1 = vec[0];    
    for(int i = 1; i < length; ++i){
        if(vec[i] < min1)
            min1 = vec[i];
    }
    return min1;
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

void showPairSet(const set<pair<int, int> > & pairs){
    for(const pair<int, int> & item : pairs)    // the 'const' in this line is essential.
        cout << item.first << ", " << item.second << endl;
}

void showSet(const set<int> & ints){
    for(int number : ints)
        cout << number << ", ";
    cout << endl;
}

//-----------------------------------------------------------------------
int main(void){    
    //string
    cout << "string" << endl;
    string str = "hello world";
    cout << str << endl << endl;

    //vector
    vector<int> vec;
    vec.push_back(1); vec.push_back(-2); vec.push_back(0); vec.push_back(8);
    showVec(vec);
    //min(vec)
    cout << "min of vec: " << getMin(vec) << endl << endl;
    
    //sort
    cout << "sort vector:" << endl;
    sort(vec.begin(), vec.end());
    showVec(vec);
    cout << endl;
    
    //getMid
    cout << getMid(INT_MAX, INT_MAX) << endl;
    cout << getMid(INT_MIN, INT_MAX) << endl;
    cout << "getMid()." << endl << endl;

    //2 dimensions vector
    cout << "2 dimensions vector:" << endl;
	vector<vector<int> > matrix;
    vec.clear();
	vec.push_back(1);vec.push_back(2);
	matrix.push_back(vec);
	vec.clear();
	vec.push_back(5);vec.push_back(6);
	matrix.push_back(vec);
    showVecVec(matrix);
    cout << endl;

    //LinkedList
    cout << "LinkedList: " << endl;
    ListNode ln1 = ListNode(1);
    ListNode ln2 = ListNode(2);
    ln1.next = &ln2;
    showList(&ln1);
    cout << endl;

    //pairs set
    cout << "pairs set:" << endl;
    set<pair<int, int> > pairSet;
    pairSet.insert(pair<int, int>(0, 2));
    pairSet.insert(pair<int, int>(1, 2));
    pairSet.insert(pair<int, int>(1, 2));   //only one (1,2) exists in pairSet
    showPairSet(pairSet);
    if(pairSet.find(pair<int, int>(1, 2)) != pairSet.end())
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    if(pairSet.find(pair<int, int>(4, 2)) != pairSet.end())
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;
    cout << endl;

    //ints set
    cout << "ints set:" << endl;
    set<int> ints;
    ints.insert(1);ints.insert(0);ints.insert(3);ints.insert(2);ints.insert(11);ints.insert(5);ints.insert(13);ints.insert(27);
    showSet(ints);
    cout << endl;
    return 0;
}
