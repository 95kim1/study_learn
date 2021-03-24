//[boj 2004 : 조합 0의 개수](https://www.acmicpc.net/problem/2004)

#include <iostream>
//nCm = n! / (n-m)! / m!
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, cnt2 = 0, cnt5 = 0, maxNum;
    std::cin >> n >> m;
    maxNum = (n>m)?n:m;
    for (long long i = 2; i <= maxNum; i*=2)
        cnt2 += n/i - (n-m)/i - m/i; // cnt2의 최종 결과 = (n! 2의 개수) - ((n-m)! 2의 개수) - (m! 2의 개수)  
        
    for (long long i = 5; i <= maxNum; i*=5)
        cnt5 += n/i - (n-m)/i - m/i;
    
    std::cout << ((cnt2>cnt5)?cnt5:cnt2) << '\n';
    
    return 0;
}
