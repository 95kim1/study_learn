//[boj 9465 : 스티커](https://acmicpc.net/problem/9465)

#include <iostream>

int findMax(int &a, int &b) {
    return (a > b) ? a : b;
}
int findMax(int &a, int &b, int &c) {
    if (a > b) {
        if (c > a) return c;
        else return a;
    }
    else {
        if (c > b) return c;
        else return b;
    }
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int **a, **d, n, t;
    
    a = new int*[2];
    d = new int*[3];
    
    std::cin >> t;
    while (t--) {
        std::cin >> n;

        for (int i = 0; i < 2; i++) {
            a[i] = new int[n];
            for (int j = 0; j < n; j++)
                std::cin >> a[i][j];
            d[i] = new int[n];
        }
        d[2] = new int[n];
        
        d[0][0] = 0; d[1][0] = a[1][0]; d[2][0] = a[0][0];
        for (int i = 1; i < n; i++) {
            d[0][i] = findMax(d[0][i-1], d[1][i-1], d[2][i-1]);
            d[1][i] = a[1][i] + findMax(d[0][i-1], d[2][i-1]);
            d[2][i] = a[0][i] + findMax(d[0][i-1], d[1][i-1]);
        }
        
        int maxNum = d[0][n-1];
        if (maxNum < d[1][n-1]) maxNum = d[1][n-1];
        if (maxNum < d[2][n-1]) maxNum = d[2][n-1];
        
        std::cout << maxNum << '\n';
        
        for (int i = 0; i < 2; i++) {
            delete[] a[i];
            delete[] d[i];
        }
        delete[] d[2];
    }
    
    delete[] a;
    delete[] d;
    return 0;
}
