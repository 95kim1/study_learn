//[boj 11052 : 카드 구매하기](https://acmicpc.net/problem/11052)

#include <iostream>
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    int *p, *D;
    std::cin >> n;
    p = new int[n+1];
    D = new int[n+1];
    
    for (int i=1; i<=n; i++) {
        std::cin >> p[i];
    }
    
    D[0] = 0;
    for (int i=1; i<=n; i++) {
        int maxNum = 0;
        for (int j=1; j<=i; j++) {
            if (maxNum < p[j] + D[i-j])
                maxNum = p[j] + D[i-j];
        }
        D[i] = maxNum;
    }
    
    printf("%d\n", D[n]);
    
    delete[]p;
    delete[]D;
    return 0;
}
