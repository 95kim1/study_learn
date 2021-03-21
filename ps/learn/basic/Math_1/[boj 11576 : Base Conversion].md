[boj 11576 : Base Conversion](https://www.acmicpc.net/problem/11576)

```c
#include <iostream>
#include <vector>
#include <string>
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::vector<int> va, vb;
    int a, b, n;
    std::cin >> a >> b >> n;
    
    for (int temp, i = 0; i < n; i++) {
        std::cin >> temp;
        va.push_back(temp);
    }
    
    n = 0;
    for (int d = 1, i = (int)va.size()-1; i >= 0; i--) {
        n += va[i] * d;
        d*=a;
    }
    
    while(n) {
        vb.push_back(n%b);
        n/=b;
    }
    
    for (int i = (int)vb.size()-1; i >= 0; i--) {
        std::cout << vb[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}
```
