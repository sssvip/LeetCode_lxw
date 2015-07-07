#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

int main(void){
    char * end;
    //warning: deprecated conversion from string constant to ‘char*’ [-Wwrite-strings] 
    //char * str = " 192.168 521.12 481.1 1. .1";
    char str[] = " 19.6 51.12 481.1 1. .1";    
	//double strtod (const char* str, char** endptr);
	double number = strtod(str, &end);    	
	cout << number << endl;
	char * tempEnd;
    while(strcmp(end, "") != 0){
    	number = strtod(end, &tempEnd);
    	cout << number << endl;    	
    	end = tempEnd;
    }
    //Test
    char str1[] = "   ";    
    strtod(str1, &end);
    if(end == str1){    //all spaces.
        cout << "'" << str1 << "'" << endl;
        cout << "'" << end << "'" << endl;
    }
    else{
        cout << "different" << endl;
    }
    return 0;
}
