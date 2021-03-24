//[boj 11054 : 가장 긴 바이토닉 부분 수열](https://acmicpc.net/problem/11054)

#include <iostream>

int maxLength(int *a, int n, int s, int e) {
    int di = 1;
    if (s > e) {
        di = -1;
    }
    int *d = new int[n];
    
    for (int i = s;  i != e+di; i+=di) {
        int temp = 0;
        for (int j = s; j != i; j+=di) {
            if (a[i] > a[j] && temp < d[j]) {
                temp = d[j];
            }
        }
        d[i] = temp + 1;
    }
    
    int i = d[e];
    delete[] d;
    return i;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int *a, n;
    std::cin >> n;
    a = new int[n];
    int *d = new int[n];
    int *d2 = new int[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0;  i < n; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && temp < d[j]) {
                temp = d[j];
            }
        }
        d[i] = temp + 1;
    }
    
    for (int i = n-1; i >= 0; i--) {
        d2[i] = 1;
        for (int j = n-1; j > i; j--) {
            if (a[i] > a[j] && d2[i] < d2[j] + 1) {
                d2[i] = d2[j] + 1;
            }
        }
    }
    
    int maxNum = 0;
    for (int i = 0; i < n; i++) {
        if (maxNum < d[i] + d2[i] - 1)
            maxNum = d[i] + d2[i] - 1;
    }
    
    std::cout << maxNum << '\n';
    
    delete[] a;
    delete[] d;
    delete[] d2;
    return 0;
}
