// File: num292.cpp
// Author: lxw
// Date: 2015-10-23

/*
Num num292: Nim Game
Source: https://leetcode.com/problems/nim-game/

You are playing the following Nim Game with your friend: There is a heap of stones on the table, each time one of you take turns to remove 1 to 3 stones. The one who removes the last stone will be the winner. You will take the first turn to remove the stones.

Both of you are very clever and have optimal strategies for the game. Write a function to determine whether you can win the game given the number of stones in the heap.

For example, if there are 4 stones in the heap, then you will never win the game: no matter 1, 2, or 3 stones you remove, the last stone will always be removed by your friend.

Hint:

If there are 5 stones in the heap, could you figure out a way to remove the stones such that you will always be the winner?
Credits:
Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

class Solution {
private:
    bool canWinNim(int n, bool turn){
    	//turn: [true: your turn;  false: your friend's turn;]
        if(n <= 3)
            return turn;
        for(int i = 1; i < 4; ++i){
            if(canWinNim(n-i, !turn))
                return true;
        }
        return false;
    }
public:
    bool canWinNim1(int n) {
    	//暴力 递归 会导致栈溢出
    	//这种方法是不对的，这种方法没有考虑前提，两个人都足够聪明，对方会
    	//尽量的让剩下的是4的倍数
        return canWinNim(n, true);
    }

    bool canWinNim(int n) {    	
        /*
        //Good Method
		由于每次能够拿得是1到3之间，那么对手拿k个，你一定可以拿4-k个，所以你只需要保证
		你第一次拿完之后剩下的是4的整数倍就行了，所以一开始的石头只要不是4的整数倍，也就
		是说你第一次拿n%4之后的石头后，剩下的就是4的整数倍的石头了，所以根据我们的凑4的
		策略，接下来对方拿k个你就拿4-k个，最终一定能够赢得，所以题目就变成了判断当前总石
		头的数量是不是4的倍数，不是的话就是我赢，否则对方赢。
		*/
		return n % 4;
    }
};

int main(void){
	Solution s;	
	cout << "Result: " << s.canWinNim(12868) << endl;
	cout << "Result: " << s.canWinNim1(12868) << endl;	
	/*
	for(int i = 1; i < 10; ++i){
		if(s.canWinNim(i) != s.canWinNim1(i))
			cout << "num: " << i << endl;
	}*/
	return 0;
}