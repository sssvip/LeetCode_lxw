// File: num133.cpp
// Author: lxw
// Date: 2015-08-11

/*
Num num133: Clone Graph
Source: https://leetcode.com/problems/clone-graph/

Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.


OJ's undirected graph serialization:
Nodes are labeled uniquely.

We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.

The graph has a total of three nodes, and therefore contains three parts as separated by #.

First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
Second node is labeled as 1. Connect node 1 to node 2.
Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
*/

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors; //何时进行初始化操作? 什么时候才可以使用这个数据成员(未在构造函数中提及的数据成员)?
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        
        UndirectedGraphNode * result = new UndirectedGraphNode(node->label);
        unordered_map<int, UndirectedGraphNode *> UGNMap;   //存的必须都是新的
        UGNMap[node->label] = result;   //该map存的是(自己的label, 和指向自己的指针, 而不是neighbors的指针)
        queue<UndirectedGraphNode *> nodeTodo;  //存的必须都是旧的
        nodeTodo.push(node);
        
        UndirectedGraphNode * temp;
        UndirectedGraphNode * neighbor;
        int length = 0;
        
        while(!nodeTodo.empty()){
            temp = nodeTodo.front();
            nodeTodo.pop();
            length = temp->neighbors.size();
            for(int i = 0; i < length; ++i){
                if(UGNMap.find(temp->neighbors[i]->label) == UGNMap.end()){    //Not created yet.
                     neighbor = new UndirectedGraphNode(temp->neighbors[i]->label);
                     UGNMap[temp->neighbors[i]->label] = neighbor;
                     nodeTodo.push(temp->neighbors[i]);
                }
                else{
                    neighbor = UGNMap[temp->neighbors[i]->label];
                }
                (UGNMap[temp->label]->neighbors).push_back(neighbor);
            }
        }
        return result;
    }
};