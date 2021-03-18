[boj 9613 : GCD 합](https://www.acmicpc.net/problem/9613)

```c
#include <iostream>

int GCD(int n, int m) {
    int temp;
    while(m!=0) {
        temp = m;
        m = n%m;
        n = temp;
    }
    return n;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    while (t--) {
        int n, *a;
        long long sum;
        std::cin >> n;
        a = new int[n];
        
        for (int i = 0; i < n; i++)
            std::cin >> a[i];
        
        if (n==1) {
            std::cout << a[0] << '\n';
            continue;
        }
        
        sum = 0;
        for (int i = 0; i < n-1; i++) {
            for (int j = i+1; j < n; j++) {
                sum+=GCD(a[i],a[j]);
            }
        }
        
        std::cout << sum << '\n';
        
        delete[] a;
    }
    
    return 0;
}
```
