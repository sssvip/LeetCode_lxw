#include <iostream>
#include <vector>
using namespace std;

void show(vector<int> & v){
    int length = v.size();
    for(int i = 0; i < length; ++i){
        cout << v[i] << ", ";
    }
    cout << endl;
}

int main(void){
    int intArr[] = {1, 3, 2};
    vector<int> v(intArr, intArr + 3);
    show(v);
    v.erase(v.begin() + 2);
    show(v);
    return 0;
}
