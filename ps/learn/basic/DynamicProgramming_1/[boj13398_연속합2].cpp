//[boj 13398 : 연속합 2](https://acmicpc.net/problem/13398)
#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    int *a = new int[n];
    int *d = new int[n];
    int *d2 = new int[n];
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    //d[i] : i번째 수를 끝으로 하는 연속 수열 중 최대 합
    //d2[i] : i번째 수를 처음으로 하는 연속 수열 중 최대 합
    for (int i = 0; i < n; i++) {
        d[i] = a[i];
        if (i > 0 && d[i] < d[i] + d[i-1]) {
            d[i] += d[i-1];
        }
    }
    
    for (int i = n-1; i >= 0; i--) {
        d2[i] = a[i];
        if (i < n-1 && d2[i] < d2[i] + d2[i+1]) {
            d2[i] += d2[i+1];
        }
    }
    
    int maxNum = d[0];
    for (int i = 1; i < n-1; i++) {
        int temp = d[i];
        if (temp > maxNum) maxNum = temp;
        temp = d[i-1] + d2[i+1];
        if (temp > maxNum) maxNum = temp;
    }
    if (maxNum < d[n-1]) maxNum = d[n-1];
    
    std::cout << maxNum << '\n';
    
    delete[]d2;
    delete[]d;
    delete[]a;
    return 0;
}

