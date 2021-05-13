#include <iostream>
#include <vector>
using namespace std;

void dfs(int r, int c, int len, vector<vector<int>> &paper, vector<int> &answer)
{
  if (len == 1)
  {
    answer[paper[r][c] + 1]++;
    return;
  }
  int elem = paper[r][c], size = len / 3;
  bool sep = false;
  for (int i = 0; i < len; i++)
  {
    for (int j = 0; j < len; j++)
    {
      if (elem != paper[r + i][c + j])
      {
        sep = true;
        break;
      }
    }
    if (sep)
      break;
  }

  if (!sep)
  {
    answer[elem + 1]++;
    return;
  }

  for (int i = 0; i < len; i += size)
  {
    for (int j = 0; j < len; j += size)
    {
      dfs(r + i, c + j, size, paper, answer);
    }
  }
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

  vector<int> answer(3, 0);
  dfs(0, 0, n, paper, answer);

  for (int cnt : answer)
    cout << cnt << '\n';

  return 0;
}