#include <iostream>
#include <vector>
#include <stack>

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::vector<std::vector<int>> grp(n + 1);
  bool *visit = new bool[n + 1];
  for (int from, to, i = 1; i < n; i++)
  {
    std::cin >> from >> to;
    grp[from].push_back(to);
    grp[to].push_back(from);
    visit[i] = false;
  }
  visit[n] = false;
  std::vector<int> ord(n);
  std::vector<int> parent(n + 1);
  std::vector<int> child(n + 1);
  std::vector<int> childCnt(n + 1);

  for (int i = 0; i < n; i++)
  {
    std::cin >> ord[i];
    parent[i] = 0;
    child[i] = 0;
    childCnt[i] = 0;
  }
  parent[n] = 0;
  child[n] = 0;
  childCnt[n] = 0;
  std::stack<int> s;

  if (ord[0] != 1)
  {
    printf("0\n");
    delete[] visit;
    return 0;
  }

  s.push(1);
  s.push(-1); //visited child's idx
  while (!s.empty())
  {
    int idx = s.top();
    s.pop();
    int cur = s.top();
    visit[cur] = true;
    s.pop();

    for (int i = idx + 1; i < (int)grp[cur].size(); i++)
    {
      int next = grp[cur][i];
      if (visit[next])
        continue;
      s.push(cur);
      s.push(i); //visited child's index
      s.push(next);
      s.push(-1); //visited child's index
      parent[next] = cur;
      break;
    }
  }
  delete[] visit;

  for (int i = 2; i <= n; i++)
    childCnt[parent[i]]++;
  childCnt[0] = 0;

  s.push(1);
  for (int i = 1; i < n; i++)
  { //순서
    int cur = s.top();
    if (cur == parent[ord[i]])
    {
      s.push(ord[i]);
      child[cur] = ord[i];
      childCnt[cur]--;
      continue;
    }

    cur = parent[ord[i]];
    if (childCnt[child[cur]] > 0)
    {
      printf("0\n");
      return 0;
    }
    s.push(ord[i]);
    child[cur] = ord[i];
    childCnt[cur]--;
  }
  printf("1\n");

  return 0;
}