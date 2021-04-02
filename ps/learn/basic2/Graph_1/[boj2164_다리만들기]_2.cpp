#include <iostream>
#include <queue>
#include <utility>
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void DFS_separate(int **map_, int &n);
void dfs_separate(int **map_, int &n, int r, int c, int &num);

bool isNextSea(int **map_, int &n, int r, int c);
int BFS_bridge(int **map_, int &n);
int bfs_bridge(int **map_, int &n, int r, int c, int &num);

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};

void dfs_separate(int **map_, int &n, int r, int c, int &num)
{
  map_[r][c] = num;

  for (int i = 0; i < 4; i++)
  {
    int R = r + dr[i];
    int C = c + dc[i];
    if (!(0 <= R && R < n && 0 <= C && C <= n) || map_[R][C] > -1)
      continue;
    dfs_separate(map_, n, R, C, num);
  }
}

void DFS_separate(int **map_, int &n)
{
  int num = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (map_[i][j] >= 0)
        continue;
      dfs_separate(map_, n, i, j, num);
      num++;
    }
  }
}

bool isNextSea(int **map_, int &n, int r, int c)
{
  for (int i = 0; i < 4; i++)
  {
    int R = r + dr[i];
    int C = c + dc[i];
    if (!(0 <= R && R < n && 0 <= C && C < n))
      continue;
    if (map_[R][C] == 0)
      return true;
  }
  return false;
}

int bfs_bridge(int **map_, int &n, int r, int c, int &num)
{
  bool **visit = new bool *[n];
  for (int i = 0; i < n; i++)
  {
    visit[i] = new bool[n];
    for (int j = 0; j < n; j++)
      visit[i][j] = false;
  }

  bool found = false;

  int depth = 0;
  std::queue<std::pair<std::pair<int, int>, int>> q;
  q.push(std::make_pair(std::make_pair(r, c), depth));

  while (!q.empty())
  {
    std::pair<int, int> cur = q.front().first;
    depth = q.front().second;
    q.pop();

    if ((cur.first != r || cur.second != c) && map_[cur.first][cur.second] > 0)
    {
      found = true;
      break;
    }

    for (int i = 0; i < 4; i++)
    {
      int R = cur.first + dr[i];
      int C = cur.second + dc[i];
      if (!(0 <= R && R < n && 0 <= C && C < n) || map_[R][C] == num || visit[R][C])
        continue;
      q.push(std::make_pair(std::make_pair(R, C), depth + 1));
      visit[R][C] = true;
    }
  }

  if (!found)
    depth = 10001;

  for (int i = 0; i < n; i++)
    delete[] visit[i];
  delete[] visit;

  return depth - 1;
}

int BFS_bridge(int **map_, int &n)
{
  int cnt = 10000;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      if (map_[i][j] == 0)
        continue;
      if (!(isNextSea(map_, n, i, j)))
        continue;
      cnt = MIN(cnt, bfs_bridge(map_, n, i, j, map_[i][j]));
    }
  }
  return cnt;
}

int main(void)
{
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int n;
  std::cin >> n;
  int **map_ = new int *[n];
  for (int i = 0; i < n; i++)
  {
    map_[i] = new int[n];
    for (int temp, j = 0; j < n; j++)
    {
      std::cin >> temp;
      map_[i][j] = -temp;
    }
  }

  DFS_separate(map_, n);               //섬 구분
  printf("%d\n", BFS_bridge(map_, n)); //다리 놓기

  for (int i = 0; i < n; i++)
    delete[] map_[i];
  delete[] map_;
  return 0;
}