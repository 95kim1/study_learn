//[boj 1476 : 날짜 계산](https://www.acmicpc.net/problem/1476)

#include <iostream>
#include <vector>
#include <string>

/* 방법 : year를 증가 시켜서 year%15, %28, %19 == E-1, S-1, M-1 인 year를 찾는다. */
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int e, s, m;
    std::cin >> e >> s >> m;
    
    e--;
    s--;
    m--;
    int y = 0;
    while(!(y%15==e && y%28==s && y%19==m)) {
        y++;
    }
    
    printf("%d\n", ++y);
    
    return 0;
}
