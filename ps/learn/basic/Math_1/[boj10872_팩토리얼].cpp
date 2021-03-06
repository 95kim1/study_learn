//[boj 10872 : 팩토리얼](https://www.acmicpc.net/problem/10872)

#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    long long num = 1;
    n++;
    while(--n) {
        num*=n;
    }
    std::cout << num << '\n';
    return 0;
}
