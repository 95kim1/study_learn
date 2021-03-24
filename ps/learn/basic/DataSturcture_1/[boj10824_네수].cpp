//[boj 10824 : 네 수](https://www.acmicpc.net/problem/10824)

#include <iostream>
#include <string>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    
    std::cout << std::stoll(std::to_string(A)+std::to_string(B))+std::stoll(std::to_string(C)+std::to_string(D)) << '\n';
    
    return 0;
}

