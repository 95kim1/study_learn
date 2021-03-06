//[boj 15650 : N과M (2)](https://www.acmicpc.net/problem/15650)

#include <iostream>
#include <vector>

void allSequence(std::vector<int> &num, int depth, int &n) {
    if (depth==0) {
        for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++) {
            printf("%d ", *it);
        }
        printf("\n");
        return;
    }
    int i = (num.empty()) ? 1 : num.back()+1;
    for (; i <= n; i++) {
        num.push_back(i);
        allSequence(num, depth-1, n);
        num.pop_back();
    }
}

/* 방법 :
 *      모든 수열을 다 탐색하기 위해 재귀함수를 쓴다.
 *      오름차순인 수열을 찾기 위해서 마지막 다음 수부터 수열에 쌓는다. */

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m; 
    std::cin >> n >> m;
    std::vector<int> num;
    
    allSequence(num, m, n);

    return 0;
}
