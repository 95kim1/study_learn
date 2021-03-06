//[boj 15649 : N과M (1)](https://www.acmicpc.net/problem/15649)

#include <iostream>
#include <vector>

void allSequence(std::vector<int> &num, bool *visit, int depth, int &n) {
    if (depth==0) {
        for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (visit[i]) continue;
        visit[i] = true;
        num.push_back(i);
        allSequence(num, visit, depth-1, n);
        num.pop_back();
        visit[i] = false;
    }
}

/* 방법 :
 *      모든 수열을 다 탐색하기 위해 재귀함수를 쓴다.
 *      중복 없이 수를 써야 하므로 어떤 수를 썼는지 기록하는 배열을 만든다. */

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; // mPn
    std::cin >> n >> m;
    bool *visit = new bool[n+1];
    for (int i = 0; i <= n; i++)
        visit[i] = false;
    std::vector<int> num;
    
    allSequence(num, visit, m, n);
    
    delete[]visit;
    return 0;
}
