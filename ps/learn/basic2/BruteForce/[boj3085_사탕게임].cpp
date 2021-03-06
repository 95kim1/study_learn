//[boj 3085 : 사탕게임](https://www.acmicpc.net/problem/3085)

#include <iostream>
#include <vector>
#include <string>
#define SWAP(X, Y, type) do {\
    type temp;\
    temp=X;\
    X=Y;\
    Y=temp;\
} while(0)
#define MAX(X,Y) ((X<Y)?Y:X)

/* 목적 : 모든 행과 열을 체크하여 가장 긴 연속된 캔디의 개수를 구한다. */
int maxCandyCheck(std::vector<std::string> &a) {
    int ans = 1, temp, n = (int)a.size();
    
    for (int i = 0; i < n; i++) {
        //i:행
        temp = 1;
        for (int j = 1; j < n; j++) {
            if (a[i][j] == a[i][j-1])
                temp++;
            else
                temp = 1;
            
            if (ans < temp) ans = temp;
        }
        
        //i:열
        temp = 1;
        for (int j = 1; j < n; j++) {
            if (a[j][i] == a[j-1][i])
                temp++;
            else
                temp = 1;
            
            if (ans < temp) ans = temp;
        }
    }
    
    return ans;
}

/* 목적 : 해당 좌표를 포함하는 행과 열을 체크하여 가장 긴 연속된 캔디의 개수를 구한다. */
int maxCandyCheck(std::vector<std::string> &a, int r, int c) {
    int ans = 1, temp, n = (int)a.size();
    
    //r행 (i:열)
    temp = 1;
    for (int i = 1; i < n; i++) {
        if (a[r][i] == a[r][i-1])
            temp++;
        else
            temp = 1;
        
        if (ans < temp) ans = temp;
    }
    
    //c열 (i:행)
    temp = 1;
    for (int i = 1; i < n; i++) {
        if (a[i][c] == a[i-1][c])
            temp++;
        else
            temp = 1;
        
        if (ans < temp) ans = temp;
    }
    
    return ans;
}

/* 방법 :
 *      바꾸지 않은 상태에서 최대로 연속된 캔디의 수를 구한다.
 *      각 cell 마다 오른쪽 한 번, 아래쪽 한 번씩 swap후
 *      해당 2개의 cell이 포함된 행과 열에서 최대로 연속된 캔디의 수를 구한다. */
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n;
    std::cin >> n;
    
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
        std::cin >> a[i];
    
    int ans = maxCandyCheck(a)/* 아무것도 안 바꿨을 때의 최대 연속 사탕 개수 */;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //오른쪽 (i,j), (i,j+1)
            if (j<n-1) {
                SWAP(a[i][j], a[i][j+1], char);
                ans = MAX( ans, MAX(maxCandyCheck(a, i, j), maxCandyCheck(a, i, j+1)) );
                SWAP(a[i][j], a[i][j+1], char);
            }
            //아래쪽 (i,j), (i+1,j)
            if (i<n-1) {
                SWAP(a[i][j], a[i+1][j], char);
                ans = MAX( ans, MAX(maxCandyCheck(a, i, j), maxCandyCheck(a, i+1, j)) );
                SWAP(a[i][j], a[i+1][j], char);
            }
        }
    }
    
    printf("%d\n", ans);
    
    return 0;
}
