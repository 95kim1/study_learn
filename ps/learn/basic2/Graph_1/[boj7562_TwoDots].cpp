//[boj 16929 : Two Dots](https://www.acmicpc.net/problem/16929)

#include <iostream>
#include <string>

/* 방법:
    그래프 탐색, dfs를 이용한다.
    만약 이미 탐색한 곳을 탐색하려 한다면, 3칸 이전에 탐색했던 곳인지 확인한다.  */
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
bool dfs(std::string *map_, int &n, int &m, int r, int c, int depth, int **dist)
{
    dist[r][c] = depth;

    for (int i = 0; i < 4; i++)
    {
        int R = r + dr[i], C = c + dc[i];
        if (!(0 <= R && R < n && 0 <= C && C < m) || map_[r][c] != map_[R][C])
            continue;
        if (dist[R][C] != -1)
        {
            if (dist[r][c] - dist[R][C] >= 3)
                return true;
            else
                continue;
        }
        if (dfs(map_, n, m, R, C, depth + 1, dist))
        {
            return true;
        }
    }
    return false;
}

/* 방법:
 *  사이클 찾기 -> dfs 이미 방문 했으면서, 4칸 이전에 방문했던 곳이 나오면 return true*/
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::string *map_ = new std::string[n];
    int **distance = new int *[n];
    for (int i = 0; i < n; i++)
    {
        distance[i] = new int[m];
        for (int j = 0; j < m; j++)
            distance[i][j] = -1;
        std::cin >> map_[i];
    }

    bool yes = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (dfs(map_, n, m, i, j, 0, distance))
            {
                yes = true;
                break;
            }
        }
        if (yes)
            break;
    }

    if (yes)
        printf("Yes\n");
    else
        printf("No\n");

    for (int i = 0; i < n; i++)
        delete[] distance[i];
    delete[] distance;
    delete[] map_;
    return 0;
}