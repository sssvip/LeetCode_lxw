// File: test1.cpp
// Author: lxw
// Date: 2015-09-21

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(void){
	int count;
	string str;
	int majorMax, minorMax, patchlevelMax;
	majorMax = minorMax = patchlevelMax = -1;
	while(cin >> count){
		int major, minor, patchlevel;
		while(count-- > 0){
			cin >> str;
			stringstream ss(str);
    		string numStr;
    		major = minor = patchlevel = -1;
		    if(getline(ss, numStr, '.')){
		    	stringstream majorss(numStr);
		        majorss >> major;
		    }
		    if(getline(ss, numStr, '.')){
		    	stringstream minorss(numStr);
		        minorss >> minor;
		        if(minor & 0x01 != 0){
		        	continue;
		        }
		    }
		    if(getline(ss, numStr, '.')){
		    	stringstream plss(numStr);
		        plss >> patchlevel;
		    }
		    if(major > majorMax){
		    	majorMax = major;
		    	minorMax =minor;
		    	patchlevelMax = patchlevel;		    	
		    }
		    else if(major == majorMax){
		    	if(minor > minorMax){		    	
		    		minorMax =minor;
		    		patchlevelMax = patchlevel;
		    	}
		    	else if(minor == minorMax && patchlevel > patchlevelMax){		    		
		    		patchlevelMax = patchlevel;
		    	}
		    }
		}
		if(majorMax == -1)
			cout << "no stable available" << endl;
		else if(patchlevelMax == -1)
			cout << majorMax << "." << minorMax << endl;
		else
			cout << majorMax << "." << minorMax << "." << patchlevelMax << endl;
	}
	return 0;
}