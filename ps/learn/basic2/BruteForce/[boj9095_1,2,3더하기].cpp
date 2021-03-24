//[boj 9095 : 1,2,3 더하기](https://www.acmicpc.net/problem/9095)

#include <iostream>

int cntMakeSum(int sum, int &n) {
    if (sum > n) {
        return 0;
    }
    else if (sum == n) {
        return 1;
    }
    
    int now = 0;
    for (int i = 1; i <= 3; i++) {
        now += cntMakeSum(sum+i, n);
    }
    return now;
}

/* 방법:
 *   1. 다이나믹 프로그래밍: d[n]:n을 만드는 경우의수, d[n] = d[n-1]+d[n-2]+d[n-3]
 * v 2. 브루트포스: 1,2,3으로 조합할 수 있는 모든 경우를 따진다.(목표 값보다 크지 않은 조합까지만)*/
int main(void) {
    int n, t;
    std::cin >> t;
    while(t--) {
        std::cin >> n;
        printf("%d\n",cntMakeSum(0, n));
    }
    return 0;
}
