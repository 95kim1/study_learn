//[boj 11722 : 가장 긴 감소하는 부분 수열](https://acmicpc.net/problem/11722)

#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int *a, *d, n;
    std::cin >> n;
    a = new int[n];
    d = new int[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    for (int i = 0;  i < n; i++) {
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] < a[j] && temp < d[j]) {
                temp = d[j];
            }
        }
        d[i] = temp + 1;
    }
    
    int i = 0;
    for (int j = 1; j < n; j++)
        if (d[i] < d[j])
            i = j;
    
    std::cout << d[i] << '\n';
    
    delete[] d;
    delete[] a;
    return 0;
}
