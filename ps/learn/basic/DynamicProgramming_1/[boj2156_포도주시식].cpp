//[boj 2156 : 포도주 시식](https://acmicpc.net/problem/2156)

#include <iostream>
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    int *a = new int[n];
    int *d = new int[n];
    
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    // d[i] = max{a[i]+a[i-1]+d[i-3], a[i]+d[i-2], d[i-1]} = max{temp[0], temp[1], temp[2]}
    int temp[3];
    d[0] = a[0];
    for (int i = 0; i < n; i++) {
        temp[0] = temp[1] = a[i];
        temp[2] = 0;
        if (i > 0) {
            temp[0] += a[i-1];
            temp[2] += d[i-1];
        }
        if (i > 1) {
            temp[1] += d[i-2];
        }
        if (i > 2) {
            temp[0] += d[i-3];
        }
        
        if (temp[0] < temp[1]) temp[0] = temp[1];
        if (temp[0] < temp[2]) temp[0] = temp[2];
        
        d[i] = temp[0];
    }
    
    std::cout << d[n-1] << '\n';
    
    
    delete[]a;
    delete[]d;
    return 0;
}
