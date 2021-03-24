//[boj 1476 : 날짜 계산](https://www.acmicpc.net/problem/1476)

#include <iostream>
#define SUM(X, Y, Z) ((X)+(Y)+(Z))
/* 방법 : year mod 15 == e-1,  year mod 28 == s-1,  year mod 19 == m-1
 *          => year == e-1 mod 15,  year == s-1 mod 28,  year == m-1 mod 19
 *          => x == a[0] mod m[0],  x == a[1] mod m[1],  x == a[2] mod m[2]
 *
 *          - 중국인의 나머지 정리 이용 -
 *      x = a[i] % m[i], i=0~n 일 때,
 *      x = sum( M[i]*( (m[i]에 대한 M[i]의 역원) % m[i])*a[i], i=0~n) % M 이다.
 *      이 때, M = m[0]*...*m[n], M[i] = M / m[i]이다.
 *      m[i]에 대한 M[i]의 역원을 y라 할 때, M[i]*y = 1 % m[i] 이다. */
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int e, s, m;
    std::cin >> e >> s >> m;

    e--;
    s--;
    m--;

    // M[i]*( (m[i]에 대한 M[i]의 역원) % m[i])*a[i], i=0~2
    // i==0 => (28*19) * ( 13 % 15) * e == 28*19*13*e == M_[0] * M_inv[0] * e
    // i==1 => (15*19) * ( 17 % 28) * s == 15*19*17*s == M_[1] * M_inv[1] * s
    // i==2 => (15*28) * ( 10 % 19) * m == 15*29*10*m == M_[2] * M_inv[2] * m
    int M = 15 * 28 * 19;
    int M_[3] = {M/15, M/28, M/19};
    int M_inv[3] = {13, 17, 10};
    
    printf("%d\n", SUM(M_[0]*M_inv[0]*e, M_[1]*M_inv[1]*s, M_[2]*M_inv[2]*m) % M + 1);
    
    return 0;
}
