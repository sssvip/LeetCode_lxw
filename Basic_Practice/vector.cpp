#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void showVec(vector<int> & vec){
    int length = vec.size();
    if(length < 1)
        return;
    for(int i = 0; i < length-1; ++i){
        cout << vec[i] << ",";
    }
    cout << vec[length-1] << endl;
}

int main(void){
    int intArr[] = {1, 3, 2};
    vector<int> v(intArr, intArr + 3);
    showVec(v);

    v.erase(v.begin() + 2);
    showVec(v);

    //nothing changed.
    v.erase(v.begin()+1, v.begin()+1);
    showVec(v);

    //nothing changed.
    v.erase(v.begin()+v.size(), v.end());
    showVec(v);

    //nothing changed.
    v.erase(v.end(), v.end());
    showVec(v);

    //Something unexpected.
    v.erase(v.begin()+2, v.begin()+1);
    showVec(v);

    //vecotr<int>::iterator iter;
    v.insert(v.begin(), 123);
    showVec(v);
    v.insert(v.begin() + 2, 12);
    showVec(v);

    v.push_back(1);
    v.push_back(12);
    showVec(v);
    cout << "unique:" << endl;
    //Usually, unique() alone is not enough: 1.sort()  2.unique()  3.resize()
    sort(v.begin(), v.end());
    vector<int>::iterator it = unique(v.begin(), v.end());
    v.resize(distance(v.begin(), it));
    showVec(v);

    v.clear();
    showVec(v);

    return 0;
}
