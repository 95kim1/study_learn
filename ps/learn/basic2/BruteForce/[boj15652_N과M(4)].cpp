//[boj 15652 : N과M (4)](https://www.acmicpc.net/problem/15652)

#include <iostream>
#include <string>

void allSequence(std::string num, int idx, int depth, int &n) {
    if (depth==0) {
        std::cout << num << '\n';
        return;
    }
    
    for (int i = idx; i <= n; i++) {
        if (num.empty())
            allSequence(num+std::to_string(i), i, depth-1, n);
        else
            allSequence(num+" "+std::to_string(i), i, depth-1, n);
    }
}

/* 방법 :
 *      모든 수열을 다 탐색하기 위해 재귀함수를 쓴다.
 *      비내림 차순을 유지하기 위해 재귀함수의 인자로 최근 수열에 넣은 수를 넘긴다.*/

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::string num;
    allSequence(num, 1, m, n);

    return 0;
}
