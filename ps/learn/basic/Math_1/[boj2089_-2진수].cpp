[boj 2089 : -2진수](https://www.acmicpc.net/problem/2089)

```c
#include <iostream>
#include <string>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string ans;
    int n, temp;
    std::cin >> n;

    while(n) {
        temp = n%2;
        ans += (temp < 0) ? -temp+'0' : temp+'0';
        n = (n>0) ? n/-2 : (n-1)/-2;
    }
    
    int s = 0, e = (int)ans.length()-1;
    while(s < e) {
        temp = ans[e];
        ans[e--] = ans[s];
        ans[s++] = temp;
    }
    
    if (ans.empty())
        ans+='0';
    
    std::cout << ans << '\n';
    
    return 0;
}
```
