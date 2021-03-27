//[boj 14391 : 종이 조각](https://www.acmicpc.net/problem/14391)

#include <iostream>
#include <string>
#define ABS(X) ((X<0)?-(X):X)
#define MIN(X,Y) ((X<Y)?X:Y)

/* 방법:
 *  2차원 배열을 쭉 늘어뜨려 각 cell을 정수의 비트 하나에 대응하도록 한다.
 *  각 비트가 0이면 가로, 1이면 세로를 상징하도록 하여 모든 정수를 따져본다.*/
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m;
    std::cin >> n >> m;
    std::string *s = new std::string[n];
    for (int i = 0; i < n; i++) {
        std::cin >> s[i];
    }
    
    int maxSum = 0;
    for (int bitmask = 0; bitmask < (1<<(n*m)); bitmask++) {
        int sum = 0;
        // 가로
        for (int r = 0; r < n; r++) {
            int temp = 0;
            int d = 1;
            for (int c = m-1; c >= 0; c--) {
                if (bitmask & (1 << (r*m + c))) {
                    sum += temp;
                    temp = 0;
                    d = 1;
                }
                else {
                    temp += (s[r][c]-'0') * d;
                    d*=10;
                }
            }
            sum += temp;
        }
        //세로
        for (int c = 0; c < m; c++) {
            int temp = 0;
            int d = 1;
            for (int r = n-1; r >= 0; r--) {
                if (bitmask & (1 << (r*m + c))) {
                    temp += (s[r][c]-'0') * d;
                    d *= 10;
                }
                else {
                    sum += temp;
                    temp = 0;
                    d = 1;
                }
            }
            sum += temp;
        }
        maxSum = (maxSum < sum) ? sum : maxSum;
    }
    
    printf("%d\n", maxSum);
    
    delete[]s;
    return 0;
}
