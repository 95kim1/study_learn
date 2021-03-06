//[boj 17087 : 숨바꼭질6](https://www.acmicpc.net/problem/17087)

#include <iostream>

long long GCD(long long n, long long m) {
    long long temp;
    while(m!=0) {
        temp = m;
        m = n%m;
        n = temp;
    }
    return n;
}

int abs(int a) {
    if (a<0)
        a = -a;
    return a;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, s, *a;
    std::cin >> n >> s;
    a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
        a[i] = abs(s-a[i]);
    }
    
    long long ans = a[0];
    for (int i = 1; i < n; i++) {
        ans = GCD(a[i], ans);
    }
    
    std::cout << ans << '\n';
    delete[] a;
    return 0;
}
