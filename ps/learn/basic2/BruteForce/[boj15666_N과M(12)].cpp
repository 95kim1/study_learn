//[boj 15666 : N과M (12)](https://www.acmicpc.net/problem/15666)

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
        printSequences(num, sequence, it, depth-1);
        sequence.pop_back();
        
        int temp = *it;
        while(*it == temp && it != num.end()) {
            it++;
        }
        it--;
    }
}

/* 방법 : 
 *      모든 수열을 다 탐색하기 위해 재귀함수를 쓴다.
 *      사전 순을 유지하기 위해서 sort를 쓴다.
 *      출력할 수열을 뽑을 때, 같은 자리에 같은 숫자가 오지 않게 한다.(같은 수열 여러개 나오기 방지)
 *      각 자리수가 비내림차순을 유지해야 하므로 최근 사용한 수 다음 수를 인자로 넘긴다.*/

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
    std::sort(num.begin(), num.end(), [](int a, int b)->bool{return (a > b)?false:true;});
    printSequences(num, sequence, num.begin(), m);

    return 0;
}
