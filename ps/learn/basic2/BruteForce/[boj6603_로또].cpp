//[boj 6603 : 로또](https://www.acmicpc.net/problem/6603)

#include <iostream>
#include <algorithm>
#include <vector>

void printAll(std::vector<int> &v, int k) {
    for (int i = 0; i < k; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
}

void lotto(std::vector<std::pair<int, bool> > &v, int idx, int depth, int &k) {
    if (depth == 0) {
        for (int i = 0; i < k; i++) {
            if (!v[i].second) continue;
            printf("%d ", v[i].first);
        }
        printf("\n");
        return;
    }
    
    for (int i = idx; i <= k-depth; i++) {
        v[i].second = true;
        lotto(v, i+1, depth-1, k);
        v[i].second = false;
    }
}

/* 방법 :
 *  순열(선택) : dfs 이용
 *  선택을 표시하기 위해서 pair<int, bool>이용 */
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<std::pair<int,bool> > v(13);
    
    int k;
    std::cin >> k;
    while(k) {
        for (int i = 0; i < k; i++) {
            std::cin >> v[i].first;
            v[i].second = false;
        }
        
        lotto(v, 0, 6, k);
        printf("\n");
        
        std::cin >> k;
    }
    return 0;
}
