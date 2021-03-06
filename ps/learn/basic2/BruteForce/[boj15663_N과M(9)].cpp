//[boj 15663 : N과M (9)](https://www.acmicpc.net/problem/15663)

#include <iostream>
#include <algorithm>
#include <vector>

void printSequences(std::vector<std::pair<int, bool> > &num, std::vector<int> &sequence, int depth) {
    if (depth==0) {
        for (std::vector<int>::iterator it = sequence.begin(); it != sequence.end(); it++)
            std::cout << *it << ' ';
        std::cout << '\n';
        return;
    }
    
    for (std::vector<std::pair<int,bool> >::iterator it = num.begin(); it != num.end(); it++) {
        if (it->second) continue;
        
        it->second = true;
        sequence.push_back(it->first);
        printSequences(num, sequence, depth-1);
        sequence.pop_back();
        it->second = false;
        
        int temp = it->first;
        while(it->first == temp && it != num.end()) {
            it++;
        }
        it--;
    }
}

/* 방법 :
 *      모든 수열을 다 탐색하기 위해 재귀함수를 쓴다.
 *      사전 순을 유지하기 위해서 sort를 쓴다.
 *      중복 사용 불가이므로 pair<int, bool>로 사용여부를 기록한다.
 *      출력할 수열을 뽑을 때, 같은 자리에 같은 숫자가 오지 않게 한다. */

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    std::vector<std::pair<int,bool> > num(n);
    std::vector<int> sequence;
    for (int i = 0; i < n; i++) {
        std::cin >> num[i].first;
        num[i].second = false;
    }
    std::sort(num.begin(), num.end(), [](std::pair<int, bool> a, std::pair<int,bool> b)->bool{return (a.first>b.first)?false:true;});
    printSequences(num, sequence, m);

    return 0;
}
