//[boj 15655 : N과M (6)](https://www.acmicpc.net/problem/15655)

#include <iostream>
#include <algorithm>
#include <vector>

void printSequences(std::vector<int> &num, std::vector<int> &sequence, std::vector<int>::iterator it_, int depth) {
    if (depth==0) {
        for (std::vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
            std::cout << *it << ' ';
        std::cout << '\n';
        return;
    }
    
    for (std::vector<int>::iterator it = it_; it != num.end(); it++) {
        sequence.push_back(*it);
        printSequences(num, sequence, it+1, depth-1);
        sequence.pop_back();
    }
}

/* 방법 :
 *      모든 수열을 다 탐색하기 위해 재귀함수를 쓴다.
 *      사전 순을 유지하기 위해서 sort를 쓴다.
 *      오름차순을 지키기 위해 최근 수열에 넣은 수의 다음 수를 재귀함수 인자로 넘긴다. */

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
    printSequences(num, sequence, num.begin(), m);

    return 0;
}
