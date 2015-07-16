//LinkedList simulates stack.
//对于类似栈的操作（在链表的同一端进行添加和删除节点），如果操作链表的尾部不方便（添加节点和删除节点不方便--知道为什么不方便吗？因为每当删除tail节点时需要修改tail指针，比较麻烦），可以考虑从链表的头部进行操作

// File: num155_linkedList.cpp
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
#include <set>
#include <climits>

using namespace std;

class Node{
private:
    int value;
    int minVal;
    Node * next;
public:
    Node(int val, int minV): value(val), minVal(minV), next(NULL){}
    int getValue(){
        return this->value;
    }
    int getMinVal(){
        return this->minVal;
    }
    Node * getNext(){
        return this->next;
    }
    void setNext(Node * next){
        this->next = next;
    }
};

//insert from left(head) instead of right(tail). This is important and smart.
class MinStack {
private:
    Node * topNode;
public:
	MinStack():topNode(NULL){}
    void push(int x) {
        if(this->topNode == NULL){
            //this->topNode = & Node(x, x);   //num155.cpp:56:40: error: taking address of temporary [-fpermissive]
            this->topNode = new Node(x, x);
        }
        else{
            int minVal = this->topNode->getMinVal();
            if(minVal > x)
                minVal = x;
            Node * temp = topNode;
            //this->topNode = &Node(x, minVal);
            this->topNode = new Node(x, minVal);
            this->topNode->setNext(temp);
        }
    }

    void pop() {
        if(this->topNode == NULL){
            return;
        }
        Node * temp = this->topNode;
        this->topNode = this->topNode->getNext();
        delete temp;
    }

    int top() {
        if(this->topNode == NULL){
            return 0;
        }
        return this->topNode->getValue();
    }

    int getMin() {
        if(this->topNode == NULL){
            return 0;
        }
        return this->topNode->getMinVal();
    }

    void showMinStack(){
    	Node * temp = this->topNode;
    	while(temp){
    		cout << "(" << temp->getValue() << ", " << temp->getMinVal() << ") -> ";
    		temp = temp->getNext();
    	}
    	cout << endl;
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
	cout << "ms.showMinStack(): " << endl;
	ms.showMinStack();
	cout << "ms.pop()." << endl;
	ms.pop();
	cout << "ms.top(): " << ms.top() << endl;
	cout << "ms.showMinStack(): " << endl;
	ms.showMinStack();
	cout << "ms.getMin(): " << ms.getMin() << endl;
	return 0;
}
