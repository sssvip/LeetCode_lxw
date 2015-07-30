// File: num095.cpp
// Author: lxw
// Date: 2015-07-29

/*
Num 095: Unique Binary Search Trees II
Source: https://leetcode.com/problems/unique-binary-search-trees-ii/

Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <climits>

using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
private:
    vector<TreeNode*> roots;
    vector<TreeNode*> generateTrees(int start, int end){    //如果写为vector<TreeNode*> & 则是返回函数内"临时变量的引用"，会出现"运行时错误"
        vector<TreeNode*> nodes;
        if(start > end){
            nodes.push_back(NULL);
            return nodes;
        }
        if(start == end){
            nodes.push_back(new TreeNode(start));
            return nodes;
        }
        TreeNode * node = NULL;
        for(int k = start; k <=end; ++k){
            //node = new TreeNode(k); //must NOT be here;
            //Line 25: invalid initialization of non-const reference of type ‘std::vector<TreeNode*>&’ from an rvalue of type ‘std::vector<TreeNode*>’
            //vector<TreeNode*> & left = generateTrees(start, k-1); NO  //报上面的错误
            const vector<TreeNode*> & left = generateTrees(start, k-1); //vector<TreeNode*> left = generateTrees(start, k-1);  OK//
            const vector<TreeNode*> & right = generateTrees(k+1, end);  //vector<TreeNode*> right = generateTrees(k+1, end);  OK//
            int leftLen = left.size();
            int rightLen = right.size();
            for(int i = 0; i < leftLen; ++i){
                for(int j = 0; j < rightLen; ++j){
                    //NOTE: 多个树共用节点
                    node = new TreeNode(k); //must be here;
                    node->left = left[i];
                    node->right = right[j];
                    nodes.push_back(node);
                }
            }
        }
        return nodes;
    }
    void freeNode(TreeNode ** node){
        if(*node == NULL)
            return;
        freeNode(&((*node)->left));
        freeNode(&((*node)->right));
        delete *node;
        *node = NULL;
    }
public:
    ~Solution(){
        //free roots
        int length = roots.size();
        //freeNode(&(roots[0]));
        for(int i = 1; i < length; ++i){
            ;//delete roots[i];
        }
    }
    vector<TreeNode*> generateTrees(int n) {
        this->roots = generateTrees(1, n);
        return this->roots;
    }
};

int main(void){
	Solution sol;
	sol.generateTrees(1);
	return 0;
}
