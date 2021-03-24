//[boj 15656 : N과M (7)](https://www.acmicpc.net/problem/15656)

#include <iostream>
#include <algorithm>
#include <vector>

void printSequences(std::vector<int> &num, std::vector<int> &sequence, int depth) {
    if (depth==0) {
        for (std::vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
            std::cout << *it << ' ';
        std::cout << '\n';
        return;
    }
    
    for (std::vector<int>::iterator it = num.begin(); it != num.end(); it++) {
        sequence.push_back(*it);
        printSequences(num, sequence, depth-1);
        sequence.pop_back();
    }
}

/* 방법 :
 *      모든 수열을 다 탐색하기 위해 재귀함수를 쓴다.
 *      사전 순을 유지하기 위해서 sort를 쓴다. */

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<int> num(n);
    std::vector<int> sequence;
    for (int i = 0; i < n; i++) {
        std::cin >> num[i];
    }
    std::sort(num.begin(), num.end(), [](int a, int b)->bool{return (a>b)?false:true;});
    printSequences(num, sequence, m);

    return 0;
}
