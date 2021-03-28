//[boj 16929 : 서울 지하철 2호선](https://www.acmicpc.net/problem/16929)

#include <iostream>
#include <vector>
#include <queue>
#include <utility>

int DFS(std::vector<std::vector<int> > &graph, int &n, int *cycle, int cur_node, int prev_node)
{
    //cycle[cur_node] == 0 방문 x // == 1 방문 o but not cycle // == 2 방문 o and cycle
    if (cycle[cur_node] == 1)
        return cur_node;
    cycle[cur_node] = 1;

    for (int i = 0; i < (int)graph[cur_node].size(); i++)
    {
        int next_node = graph[cur_node][i];

        if (next_node == prev_node)
            continue;

        int start_cycle = DFS(graph, n, cycle, next_node, cur_node);

        //이미 사이클을 찾은 경우이므로 더이상의 탐색을 하지 않아도 된다는 의미
        if (start_cycle == -2)
            return -2;

        //사이클의 시작점을 찾았다.
        if (start_cycle > 0)
        {
            cycle[cur_node] = 2; //cycle임을 표시

            //모든 사이클 노드를 전부 사이클이라 표시함.
            if (start_cycle == cur_node)
            {
                return -2;
            }
            //아직 모든 사이클 노드를 사이클이라 표시하진 못함.
            return start_cycle;
        }
    }
    return -1;
}

int bfs(std::vector<std::vector<int> > &graph, int &n, int cur_v, int *cycle)
{
    bool *visit = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        visit[i] = false;
    }

    std::queue<std::pair<int, int> > q;
    int cur_node = cur_v;
    int depth = 0;
    q.push(std::make_pair(cur_node, depth));
    visit[cur_node] = true;

    while (!q.empty())
    {
        cur_node = q.front().first;
        depth = q.front().second;
        q.pop();
        visit[cur_node] = true;

        if (cycle[cur_node] == 2)
            break;

        for (int i = 0; i < (int)graph[cur_node].size(); i++)
        {
            int next_node = graph[cur_node][i];
            if (visit[next_node])
                continue;
            q.push(std::make_pair(next_node, depth + 1));
            visit[next_node] = true;
        }
    }

    delete[] visit;
    return depth;
}

/* 방법:
    dfs로 순환선 찾고, bfs로 각 노드마다 순환선과의 최단 거리를 구한다.*/
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int> > graph(n + 1);
    int *cycle = new int[n + 1];
    for (int from, to, i = 1; i <= n; i++)
    {
        cycle[i] = 0;
        std::cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    DFS(graph, n, cycle, 1, 0); //cycle 찾기 (순환선 찾기)
    //각 노드마다 cycle이랑 얼마나 떨어져 있는지 확인 후 출력
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", bfs(graph, n, i, cycle));
    }
    printf("\n");

    delete[] cycle;
    return 0;
}