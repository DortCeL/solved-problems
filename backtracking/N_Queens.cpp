#include <bits/stdc++.h>
using namespace std;

bool helper(vector<vector<int>> &board, int col, int n)
{
    // If all queens are placed, return true
    if (col >= n)
        return true;

    // Try placing a queen in all rows, one by one, in the current column
    for (int i = 0; i < col; i++)
    {
        if (isSafe(board, i, col, n))
        {
            board[i][col] = 1; // place the queen

            // recur to place the rest of the queens
            if (helper(board, col + 1, n))
                return true;

            board[i][col] = 0; // backtrack
        }
    }

    return false;
}

void solveNQueens(int n)
{
    vector<vector<int>> board(n, vector<int>(n, 0));
}

int main(void)
{
    int n = 4;
    solveNQueens(n);
    return 0;
}