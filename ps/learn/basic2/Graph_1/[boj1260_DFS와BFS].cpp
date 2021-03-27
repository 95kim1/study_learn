//[boj 1260 : DFS와 BFS](https://www.acmicpc.net/problem/1260)

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>

//not 재귀 dfs
void dfs_(std::vector<std::vector<int> > &graph, int v, int &n) {
    bool *visit = new bool[n+1];
    for (int i = 0; i <= n; i++) {
        visit[i] = false;
    }
    
    std::stack<int> s;
    s.push(v);
    while(!s.empty()) {
LABEL:
        int cur_node = s.top();
        s.pop();
        if (!visit[cur_node])
            printf("%d ", cur_node);
        visit[cur_node] = true;
        
        
        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i];
            if (visit[next_node]) continue;
            s.push(cur_node);
            s.push(next_node);
            goto LABEL;
        }
    }
    
    printf("\n");
    delete[] visit;
}

//bfs
void bfs(std::vector<std::vector<int> > &graph, int v, int &n) {
    bool *visit = new bool[n+1];
    for (int i = 0; i <= n; i++) {
        visit[i] = false;
    }
    
    std::queue<int> q;
    visit[v] = true;
    q.push(v);
    while(!q.empty()) {
        int cur_node = q.front();
        q.pop();
        printf("%d ", cur_node);
        
        for (int i = 0; i < graph[cur_node].size(); i++) {
            int next_node = graph[cur_node][i];
            if (visit[next_node]) continue;
            visit[next_node] = true;
            q.push(next_node);
        }
    }
    
    printf("\n");
    delete[] visit;
}


//재귀 dfs
void DFS(std::vector<std::vector<int> > &graph, int v, bool*visit) {
    visit[v] = true;
    printf("%d ", v);
    
    for (int i = 0; i < graph[v].size(); i++) {
        if (visit[graph[v][i]]) continue;
        DFS(graph, graph[v][i], visit);
    }
}
void dfs(std::vector<std::vector<int> > &graph, int v, int &n) {
    bool *visit = new bool[n+1];
    for (int i = 0; i <= n; i++) {
        visit[i] = false;
    }
    DFS(graph, v, visit);
    printf("\n");
    delete[] visit;
}


int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, v;
    std::cin >> n >> m >> v;
    std::vector<std::vector<int> > graph(n+1);
    for (int from, to, i = 0; i < m; i++) {
        std::cin >> from >> to;
        graph[from].push_back(to);
        graph[to].push_back(from);
    }
    
    for (int i = 1; i <= n; i++) {
        std::sort(graph[i].begin(), graph[i].end());
    }
    
    //dfs_(graph,v,n);
    dfs(graph, v, n);
    bfs(graph, v, n);
    
    return 0;
}
