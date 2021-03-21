[boj 1149 : RGB 거리](https://acmicpc.net/problem/1149)

```c
#include <iostream>
#include <stack>
#include <string>
#define MOD 1000000009

int findMin(int &a, int &b) {
    return ((a > b) ? b : a);
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, **a, **ans;
    std::cin >> n;
    a = new int*[n];
    ans = new int*[n];
    for (int i = 0; i < n; i++) {
        a[i] = new int[3];
        ans[i] = new int[3];
    }
    for (int i = 0 ; i < n; i++) {
        std::cin >> a[i][0] >> a[i][1] >> a[i][2];
    }
    
    for (int i = 0; i < n; i++) {
        int color;
        for (color = 0; color < 3; color++) {
            ans[i][color] = a[i][color];
            
            if (i > 0) {
                ans[i][color] += findMin(ans[i-1][(color+1)%3], ans[i-1][(color+2)%3]);
            }
        }
    }
    
    int minCost = ans[n-1][0];
    for (int i = 1; i < 3; i++)
        minCost = (minCost > ans[n-1][i]) ? ans[n-1][i] : minCost;
    
    std::cout << minCost << '\n';
    
    for (int i = 0; i < n; i++) {
        delete[] a[i];
        delete[] ans[i];
    }
    delete[] a;
    delete[] ans;
    
    return 0;
}

```
