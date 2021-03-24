//[boj 15664 : N과M (10)](https://www.acmicpc.net/problem/15664)

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
        
        int temp = *it;
        while(*it == temp && it != num.end()) {
            it++;
        }
        it--;
    }
}

/* 방법 : 같은 수 == 같은 자리에 있는 수 (!= 크기가 같은 수) ex 1 7 9 9  3번째 9와 4번째 9는 다르다.
 *      모든 수열을 다 탐색하기 위해 재귀함수를 쓴다.
 *      사전 순을 유지하기 위해서 sort를 쓴다.
 *      출력할 수열을 뽑을 때, 같은 자리에 같은 숫자가 오지 않게 한다.
 *      비내림차순을 유지해야 하고 중복 사용 불가이므로 최근 사용한 수 다음 수를 인자로 넘긴다.*/

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
