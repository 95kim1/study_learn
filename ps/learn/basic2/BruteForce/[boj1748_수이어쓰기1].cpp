//[boj 1748 : 수 이어 쓰기 1](https://www.acmicpc.net/problem/1748)

#include <iostream>

int lengthOfNum(int N) {
    int cnt = 0;
    while(N > 0) {
        N/=10;
        cnt++;
    }
    return cnt;
}

/* 방법 :
 *      입력 받은 수, N의 자리수를 센다.
 *      n자리수면,
 *      (10^1-10^0)*1 + ... + (10^(n-1) - 10^(n-2))*(n-1) + (N-10^(n-1))*n + n 이 답이다. */
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    int b = 1; int ans = 0;
    
    int n = lengthOfNum(N);
    
    for (int i = 1; i < n; i++) {
        ans += (b*10 - b) * i;
        b*=10;
    }
    ans += (N - b) * n + n;
    
    printf("%d\n", ans);
    
    return 0;
}
