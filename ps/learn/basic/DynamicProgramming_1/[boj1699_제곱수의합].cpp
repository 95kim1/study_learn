//[boj 1699 : 제곱수의 합](https://acmicpc.net/problem/1699)

#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    int *D = new int[n+1];
    
    for (int i = 0; i <= n; i++) {
        D[i] = 100000;
    }
    
    D[0] = 0;
    D[1] = 1;
    for (int j, i = 2; i<=n; i++) {
        j = 1;
        for (int J = j*j; J <= i; J=j*j) {
            if (D[i-J]+1 < D[i])
                D[i] = D[i-J]+1;
            j++;
        }
    }
    
    printf("%d\n", D[n]);
    
    delete[] D;
    return 0;
}
