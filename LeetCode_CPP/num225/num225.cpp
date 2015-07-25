// File: num225.cpp
// Author: lxw
// Date: 2015-07-25

/*
Num num225: Implement Stack using Queues
Source: https://leetcode.com/problems/implement-stack-using-queues/

Implement the following operations of a stack using queues.

push(x) -- Push element x onto stack.
pop() -- Removes the element on top of the stack.
top() -- Get the top element.
empty() -- Return whether the stack is empty.
Notes:
You must use only standard operations of a queue -- which means only push to back, peek/pop from front, size, and is empty operations are valid.
Depending on your language, queue may not be supported natively. You may simulate a queue by using a list or deque (double-ended queue), as long as you use only standard operations of a queue.
You may assume that all operations are valid (for example, no pop or top operations will be called on an empty stack).
Update (2015-06-11):
The class name of the Java function had been updated to MyStack instead of Stack.

Credits:
Special thanks to @jianchao.li.fighter for adding this problem and all test cases.
*/

//not thread-safe
class Stack {
private:
    queue<int> q1;
    queue<int> q2;
public:
    // Push element x onto stack.
    void push(int x) {
        if(q1.empty())
            q2.push(x);
        else
            q1.push(x);
    }

    // Removes the element on top of the stack.
    void pop() {
        int number = 0;
        if(q1.empty() && q2.empty())
            return;
        else if(q1.empty()){
            while(1){
                number = q2.front();
                q2.pop();
                if(q2.empty())
                    break;
                else
                    q1.push(number);
            }
        }
        else{ //q2.empty()
            while(1){
                number = q1.front();
                q1.pop();
                if(q1.empty())
                    break;
                else
                    q2.push(number);
            }
        }
    }

    // Get the top element.
    int top() {
        if(q1.empty() && q2.empty())
            return -1;
        else if(q1.empty()){
            return q2.back();
        }
        else{ //q2.empty()
            return q1.back();
        }
    }

    // Return whether the stack is empty.
    bool empty() {
        return q1.empty() && q2.empty();
    }
};