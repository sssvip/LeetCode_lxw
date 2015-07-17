//Runtime Error.
// File: num155.cpp
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

//insert from left(head) instead of right(tail). This is important and smart.
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
    Node * setNext(Node * next){
        this->next = next;
    }
};
class MinStack {
private:
    Node * topNode;
public:
    void push(int x) {
        if(this->topNode == NULL){
            //this->topNode = & Node(x, x);   //Line 28: taking address of temporary [-fpermissive]
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
        //delete temp;
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
};
