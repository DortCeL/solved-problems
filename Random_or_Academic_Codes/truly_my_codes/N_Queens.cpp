#include <bits/stdc++.h>
using namespace std;

typedef struct Queen
{
  int x, y;
  Queen(int x, int y)
  {
    this->x = x;
    this->y = y;
  }
} Queen;

// index represents row number
vector<int> placedQueenColumn(100, 0);

bool isSafe(int row, int col)
{
  for (int i = 1; i < row; i++)
  {
    if ((placedQueenColumn[i] == col) or (abs(placedQueenColumn[i] - col) == abs(col - row)))
  }
}

int main(void)
{
}