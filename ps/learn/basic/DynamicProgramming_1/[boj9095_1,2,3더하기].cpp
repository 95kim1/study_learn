//[boj 9095 : 1,2,3 더하기](https://acmicpc.net/problem/9095)

#include <iostream>
int D[11];
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    D[1] = 1;
    D[2] = 2;
    D[3] = 4;
    int t, n;
    std::cin >> t;
    
    for (int i=4; i<11; i++) {
        D[i] = D[i-3] + D[i-2] + D[i-1];
    }
    
    while(t--) {
        std::cin >> n;
        std::cout << D[n] << '\n';
    }
    return 0;
}
