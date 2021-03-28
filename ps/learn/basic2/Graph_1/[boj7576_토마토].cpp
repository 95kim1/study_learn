//[boj 7576 : 토마토](https://www.acmicpc.net/problem/7576)

#include <iostream>
#include <utility>
#include <queue>
//첫 탐색 전에 익은 토마토의 위치를 모두 큐에 넣고 bfs를 진행한다.
//더이상 익을 토마토가 없을 때 까지 걸리는 시간을 반환한다.
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
int bfs(int **box, int &n, int &m)
{
    int len = 0, tomato = 0;
    std::queue<std::pair<std::pair<int, int>, int> > q;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (box[i][j] != 1)
            {
                if (box[i][j] == 0)
                    tomato++;
                continue;
            }
            q.push(std::make_pair(std::make_pair(i, j), 0));
        }
    }
    while (!q.empty())
    {
        std::pair<int, int> cur = q.front().first;
        int depth = q.front().second;
        len = depth;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int R = cur.first + dr[i];
            int C = cur.second + dc[i];
            if (!(0 <= R && R < n && 0 <= C && C < m) || box[R][C] != 0)
                continue;
            q.push(std::make_pair(std::make_pair(R, C), depth + 1));
            box[R][C] = 1;
            tomato--;
        }
    }

    if (tomato > 0)
        len = -1;

    return len;
}

/* 방법:
 *  익은 토마토가 인접한 토마토에 영향을 주므로
 *  bfs를 통해 익은 토마토의 모든 인접한 토마토에 대해서 동시에 익을 수 있도록한다.
 *  bfs 구현시, 모든 익은 토마토를 큐에 한 번에 다 넣는다.*/
int main(void)
{
    int n, m;
    std::cin >> m >> n;
    int **box = new int *[n];
    for (int i = 0; i < n; i++)
    {
        box[i] = new int[m];
        for (int j = 0; j < m; j++)
        {
            std::cin >> box[i][j];
        }
    }

    printf("%d\n", bfs(box, n, m));

    for (int i = 0; i < n; i++)
        delete[] box[i];
    delete[] box;

    return 0;
}