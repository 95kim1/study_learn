//[boj 2178 : 미로 탐색](https://www.acmicpc.net/problem/2178)

#include <iostream>
#include <string>
#include <utility>
#include <queue>

int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
int bfs(std::string *maze, int &n, int &m)
{
    int len = 0;
    std::queue<std::pair<std::pair<int, int>, int> > q;
    q.push(std::make_pair(std::make_pair(0, 0), 1));
    maze[0][0] = '2'; //탐색 완료
    while (!q.empty())
    {
        std::pair<int, int> cur = q.front().first;
        int depth = q.front().second;
        len = depth;
        q.pop();

        if (cur.first == n - 1 && cur.second == m - 1)
            break;

        for (int i = 0; i < 4; i++)
        {
            int r = cur.first + dr[i];
            int c = cur.second + dc[i];
            if (!(0 <= r && r < n && 0 <= c && c < m) || maze[r][c] != '1')
                continue;
            maze[r][c] = '2'; //탐색 완료
            q.push(std::make_pair(std::make_pair(r, c), depth + 1));
        }
    }

    return len;
}

/* 방법:
 *  그래프의 탐색 문제
 *  최단 거리로 미로를 탐색하는 경로의 노드 수를 묻는 문제이므로
 *  bfs를 이용한다. */
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::string *maze = new std::string[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> maze[i];
    }

    printf("%d\n", bfs(maze, n, m));

    delete[] maze;

    return 0;
}