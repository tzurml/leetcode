//
//Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
//
//Each row must contain the digits 1-9 without repetition.
//Each column must contain the digits 1-9 without repetition.
//Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
//Note:
//
//A Sudoku board (partially filled) could be valid but is not necessarily solvable.
//Only the filled cells need to be validated according to the mentioned rules.
//
//
//Example 1:
//
//
//Input: board =
//[["5","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
//Output: true
//Example 2:
//
//Input: board =
//[["8","3",".",".","7",".",".",".","."]
//,["6",".",".","1","9","5",".",".","."]
//,[".","9","8",".",".",".",".","6","."]
//,["8",".",".",".","6",".",".",".","3"]
//,["4",".",".","8",".","3",".",".","1"]
//,["7",".",".",".","2",".",".",".","6"]
//,[".","6",".",".",".",".","2","8","."]
//,[".",".",".","4","1","9",".",".","5"]
//,[".",".",".",".","8",".",".","7","9"]]
//Output: false
//Explanation: Same as Example 1, except with the 5 in the top left corner being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.


#include <cctype>
#include "set"
#include "vector"

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int x = 0;
        for(int i = 0; i < 9;++i)
        {
            if (check_row(board,i)) return false;
            if (check_col(board,i)) return false;
        }
        for(int j = 0; j < 9; j = j + 3)
        {
            for(int k = 0; k < 9; k = k + 3)
            {
                if (check_box(board,j,k)) return false;
            }
        }
        return true;

    }



    int check_box(vector<vector<char>>& board,int row,int col)
    {
        set<char> check;
        for(int i = 0; i < 3 ; ++i)
        {
            for(int j = 0; j < 3;++j)
            {
                if(isdigit(board[row+i][col+j]) && board[row+i][col+j] != '.')
                    if(check.find(board[row+i][col+j]) != check.end()) return -1;
                check.insert(board[row+i][col+j]);
            }
        }
        return 0;
    }

    int check_row(vector<vector<char>>& board,int row)
    {
        set<char> check;
        for(int i=0; i < 9; ++i)
        {
            if(isdigit(board[row][i]) && board[row][i] != '.')
                if(check.find(board[row][i]) != check.end()) return -1;
            check.insert(board[row][i]);
        }
        return 0;

    }

    int check_col(vector<vector<char>>& board,int col)
    {
        set<char> check;
        for(int i=0; i < 9; ++i)
        {
            if(check.find(board[i][col]) != check.end() && board[i][col] != '.')
            {return -1;}
            check.insert(board[i][col]);
        }
        return 0;
    }
};