//[boj 7562 : 나이트의 이동](https://www.acmicpc.net/problem/7562)

/*
나이트 현재 위치: O
나이트 이동 가능 위치: X
| |X| |X| |
|X| | | |X|
| | |O| | |
|X| | | |X|
| |X| |X| |
*/

#include <iostream>
#include <utility>
#include <queue>

/* 방법:
 *  가중치가 1인 그래프의 최단경로와 같은 문제이므로 bfs이용*/
int main(void)
{
    int t;
    std::cin >> t;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::pair<int, int> cur, next;
        std::cin >> cur.first >> cur.second >> next.first >> next.second;
        int **map_ = new int *[n];
        for (int i = 0; i < n; i++)
        {
            map_[i] = new int[n];
            for (int j = 0; j < n; j++)
            {
                map_[i][j] = 0;
            }
        }

        int depth = 0;
        std::queue<std::pair<std::pair<int, int>, int> > q;
        q.push(std::make_pair(cur, depth));
        map_[cur.first][cur.second] = 1;
        int dr[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dc[8] = {1, 2, 2, 1, -1, -2, -2, -1};
        while (!q.empty())
        {
            cur = q.front().first;
            depth = q.front().second;
            q.pop();

            if (cur.first == next.first && cur.second == next.second)
                break;

            for (int i = 0; i < 8; i++)
            {
                int r = cur.first + dr[i];
                int c = cur.second + dc[i];
                if (!(0 <= r && r < n && 0 <= c && c < n) || map_[r][c] != 0)
                    continue;
                q.push(std::make_pair(std::make_pair(r, c), depth + 1));
                map_[r][c] = 1;
            }
        }

        printf("%d\n", depth);
    }

    return 0;
}