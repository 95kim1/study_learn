//[boj 16929 : 서울 지하철 2호선](https://www.acmicpc.net/problem/16929)

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <utility>

bool dfs(std::vector<std::vector<int> > &graph, int &n, int prev_node, int cur_node, bool *visit, std::stack<int> &s)
{
    visit[cur_node] = true;
    s.push(cur_node);

    for (int i = 0; i < (int)graph[cur_node].size(); i++)
    {
        int next_node = graph[cur_node][i];
        if (visit[next_node])
        {
            if (next_node == prev_node)
                continue;
            s.push(next_node);
            return true;
        }
        if (dfs(graph, n, cur_node, next_node, visit, s))
        {
            return true;
        }
        s.pop();
    }
    return false;
}
void DFS(std::vector<std::vector<int> > &graph, int &n, bool *cycle)
{
    bool *visit = new bool[n + 1];
    for (int i = 0; i <= n; i++)
    {
        visit[i] = false;
    }
    std::stack<int> s;
    dfs(graph, n, 0, 1, visit, s);

    int end_node = s.top();
    cycle[end_node] = true;
    s.pop();
    while (!s.empty() && s.top() != end_node)
    {
        cycle[s.top()] = true;
        s.pop();
    }

    delete[] visit;
}

int bfs(std::vector<std::vector<int> > &graph, int &n, int cur_v, bool *cycle)
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

        if (cycle[cur_node])
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
    dfs로 순환선 찾고, bfs로 각 노드마다 순환선과의 최단 거리를 구한다. */
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::vector<int> > graph(n + 1);
    bool *cycle = new bool[n + 1];
    for (int from, to, i = 1; i <= n; i++)
    {
        cycle[i] = false;
        std::cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }

    DFS(graph, n, cycle); //cycle 찾기 (순환선 찾기)

    //각 노드마다 cycle이랑 얼마나 떨어져 있는지 확인 후 출력
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", bfs(graph, n, i, cycle));
    }
    printf("\n");

    delete[] cycle;
    return 0;
}