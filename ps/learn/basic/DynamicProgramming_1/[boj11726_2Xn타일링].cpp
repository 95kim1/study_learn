//[boj 11726 : 2Xn 타일링](https://acmicpc.net/problem/11726)

#include <iostream>
int D[1001];
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    D[0] = 1;
    D[1] = 1;
    int n;
    std::cin >> n;
    for (int i=2; i<=n; i++) {
        D[i] = (D[i-2] + D[i-1])%10007;
    }
    
    std::cout << D[n] << '\n';
    
    return 0;
}
