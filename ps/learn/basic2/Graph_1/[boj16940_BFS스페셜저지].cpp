#include <iostream>
#include <vector>
#include <queue>

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> grp(n + 1);
  std::vector<int> ord;
  for (int from, to, i = 1; i < n; i++)
  {
    std::cin >> from >> to;
    grp[from].push_back(to);
    grp[to].push_back(from);
  }

  bool *visit = new bool[n + 1];
  for (int temp, i = 1; i <= n; i++)
  {
    std::cin >> temp;
    ord.push_back(temp);
    visit[i] = false;
  }

  std::queue<int> q;
  std::vector<int> temp_v;

  if (ord[0] != 1)
  {
    printf("0\n");
    return 0;
  }
  q.push(1);
  visit[1] = true;
  int ord_idx = 1;
  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    int cnt = 0;
    for (int i = (int)grp[cur].size() - 1; i >= 0; i--)
    {
      if (visit[grp[cur][i]])
        continue;
      cnt++;
    }
    for (int i = 0; i < cnt && ord_idx < n; i++)
    {
      if (visit[ord[ord_idx++]])
      {
        printf("0\n");
        return 0;
      }

      visit[ord[ord_idx - 1]] = true;
      q.push(ord[ord_idx - 1]);
    }

    cnt = (int)grp[cur].size();
    for (int i = 0; i < cnt; i++)
    {
      int next = grp[cur][i];
      if (visit[next])
        continue;

      printf("0\n");
      return 0;
    }
  }
  printf("1\n");
  delete[] visit;
  return 0;
}