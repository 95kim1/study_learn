//[boj 15990 : 1,2,3 더하기 5](https://acmicpc.net/problem/15990)

#include <iostream>
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t, n;
    std::cin >> t;
    int **D = new int*[3];
    for (int i=0; i<=2; i++)
        D[i] = new int[100001];
    
    D[0][1] = 1;
    D[1][1] = 0;
    D[2][1] = 0;
    D[0][2] = 0;
    D[1][2] = 1;
    D[2][2] = 0;
    D[0][3] = 1;
    D[1][3] = 1;
    D[2][3] = 1;
    
    const int ll = 1000000009;
    
    for (int i=4; i<=100000; i++) {
        for (int j=0; j<=2; j++) {
            D[j][i] = (D[(j+1)%3][i-j-1]+D[(j+2)%3][i-j-1])%ll;
        }
    }
    
    while(t--) {
        std::cin >> n;
        std::cout << ((D[0][n]+D[1][n])%ll+D[2][n])%ll << '\n';
    }
    
    for (int i=0; i<=2; i++)
        delete[]D[i];
    delete[]D;
    
    return 0;
}
