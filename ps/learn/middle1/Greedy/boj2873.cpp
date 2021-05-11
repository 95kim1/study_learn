#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<vector<int>> init(int R, int C)
{
  vector<vector<int>> board(R, vector<int>(C));
  for (vector<int> &row : board)
  {
    for (int &elem : row)
    {
      cin >> elem;
    }
  }
  return board;
}

string move(char direction, int len)
{
  string ans = "";
  while (len > 1)
  {
    len--;
    ans += direction;
  }
  return ans;
}

string rOdd(int R, int C)
{
  int cnt = R / 2;
  string ans = "";
  while (cnt--)
  {
    ans += move('R', C) + move('D', 2) + move('L', C) + move('D', 2);
  }
  ans += move('R', C);
  return ans;
}

string cOdd(int R, int C)
{
  int cnt = C / 2;
  string ans = "";
  while (cnt--)
  {
    ans += move('D', R) + move('R', 2) + move('U', R) + move('R', 2);
  }
  ans += move('D', R);
  return ans;
}

pair<int, int> getMinCostPos(vector<vector<int>> &board)
{
  int rLen = (int)board.size();
  int cLen = (int)board[0].size();
  int minCost = -1;
  pair<int, int> pos;
  for (int i = 0; i < rLen; i++)
  {
    for (int j = 0; j < cLen; j++)
    {
      if (i == 0 && j == 0 || i == rLen - 1 && j == cLen - 1 || (i + j) % 2 == 0)
        continue;
      if (minCost == -1 || minCost > board[i][j])
      {
        minCost = board[i][j];
        pos = {i, j};
      }
    }
  }
  return pos;
}

string shrinkR(int cnt, int len)
{
  int i = 0;
  char c[2] = {'R', 'L'};
  string ans = "";
  while (cnt--)
  {
    ans += move(c[i], len);
    ans += move('D', 2);
    i = (i + 1) % 2;
  }
  return ans;
}

string shrinkC(int cnt)
{
  int i = 0;
  char c[2] = {'D', 'U'};
  string ans = "";
  while (cnt--)
  {
    ans += move(c[i], 2);
    ans += move('R', 2);
    i = (i + 1) % 2;
  }
  return ans;
}

string rcEven(int R, int C, vector<vector<int>> &board)
{
  pair<int, int> pos = getMinCostPos(board);
  //cout << pos.first << ", " << pos.second << '\n';
  string ansA = "", ansB = "";
  int aux = 0;
  if (pos.first % 2 == 1)
  {
    aux = 1;
  }

  ansA += shrinkR(pos.first - 0 - aux, C);
  ansB += shrinkR((R - 1) - pos.first - (1 - aux), C);

  ansA += shrinkC(pos.second - 0 - (1 - aux));
  ansB += shrinkC((C - 1) - pos.second - aux);

  if (aux)
  {
    ansA += move('R', 2) + move('D', 2);
  }
  else
  {
    ansA += move('D', 2) + move('R', 2);
  }

  while (!ansB.empty())
  {
    ansA += ansB.back();
    ansB.pop_back();
  }

  return ansA;
}

int main(void)
{
  int R, C;
  cin >> R >> C;
  vector<vector<int>> board = init(R, C);

  if (R % 2 == 1)
  {
    cout << rOdd(R, C) << '\n';
    return 0;
  }
  else if (C % 2 == 1)
  {
    cout << cOdd(R, C) << '\n';
    return 0;
  }

  cout << rcEven(R, C, board) << '\n';

  return 0;
}