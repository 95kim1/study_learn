[boj 1929 : 소수 구하기](https://www.acmicpc.net/problem/1929)

```c
#include <iostream>
int a[1000001];

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    //에라스토테네스의 
    a[0] = a[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (a[i]) continue;
        for (int j = i+i; j <= 1000000; j+=i)
            a[j] = 1;
    }
    
    int n, m;
    std::cin >> m >> n;
    
    for (int i = m; i <= n; i++) {
        if (!a[i]) std::cout << i << '\n';
    }
    
    return 0;
}
```
