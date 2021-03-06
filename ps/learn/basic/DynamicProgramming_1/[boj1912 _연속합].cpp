//[boj 1912 : 연속합](https://acmicpc.net/problem/1912)

#include <iostream>

int main(void) {
    int n;
    std::cin >> n;
    int *A = new int[n];
    int *D = new int[n];
    
    for (int i=0;i<n;i++) {
        std::cin >> A[i];
    }
    
    int maxNum = A[0];
    D[0] = A[0];
    for (int i=1;i<n;i++) {
        D[i] = D[i-1]+A[i];
        D[i] = (D[i] > A[i]) ? D[i] : A[i];
        if (maxNum < D[i])
            maxNum = D[i];
    }
    
    printf("%d\n", maxNum);
    
    return 0;
}
