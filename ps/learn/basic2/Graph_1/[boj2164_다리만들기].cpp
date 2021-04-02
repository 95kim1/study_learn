#include <iostream>
#include <queue>
#include <utility>
/*방법:
  
*/

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

void DFS_separate(std::pair<int, int> **map_, int &n);
void dfs_separate(std::pair<int, int> **map_, int &n, int r, int c, int &num);

int isNextIsland(std::pair<int, int> **map_, int &n, int r, int c);
int BFS_bridge(std::pair<int, int> **map_, int &n);

void dfs_separate(std::pair<int, int> **map_, int &n, int r, int c, int &num)
{
  map_[r][c].first = num;

  for (int i = 0; i < 4; i++)
  {
    int R = r + dr[i];
    int C = c + dc[i];
    if (!(0 <= R && R < n && 0 <= C && C <= n) || map_[R][C].first > -1)
      continue;
    dfs_separate(map_, n, R, C, num);
  }
}

void DFS_separate(std::pair<int, int> **map_, int &n)
{
  int num = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (map_[i][j].first >= 0)
        continue;
      dfs_separate(map_, n, i, j, num);
      num++;
    }
  }
}

int isNextIsland(std::pair<int, int> **map_, int &n, int r, int c)
{
  for (int i = 0; i < 4; i++)
  {
    int R = r + dr[i];
    int C = c + dc[i];
    if (!(0 <= R && R < n && 0 <= C && C < n))
      continue;
    if (map_[R][C].second == 0 && map_[R][C].first > 0)
      return map_[R][C].first;
  }
  return 0;
}

int BFS_bridge(std::pair<int, int> **map_, int &n)
{
  std::queue<std::pair<std::pair<int, int>, int>> q;
  int depth = 1;
  int group;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      group = isNextIsland(map_, n, i, j);
      if (map_[i][j].first > 0 || group == 0)
        continue;
      q.push(std::make_pair(std::make_pair(i, j), depth));
      map_[i][j].second = depth;
      map_[i][j].first = group;
    }
  }

  int minNum = 10000;
  bool found = false;
  while (!q.empty())
  {
    std::pair<int, int> cur = q.front().first;
    depth = q.front().second;
    q.pop();
    group = map_[cur.first][cur.second].first;

    for (int i = 0; i < 4; i++)
    {
      int R = cur.first + dr[i];
      int C = cur.second + dc[i];
      if (!(0 <= R && R < n && 0 <= C && C < n) || map_[R][C].first == group)
        continue;
      if (map_[R][C].first != 0)
      {
        int temp_min = depth;
        if (map_[R][C].second != -1)
          temp_min += map_[R][C].second;
        if (minNum > temp_min)
          minNum = temp_min;
        continue;
      }
      q.push(std::make_pair(std::make_pair(R, C), depth + 1));
      map_[R][C].second = depth + 1;
      map_[R][C].first = group;
    }
  }
  return minNum;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  std::pair<int, int> **map_ = new std::pair<int, int> *[n];
  for (int i = 0; i < n; i++)
  {
    map_[i] = new std::pair<int, int>[n];
    for (int temp, j = 0; j < n; j++)
    {
      std::cin >> temp;
      map_[i][j].first = -temp;
      map_[i][j].second = 0;
    }
  }

  DFS_separate(map_, n);               //섬 구분
  printf("%d\n", BFS_bridge(map_, n)); //다리 놓기

  for (int i = 0; i < n; i++)
    delete[] map_[i];
  delete[] map_;
  return 0;
}