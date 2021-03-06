//[boj 6064 : 카잉 달력](https://www.acmicpc.net/problem/6064)

#include <iostream>

int gcd(int m, int n) {
    while(n!=0) {
        int temp = n;
        n = m%n;
        m = temp;
    }
    return m;
}

/* 방법 :
 *      x, y값을 받은 뒤 x, x에서 시작하여
 *      x에 M을 계속 더하며 y가 나올 때까지 얼마나 더했는지 기록한다.
 *      만약 N번 반복해도 못 찾는다면 표현이 되지 않는 연도다. */
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while(t--) {
        int m,n,x,y;
        std::cin >> m >> n >> x >> y;
        int year = x; // <x,y>를 찾기 위해 <x,x>에서 시작하므로 연도를 기본으로 x로 맞춘다.
        x--; y--; // 모듈러 연산을 위해서 1을 빼줘서 첫 수를 0으로 맞췄다.
        x%=n; // x >= n인 케이스 방지
        int gcd_ = gcd(m,n);
        for (int i = 0; i <= n/gcd_; i++) {
            if (x==y) break;
            x = (x+m) % n;
            year+=m;
        }
        if (x!=y) {
            printf("-1\n");
        }
        else {
            printf("%d\n", year);
        }
    }
    return 0;
}
