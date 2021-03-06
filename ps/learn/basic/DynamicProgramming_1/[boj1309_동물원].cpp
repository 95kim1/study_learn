//[boj 1309 : 동물원](https://acmicpc.net/problem/1309)

#include <iostream>
#define MOD 9901

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int **d, n;
    std::cin >> n;
    d = new int*[n];
    for (int i = 0; i < n; i++) {
        d[i] = new int[3];
    }
    
    // d[n][i] : 2*n 우리 중에서, index가 n인 우리에 (i==0)사자x, (i==1)사자 윗칸에, (i==2)사자 아래칸에 놓는 방법 수
    d[0][0] = d[0][1] = d[0][2] = 1;
    for (int i = 1; i < n; i++) {
        d[i][0] = (d[i-1][0] + d[i-1][1] + d[i-1][2]) % MOD;
        d[i][1] = (d[i-1][0] + d[i-1][2]) % MOD;
        d[i][2] = (d[i-1][0] + d[i-1][1]) % MOD;
    }
    
    std::cout << (d[n-1][0] + d[n-1][1] + d[n-1][2]) % MOD << '\n';
    
    for (int i = 0; i < n; i++)
        delete[] d[i];
    delete[] d;
    
    return 0;
}
