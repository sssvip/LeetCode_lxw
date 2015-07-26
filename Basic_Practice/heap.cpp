#include <iostream>
#include <vector>
#include <algorithm>//make_heap(), push_heap(), pop_heap(), sort_heap()
using namespace std;

void show(vector<int>& v){
    int length = v.size();
    for(int i = 0; i < length; ++i){
        cout << v[i] << ", ";
    }
    cout << endl;
}

//default "max_heap"

int main(void)
{
    int myInts[] = {10, 20, 30, 5, 15};
    vector<int> v(myInts, myInts + 5);
    show(v);
    //make_heap
    cout << "make heap:" << endl;
    make_heap(v.begin(), v.end());
    show(v);
    cout << endl;
    
    //rebuild_heap
    cout << "rebuild heap:" << endl;
    v.push_back(25);
    push_heap(v.begin(), v.end());
    show(v);
    cout << endl;

    //delete max
    cout << "delete max:" << endl;
    pop_heap(v.begin(), v.end());
    show(v);    //NOTE this output
    v.pop_back();
    show(v);    //Compare with the output between this and the former one.
    cout << endl;

    //sort
    cout << "sort heap:" << endl;
    sort_heap(v.begin(), v.end());
    show(v);
    cout << endl;
    return 0;
}

/*
lxw@17:46:43:Basic_Practice$ ./a.out 
10, 20, 30, 5, 15, 
make heap:
30, 20, 10, 5, 15, 

rebuild heap:
30, 20, 25, 5, 15, 10, 

delete max:
25, 20, 10, 5, 15, 30, 
25, 20, 10, 5, 15, 

sort heap:
5, 10, 15, 20, 25, 
*/
