//[boj 10844 : 쉬운 계단 수](https://acmicpc.net/problem/10844)

#include <iostream>
#define MOD 1000000000

int main(void) {
    int n;
    std::cin >> n;
    
    int **D = new int*[n+1];
    for (int i=0; i<=n; i++)
        D[i] = new int[10];
    
    //길이 1
    for (int i=1; i<10; i++)
        D[1][i] = 1;
    //길이 2
    for (int i=0; i<10 && n > 1; i++) {
        D[2][i] = 0;
        if (i>=1)
            D[2][i] += D[1][i-1];
        if (i<9)
            D[2][i] += D[1][i+1];
    }
    //길이 3이상
    for (int i=3; i<=n; i++) {
        for (int j=0; j<10; j++) {
            D[i][j] = 0;
            if (j>=1)
                D[i][j] += D[i-1][j-1];
            if (j<9)
                D[i][j] += D[i-1][j+1];
            D[i][j]%=MOD;
        }
    }
    
    int sum = 0;
    for (int i=0; i<=9; i++) {
        sum=(D[n][i]+sum)%MOD;
    }
    
    printf("%d\n", sum);
    
    for (int i=0; i<=n; i++)
        delete[] D[i];
    delete[] D;
    
    return 0;
}
