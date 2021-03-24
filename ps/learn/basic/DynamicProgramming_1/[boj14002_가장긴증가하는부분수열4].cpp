//[boj 14002 : 가장 긴 증가하는 부분 수열 4](https://acmicpc.net/problem/14002)

#include <iostream>
#include <stack>

int main(void) {
    int n;
    std::cin >> n;
    
    int *D = new int[n], *A = new int[n], *path = new int[n];
    for (int i=0; i<n; i++) {
        std::cin >> A[i];
        path[i] = -1;
    }
    
    D[0] = 1;
    for (int i=1; i<n; i++) {
        D[i] = 1;
        for (int j = i-1; j >= 0; j--) {
            if (A[i] > A[j] && D[i] < 1+D[j]) {
                D[i] = 1 + D[j];
                path[i] = j;
            }
        }
    }
    
    int maxNum = D[0], maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (maxNum < D[i]) {
            maxNum = D[i];
            maxIndex = i;
        }
    }
    
    printf("%d\n", maxNum);
    
    std::stack<int> s;
    for (int i=maxIndex; i != -1; i = path[i]) {
        s.push(A[i]);
    }
    while(!s.empty()) {
        printf("%d ", s.top());
        s.pop();
    }
    printf("\n");
    
    delete[]D;
    delete[]A;
    return 0;
}
