// File: test2.cpp
// Author: lxw
// Date: 2015-09-26

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class TestUtils {
public:

	/**
	 * 获取最长递增子序列
	 *
	 * @param input 整型数组
	 * @return 整型数组
	 */
	
	//DP: Dynamic Programming
	//返回值不应该是引用类型吧???
	static const vector<int>& findSeq(const vector<int>& input) {
		// 请在此添加代码
		int length = input.size();
		vector<int> dp(length, 1);
		
		int maxLength = 0;
		//得到最长增量序列的长度
		for(int i = 0; i < length; ++i){
			for(int j = 0; j < i; ++j){
				if(input[j] < input[i] && dp[i] < dp[j] + 1){
					dp[i] = dp[j] + 1;
					if(dp[i] > maxLength)
						maxLength = dp[i];
				}
			}
		}
		
		vector<int> result;
		//得到最长增量序列上的元素
		for(int i = length - 1; i >= 0; --i){
			if(dp[i] == maxLength){
				result.push_back(input[i]);
				--maxLength;
			}
		}
		return result;
	}

	// 若有需要，请在此添加辅助变量、方法

};
