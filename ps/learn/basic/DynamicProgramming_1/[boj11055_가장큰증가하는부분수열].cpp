//[boj 11055 : 가장 큰 증가하는 부분 수열](https://acmicpc.net/problem/11055)

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
    
    d[0] = a[0];
    for (int i = 1;  i < n; i++) {
        d[i] = a[i];
        int temp = 0;
        for (int j = 0; j < i; j++) {
            if (a[i] > a[j] && temp < d[j]) {
                temp = d[j];
            }
        }
        d[i] += temp;
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
