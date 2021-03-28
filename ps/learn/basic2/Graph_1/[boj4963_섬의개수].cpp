//[boj 4963 : 섬의 개수](https://www.acmicpc.net/problem/4963)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int dr[8] = {-1, -1, 0, 1, 1, 1, 0, -1}, dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
// 그래프의 연결요소를 찾기: 1은 탐새 전, 2는 탐색 완료를 의미한다.
void dfs(int **map_, int &n, int &m, int r, int c)
{
    map_[r][c] = 2; //방문 : 탐색 완료

    for (int i = 0; i < 8; i++)
    {
        int R = r + dr[i];
        int C = c + dc[i];
        if (!(0 <= R && R < n && 0 <= C && C < m) || map_[R][C] != 1)
            continue;
        dfs(map_, n, m, R, C); //방문예정(함수 호출)
    }
}

int cntIsland(int **map_, int &n, int &m)
{
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map_[i][j] != 1)
                continue;
            dfs(map_, n, m, i, j);
            cnt++;
        }
    }

    return cnt;
}

/* 방법:
 *  그래프의 연결요소 찾기
 *  문제에서 2차원 배열을 쓰므로 인접행렬을 사용한다. */
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    while (1)
    {
        int n, m;
        std::cin >> m >> n;
        if (n == 0 && m == 0)
            break;
        int **map_ = new int *[n];
        for (int i = 0; i < n; i++)
        {
            map_[i] = new int[m];
            for (int j = 0; j < m; j++)
            {
                std::cin >> map_[i][j];
            }
        }

        printf("%d\n", cntIsland(map_, n, m));

        for (int i = 0; i < n; i++)
        {
            delete[] map_[i];
        }
        delete[] map_;
    }
    return 0;
}