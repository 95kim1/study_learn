//[boj 1676 : 팩토리얼 0의 개수](https://www.acmicpc.net/problem/1676)

#include <iostream>
int a[501]; // a[n] : n을 소인수 분해했을 때 5의 개수
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    for (int i = 5; i <= 125; i *= 5) {
        for (int j = i; j <= 500; j += i) {
            a[j]++;
        }
    }
    
    int cnt = 0;
    for (int i = 5; i <= n; i++) {
        cnt += a[i];
    }
    
    std::cout << cnt << '\n';
    
    return 0;
}
