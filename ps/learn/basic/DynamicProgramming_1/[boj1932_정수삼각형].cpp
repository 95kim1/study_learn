//[boj 1932 : 정수 삼각형](https://acmicpc.net/problem/1932)

#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int **a, **d, n;
    std::cin >> n;
    a = new int*[n];
    d = new int*[n];
    
    for (int i = 0; i < n; i++) {
        a[i] = new int[n];
        d[i] = new int[n];
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            std::cin >> a[i][j];
        }
    }
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            d[i][j] = a[i][j];
            if (i > 0) {
                if (j > 0)
                    d[i][j] += (d[i-1][j] > d[i-1][j-1]) ? d[i-1][j] : d[i-1][j-1];
                else
                    d[i][j] += d[i-1][j];
            }
        }
    }
    
    int maxNum = d[n-1][0];
    for (int i = 1; i < n; i++) {
        if (maxNum < d[n-1][i])
            maxNum = d[n-1][i];
    }
    
    std::cout << maxNum << '\n';
    
    for (int i = 0; i < n; i++) {
        delete[] d[i];
        delete[] a[i];
    }
    delete[] d;
    delete[] a;
    return 0;
}
