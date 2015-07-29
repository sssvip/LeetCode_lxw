/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Tuple{
    Tuple(TreeNode * tn, int value):node(tn), tag(value){}
    TreeNode * node;
    int tag;
};
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postOrder;
        stack<Tuple> s;
        if(root == NULL)
            return postOrder;
        s.push(Tuple(root, 0));
        while(!s.empty()){
            Tuple & t = s.top();
            s.pop();
            if(t.tag == 0){ //first time pop out.
                //入栈的顺序非常重要: 先入当前节点, 然后入右节点, 最后入左节点
                s.push(Tuple(t.node, 1));
                if(t.node->right)
                    s.push(Tuple(t.node->right, 0));
                if(t.node->left)
                    s.push(Tuple(t.node->left, 0));
            }
            else{   //second time pop out.
                postOrder.push_back(t.node->val);
            }
        }
        return postOrder;
    }
};
