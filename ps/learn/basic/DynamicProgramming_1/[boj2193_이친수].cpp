//[boj 2193 : 이친수](https://acmicpc.net/problem/2193)

#include <iostream>

int main(void) {
    int n;
    std::cin >> n;
    
    std::pair<long long, long long> *D = new std::pair<long long, long long>[n+1];
    D[1].first = 0; //길이 1, 마지막 수 0
    D[1].second = 1; //길이 1, 마지막 수 1
    
    for (int i=2; i<=n; i++) {
        D[i].first = D[i-1].first + D[i-1].second;
        D[i].second = D[i-1].first;
    }
    
    printf("%lld\n", D[n].first + D[n].second);
    
    return 0;
}
