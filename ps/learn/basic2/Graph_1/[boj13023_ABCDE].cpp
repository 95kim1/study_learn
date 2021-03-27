//[boj 13023 : ABCDD](https://www.acmicpc.net/problem/13023)

#include <iostream>
#include <vector>

bool findABCDE(std::vector<std::vector<int> > & graph, bool *visit, int depth, int cur_node, int &n) {
    if (depth == 5) {
        return true;
    }
    
    bool flag_ABCDE = false;
    for (int i = 0; i < graph[cur_node].size(); i++) {
        if (visit[graph[cur_node][i]]) continue;
        visit[graph[cur_node][i]] = true;
        flag_ABCDE = (flag_ABCDE || findABCDE(graph, visit, depth+1, graph[cur_node][i], n));
        visit[graph[cur_node][i]] = false;
    }
    return flag_ABCDE;
}

/* 방법:
 *  우선 친구관계를 인접리스트 그래프로 만든다.
 *  각 정점(사람)마다 친구관계를 탐색하여 5명이 연달아 연결되어 있는지 탐색한다. */
int main(void) {
    int n, m;
    bool *visit;
    std::cin >> n >> m;
    std::vector<std::vector<int> > graph(n);
    visit = new bool[n];
    for (int i = 0; i < n; i++) {
        visit[i] = false;
    }
    for (int v1, v2, i = 0; i < m; i++) {
        std::cin >> v1 >> v2;
        graph[v1].push_back(v2);
        graph[v2].push_back(v1);
    }
    
    int trueFalse = 0;
    for (int i = 0; i < n; i++) {
        if (findABCDE(graph, visit, 0, i, n)) {
            trueFalse = 1;
            break;
        }
    }
    
    printf("%d\n", trueFalse);
    delete[]visit;
    return 0;
}
