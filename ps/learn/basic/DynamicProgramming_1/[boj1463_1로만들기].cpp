//[boj 1463 : 1로 만들기](https://acmicpc.net/problem/1463)

#include <iostream>

int makeOne(int n, int *a) {
    if (n == 1) return 0;
    if (a[n] > 0) return a[n];
    
    a[n] = 1 + makeOne(n-1, a);
    
    if (n%3 == 0) {
        int temp = 1 + makeOne(n/3, a);
        if (temp < a[n]) a[n] = temp;
    }
    
    if (n%2 == 0 ) {
        int temp = 1 + makeOne(n/2, a);
        if (temp < a[n]) a[n] = temp;
    }
    
    return a[n];
}

int main(void) {
    int *a, n;
    std::cin >> n;
    
    a = new int[n+1];
    for (int i = 0; i < n+1; i++)
        a[i] = 0;
    
    makeOne(n, a);
    
    std::cout << a[n] << '\n';
    
    delete[] a;
    
    return 0;
}

