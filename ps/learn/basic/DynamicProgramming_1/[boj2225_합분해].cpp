//[boj 2225 : 합분해](https://acmicpc.net/problem/2225)

#include <iostream>
#define MOD 1000000000

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int **dp;
    int n, k;
    std::cin >> n >> k;
    
    //dp[i][j] : 0~n 정수 i개의 합으로 j 만드는 경우의 수
    dp = new int*[k+1];
    for (int i = 0; i <= k; i++) {
        dp[i] = new int[n+1];
    }
    
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        dp[0][i] = 0;
    
    for (int i = 1; i <= k; i++) {
        for (int j = 0; j <= n; j++) {
            dp[i][j] = 0;
            for (int t = 0; t <= j; t++) {
                dp[i][j] = (dp[i][j] + dp[i-1][t])%MOD;
            }
        }
    }
    
    std::cout << dp[k][n] << '\n';
    
    for (int i = 0; i <= k; i++) {
        delete[] dp[i];
    }
    delete[] dp;
    
    return 0;
}
