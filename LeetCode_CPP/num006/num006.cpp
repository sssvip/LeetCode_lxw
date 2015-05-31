#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    //Time: O(n).  Space: O(n).
    string convert1(string s, int numRows) {
        string * result1 = new string[numRows];
        for(int i = 0; i < numRows; ++i){
            result1[i] = "";
        }
        int length = s.length();
        for(int i = 0; i < length;){
            for(int j = 0; j < numRows && i < length; ++j){
                result1[j] += s[i];
                ++i;
            }
            if(i < length){
                for(int j = numRows-2; j > 0 && i < length; --j){
                    result1[j] += s[i];
                    ++i;
                }
            }
        }
        string result = "";
        for(int i = 0; i < numRows; ++i){
            result += result1[i];
        }
        delete[] result1;
        return result;
    }

    //Time: O(n).
    string convert(string s, int numRows) {
        int length = s.length();
        if(numRows == 1 || length <= numRows)
            return s;
        string result = "";
        for(int i = 0; i < numRows; ++i){
            int index = i;
            if(i == 0 || i == numRows - 1){
                while(index < length){
                    result += s[index];
                    index += 2 * numRows - 2;
                }
            }
            else{
                bool flag = true;
                while(index < length){
                    result += s[index];
                    if(flag){
                        index += 2 * (numRows - 1 - i);
                        flag = false;
                    }
                    else{
                        index += 2 * i;
                        flag = true;
                    }
                }
            }
        }
        return result;
    }
};


int main(void)
{
    Solution sol;
    cout << sol.convert1("abcdefghijklmn", 3) << endl;
    cout << sol.convert("abcdefghijklmn", 3) << endl;
    return 0;
}
