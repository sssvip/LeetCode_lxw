// File: num130.cpp
// Author: lxw
// Date: 2015-08-10

/*
Num num130: Surrounded Regions
Source: https://leetcode.com/problems/surrounded-regions/

Given a 2D board containing 'X' and 'O', capture all regions surrounded by 'X'.

A region is captured by flipping all 'O's into 'X's in that surrounded region.

For example,
X X X X
X O O X
X X O X
X O X X
After running your function, the board should be:

X X X X
X X X X
X X X X
X O X X
*/

//BFS和DFS的思想差不多:只不过BFS用的是queue, 而DFS用的是stack.
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rows = board.size();
        if(rows < 3)
            return;
        int cols = board[0].size();
        if(cols < 3)
            return;
        queue<pair<int, int> > pos;
        //col 0.
        for(int i = 1; i < rows; ++i){
            if(board[i][0] == 'O'){
                board[i][0] = '*';
                pos.push(make_pair(i, 0));
            }
        }
        //row rows-1.
        for(int j = 1; j < cols; ++j){
            if(board[rows-1][j] == 'O'){
                board[rows-1][j] = '*';
                pos.push(make_pair(rows-1, j));
            }
        }
        //col cols-1.
        for(int i = 0; i < rows-1; ++i){
            if(board[i][cols-1] == 'O'){
                board[i][cols-1] = '*';
                pos.push(make_pair(i, cols-1));
            }
        }
        //row 0.
        for(int j = 0; j < cols-1; ++j){
            if(board[0][j] == 'O'){
                board[0][j] = '*';
                pos.push(make_pair(0, j));
            }
        }
        pair<int, int> temp;
        int count = pos.size();
        int left = 1;
        int right = cols-1;
        int top = 1;
        int bottom = rows-1;
        int i, j;
        while(!pos.empty()){
            temp = pos.front();
            pos.pop();
            --count;
            i = temp.first;
            j = temp.second;
            //up
            if(i-1 >= top && i-1 <= bottom && board[i-1][j] == 'O'){
                board[i-1][j] = '*';
                pos.push(make_pair(i-1, j));
            }
            //down
            if(i+1 >= top && i+1 <= bottom && board[i+1][j] == 'O'){
                board[i+1][j] = '*';
                pos.push(make_pair(i+1, j));
            }
            //left
            if(j-1 >= left &&  j-1 <= right && board[i][j-1] == 'O'){
                board[i][j-1] = '*';
                pos.push(make_pair(i, j-1));
            }
            //right
            if(j+1 >= left && j+1 <= right && board[i][j+1] == 'O'){
                board[i][j+1] = '*';
                pos.push(make_pair(i, j+1));
            }
            if(count == 0){
                count = pos.size();
                //++left; --right; // NO. Special case in following comment block.
                //++top; --bottom;
            }
        }
        for(i = 0; i < rows; ++i){
            for(j = 0; j < cols; ++j){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
                else if(board[i][j] == '*'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};

/*
Submission Result: Wrong Answer
Input:
["OOOOXX","OOOOOO","OXOXOO","OXOOXO","OXOXOO","OXOOOO"]
Output:
["OOOOXX","OOOOOO","OXOXOO","OXOXXO","OXOXOO","OXOOOO"]
Expected:
["OOOOXX","OOOOOO","OXOXOO","OXOOXO","OXOXOO","OXOOOO"]
*/