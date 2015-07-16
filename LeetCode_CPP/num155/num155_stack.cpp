// File: num155_stack.cpp
// Author: lxw
// Date: 2015-07-16

/*
Num num155: Min Stack
Source: https://leetcode.com/problems/min-stack/

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
getMin() -- Retrieve the minimum element in the stack.
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <climits>

using namespace std;

class MinStack {
private:
    stack<int> stk;
    stack<int> minStk;
public:
    void push(int x) {
        if(stk.empty() || x <= minStk.top()){
            minStk.push(x);
        }
        stk.push(x);
    }

    void pop() {
        if(!stk.empty()){
            if(stk.top() == minStk.top())
                minStk.pop();
            stk.pop();
        }
    }

    int top() {
        if(!stk.empty()){
            return stk.top();
        }
        return -1;
    }

    int getMin() {
        if(!minStk.empty()){
            return minStk.top();
        }
        return -1;
    }
};

int main(void){
	MinStack ms;
	ms.push(1);
	ms.push(2);
	ms.push(1);		
	ms.push(12);
	ms.push(-12);
	ms.push(3);	
	ms.push(-14);
	ms.push(3);	
	ms.push(13);
	cout << "ms.getMin(): " << ms.getMin() << endl;
	cout << "ms.top(): " << ms.top() << endl;
	cout << "ms.pop()." << endl;
	ms.pop();
	cout << "ms.top(): " << ms.top() << endl;
	cout << "ms.getMin(): " << ms.getMin() << endl;
	return 0;
}
