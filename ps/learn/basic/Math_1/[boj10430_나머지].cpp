//[boj 10430 : 나머지](https://www.acmicpc.net/problem/10430)

#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, c;
    std::cin >> a >> b >> c;
    
    std::cout << (a+b)%c << '\n' << (a%c+b%c)%c << '\n' << (a*b)%c << '\n' << ((a%c)*(b%c))%c << '\n';
    
    return 0;
}
