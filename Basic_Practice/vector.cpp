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

    //nothing changed.
    v.erase(v.begin()+1, v.begin()+1);
    show(v);

    //nothing changed.
    v.erase(v.begin()+v.size(), v.end());
    show(v);

    //nothing changed.
    v.erase(v.end(), v.end());
    show(v);

    //Something unexpected.
    v.erase(v.begin()+2, v.begin()+1);
    show(v);

    //vecotr<int>::iterator iter;
    v.insert(v.begin(), 123);
    show(v);

    return 0;
}
