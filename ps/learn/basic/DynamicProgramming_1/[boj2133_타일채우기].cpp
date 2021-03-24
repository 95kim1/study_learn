//[boj 2133 : 타일 채우기](https://acmicpc.net/problem/2133)

#include <iostream>
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    if (n%2==1) {
        printf("0\n");
        return 0;
    }
    
    n/=2;
    int *d = new int[n+1];
    
    d[0] = 1; d[1] = 3;
    for (int i = 2; i <= n; i++) {
        d[i] = d[i-1] * 3;
        for (int j = 0; j < i-1; j++) {
            d[i] += 2*d[j];
        }
    }
    printf("%d\n", d[n]);
    return 0;
}
