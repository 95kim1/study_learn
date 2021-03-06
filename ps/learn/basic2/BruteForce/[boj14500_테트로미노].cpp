//[boj 14500 : 테트로미노](https://www.acmicpc.net/problem/14500)

#include <iostream>
#include <string>
#define MAX(X,Y) ((X>Y)?X:Y)

/* 방법 :
 *      테트로미노의 모든 case는 19가지 이다.
 *      각각의 케이스의 한 점을 선택하여 그 점을 기준으로,
 *      종이의 각 cell마다 해당 테트로미노 모양 그대로 놓아 값을 계산하고 최대값을 갱신한다.
 *      종이 바깥으로 삐져나가는 부분은 예외처리 대신 0을 더해서 최대값 갱신을 막아준다. */
int main(void) {
    int n, m;
    std::cin >> n >> m;
    int **a = new int*[n+5];
    for (int i = 0; i < n+5; i++) {
        a[i] = new int[m+5];
        for (int j = 0; j < m+5; j++) {
            a[i][j] = 0;
        }
    }
    
    for (int i = 2; i < n+2; i++) {
        for (int j = 2; j < m+2; j++) {
            std::cin >> a[i][j];
        }
    }
    
    int maxSum = 0;
    for (int i = 2; i < n+2; i++) {
        for (int j = 2; j < m+2; j++) {
            // shape : ㅁ
            maxSum = MAX( maxSum, a[i][j]+a[i][j+1]+a[i+1][j]+a[i+1][j+1] );
            
            // shape : ㅡ
            maxSum = MAX( maxSum, a[i][j]+a[i][j+1]+a[i][j+2]+a[i][j+3] );
            maxSum = MAX( maxSum, a[i][j]+a[i+1][j]+a[i+2][j]+a[i+3][j] );
       
            // shape : ㅜ
            maxSum = MAX( maxSum, a[i][j]+a[i+1][j]+a[i][j-1]+a[i][j+1] );
            maxSum = MAX( maxSum, a[i][j]+a[i][j+1]+a[i+1][j]+a[i-1][j] );
            maxSum = MAX( maxSum, a[i][j-1]+a[i][j]+a[i][j+1]+a[i-1][j] );
            maxSum = MAX( maxSum, a[i][j]+a[i][j-1]+a[i+1][j]+a[i-1][j] );
            
            // shape : ㄱ_
            maxSum = MAX( maxSum, a[i][j]+a[i][j+1]+a[i+1][j+1]+a[i+1][j+2] );
            maxSum = MAX( maxSum, a[i][j]+a[i][j+1]+a[i-1][j+1]+a[i-1][j+2] );
            maxSum = MAX( maxSum, a[i][j]+a[i+1][j]+a[i+1][j+1]+a[i+2][j+1] );
            maxSum = MAX( maxSum, a[i][j]+a[i+1][j]+a[i+1][j-1]+a[i+2][j-1] );
            
            // shape : |_
            maxSum = MAX( maxSum, a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j+1] );
            maxSum = MAX( maxSum, a[i][j]+a[i][j+1]+a[i][j+2]+a[i-1][j+2] );
            maxSum = MAX( maxSum, a[i][j]+a[i-1][j]+a[i-2][j]+a[i-2][j-1] );
            maxSum = MAX( maxSum, a[i][j]+a[i][j-1]+a[i][j-2]+a[i+1][j-2] );
            
            // shape : _|
            maxSum = MAX( maxSum, a[i][j]+a[i+1][j]+a[i+2][j]+a[i+2][j-1] );
            maxSum = MAX( maxSum, a[i][j]+a[i][j+1]+a[i][j+2]+a[i+1][j+2] );
            maxSum = MAX( maxSum, a[i][j]+a[i-1][j]+a[i-2][j]+a[i-2][j+1] );
            maxSum = MAX( maxSum, a[i][j]+a[i][j-1]+a[i][j-2]+a[i-1][j-2] );
        }
    }
    
    std::cout << maxSum << '\n';
    
    for (int i = 0; i < n; i++) {
        delete[] a[i];
    }
    delete[]a;
    
    return 0;
}
