// File: test2.cpp
// Author: lxw
// Date: 2015-08-11

#include <iostream>
#include <climits>
using namespace std;

int main(void){
	int T;
	cin >> T;
    getchar();  //newline
    char ch;
    int position;
    int result;
    int index;
	while(T-- > 0){
		int str[95] = {0};
		int pos[95];
		position = 0;
		result = INT_MAX;
        while(1){
			ch = getchar();
			++position;
	        if(ch == '\n')
	            break;
	        else{
	        	++str[ch-0x21];
	        	pos[ch-0x21] = position;
	        }
        }
        for(int i = 0; i < 95; ++i){
        	if(str[i] == 1){
        		if(result > pos[i]){
        			result = pos[i];
        			index = i;
        		}
        	}
        }
        cout << (char)(index + 33) << endl;
	}
	return 0;
}
