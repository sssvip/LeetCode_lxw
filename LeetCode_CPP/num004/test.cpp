#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char ** argv){
    vector<int> a(0);
    for(int i = 0; i < 10; ++i){
        a.push_back(i);
    }
    int length = a.size();

    vector<int> b(0);
    for(int i = 0; i < 5; ++i){
        b.push_back(a[i]);
    }
    for(int i = 0; i < 5; ++i){
        cout << b[i] << endl;
    }
}
