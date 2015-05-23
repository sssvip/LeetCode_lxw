#include <iostream>
using std::cout;
using std::endl;
using std::string;

class Solution {
public:
    int myAtoi(string str) {
        int index  = 0;
        int length = str.length();
        while(index < length){
            if(str[index] == ' '){
                ++index;
            }
            else{
                break;
            }
        }
        bool sign = true;
        if(str[index] == 43){       //+
            ++index;
        }
        else if(str[index] == 45){  //-
            sign = false;
            ++index;
        }
	    else if(str[index] < 48 || str[index] > 57){
            return 0;
        }
	
	    if(index < length && (str[index] < 48 || str[index] > 57)){
            return 0;
        }
        long long abs_max = 0x7fffffff;
        long long result = 0;
        while(index < length && (str[index] > 47 && str[index] < 58)){
            result = result * 10 + (str[index] - 48);
            if(result > abs_max){
                break;
            }
            ++index;
        }
        if(sign)
            result = result > abs_max ? (int)0x7fffffff : result;
        else
            result = result > abs_max ? (int)0x80000000 : -result;
        return result;
    }
};

int main(void){
    Solution s;
    cout << s.myAtoi("-2a") << endl;
    cout << s.myAtoi("+-2") << endl;
    cout << s.myAtoi("-2") << endl;
    cout << s.myAtoi("-2384632463278946328794632874637867842") << endl;
    cout << s.myAtoi("2384632463278946328794632874637867842") << endl;
    return 0;
}
