//[boj 15988 : 1,2,3 더하기 3](https://acmicpc.net/problem/15988)

#include <iostream>
#include <stack>
#include <string>
#define MOD 1000000009

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int *a;
    a = new int[1000001];
    for (int i = 0; i < 1000001; i++)
        a[i] = 0;
    
    
    a[1] = 1;
    a[2] = 2;
    a[3] = 4;
    
    for (int n = 4; n < 1000001; n++) {
        a[n] = ((a[n-1] + a[n-2])%MOD + a[n-3])%MOD;
    }
    
    int t;
    std::cin >> t;
    
    while(t--) {
        int n;
        std::cin >> n;
        std::cout << a[n] << '\n';
    }
    delete[] a;
    return 0;
}
