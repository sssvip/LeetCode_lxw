#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include <climits>

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

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        if(m == 0){
            return result;
        }
        int n = matrix[0].size();
        if(n == 0){
            return result;
        }
        int upBound = 0;
        int downBound = m - 1;
        int leftBound = 0;
        int rightBound = n - 1;
        while(1){
            //right
            for(int i = leftBound; i <= rightBound; ++i){
                result.push_back(matrix[upBound][i]);
                //cout << matrix[upBound][i] << endl;
            }
            ++upBound;
            if(upBound > downBound)
                break;
            //down
            for(int i = upBound; i <= downBound; ++i){
                //cout << rightBound << ", " << i << endl;    //2, 1
                result.push_back(matrix[i][rightBound]);
            }
            --rightBound;
            if(rightBound < leftBound)
                break;
            //left
            for(int i = rightBound; i >= leftBound; --i){
                result.push_back(matrix[downBound][i]);
                //cout << matrix[downBound][i] << endl;
            }
            --downBound;
            if(downBound < upBound)
                break;
            //up
            for(int i = downBound; i >= upBound; --i){
                result.push_back(matrix[i][leftBound]);
                //cout << matrix[i][leftBound] << endl;
            }
            ++leftBound;
            if(leftBound > rightBound)
                break;
        }
        return result;
    }
};
int main(void){
    Solution sol;
	vector<vector<int> > matrix;
    vector<int> vec;
	vec.push_back(2);vec.push_back(5);vec.push_back(8);
	matrix.push_back(vec);
	vec.clear();
	vec.push_back(4);vec.push_back(0);vec.push_back(-1);
	matrix.push_back(vec);
    vector<int> result = sol.spiralOrder(matrix);
    showVec(result);
    return 0;
}
