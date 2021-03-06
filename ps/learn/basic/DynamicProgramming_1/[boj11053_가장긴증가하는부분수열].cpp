//[boj 11053 : 가장 긴 증가하는 부분 수열](https://acmicpc.net/problem/11053)

#include <iostream>

int main(void) {
    int n;
    std::cin >> n;
    
    int *D = new int[n], *A = new int[n];
    for (int i=0; i<n; i++) {
        std::cin >> A[i];
    }
    
    D[0] = 1;
    for (int i=1; i<n; i++) {
        D[i] = 1;
        for (int j = i-1; j >= 0; j--) {
            if (A[i] > A[j] && D[i] < 1+D[j]) {
                D[i] = 1 + D[j];
            }
        }
    }
    
    int maxNum = D[0];
    for (int i = 1; i < n; i++) {
        if (maxNum < D[i])
            maxNum = D[i];
    }
    
    printf("%d\n", maxNum);
    
    delete[]D;
    delete[]A;
    return 0;
}
