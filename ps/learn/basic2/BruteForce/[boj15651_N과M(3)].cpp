//[boj 15651 : N과M (3)](https://www.acmicpc.net/problem/15651)

#include <iostream>
#include <string>

void allSequence(std::string num, int depth, int &n) {
    if (depth==0) {
        std::cout << num << '\n';
        return;
    }
    
    for (int i = 1; i <= n; i++) {
        if (num.empty())
            allSequence(num+std::to_string(i), depth-1, n);
        else
            allSequence(num+" "+std::to_string(i), depth-1, n);
    }
}

/* 방법 :
 *      모든 수열을 다 탐색하기 위해 재귀함수를 쓴다. */

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::string num;
    allSequence(num, m, n);

    return 0;
}
