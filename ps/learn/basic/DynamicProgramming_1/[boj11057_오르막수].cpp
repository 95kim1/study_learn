//[boj 11057 : 오르막 수](https://acmicpc.net/problem/11057)

#include <iostream>
#define MOD 10007

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int **d, n;
    std::cin >> n;
    d = new int*[n];
    for (int i = 0; i < n; i++) {
        d[i] = new int[10];
    }

    for (int j = 0; j < 10; j++)
        d[0][j] = 1;
    
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            d[i][j] = 0;
            for (int k = 0; k <= j; k++) {
                d[i][j] += d[i-1][k];
            }
            d[i][j] %= MOD;
        }
    }
    
    int cnt = d[n-1][0];
    for (int i = 1; i < 10; i++)
        cnt += d[n-1][i];
    
    std::cout << cnt % MOD << '\n';
        
    for (int i = 0; i < n; i++)
        delete[] d[i];
    delete[] d;
    
    return 0;
}

