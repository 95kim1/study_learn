#include <iostream>
#include <vector>
using namespace std;

int dfs(int r, int c, int len, vector<vector<int>> &paper, vector<int> &answer)
{
  if (len == 1)
  {
    return paper[r][c];
  }

  vector<int> cnts(4, 0);
  int size = len / 3;
  for (int i = 0; i < len; i += size)
  {
    for (int j = 0; j < len; j += size)
    {
      int elem = dfs(r + i, c + j, size, paper, answer);
      cnts[elem + 1]++;
    }
  }

  int maxCnt = len * len, i;
  for (i = 0; i < 3; i++)
  {
    if (9 == cnts[i])
    {
      return i - 1;
    }
  }

  for (i = 0; i < 3; i++)
  {
    answer[i] += cnts[i];
  }

  return 2;
}

int main(void)
{
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  cin >> n;
  vector<vector<int>> paper(n, vector<int>(n));
  for (vector<int> &row : paper)
    for (int &i : row)
      cin >> i;

  vector<int> answer(4, 0);
  answer[dfs(0, 0, n, paper, answer) + 1]++;

  for (int i = 0; i < 3; i++)
    cout << answer[i] << '\n';

  return 0;
}