//[boj 10971 : 외판원 순회 2](https://www.acmicpc.net/problem/10971)

#include <iostream>
#include <algorithm>
#include <vector>

/* 방법 :
 *  모든 경로를 다 따져본다. (permutation 이용)
 *  단, 맨 앞의 경로가 바뀐다면 이미 따져 본 경로이므로 이후는 무시한다.
 *  ex) a1bc == 1bca, ab1c == 1cab, abc1 == 1abc */
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    std::vector<std::vector<int> > v;
    std::vector<int> num(n);
    for (int i = 0; i < n; i++) {
        num[i] = i;
        v.push_back(std::vector<int>(n));
        for (int j = 0; j < n; j++) {
            std::cin >> v[i][j];
        }
    }
    
    
    int ans = 10000000;
    do {
        int temp = 0;
        bool broken = false;
        for (int i = 1; i < n; i++) {
            if (v[num[i-1]][num[i]] == 0) {
                broken = true;
                break;
            }
            temp += v[num[i-1]][num[i]];
        }
        if (v[num[n-1]][num[0]]==0)
            broken = true;
        else
            temp += v[num[n-1]][num[0]];
        
        if (!broken && temp < ans) {
            ans = temp;
        }
    }while(std::next_permutation(num.begin(), num.end()) && num[0] == 0);
    
    printf("%d\n", ans);
    
    return 0;
}
