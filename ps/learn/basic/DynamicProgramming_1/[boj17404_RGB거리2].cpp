//[boj 17404 : RGB 거리 2](https://acmicpc.net/problem/17404)

#include <iostream>
#define INFINITY_ 1000001

int findMin(int a, int b) { return (a>b) ? b : a; };

int findMinCost(int **rgb, int n, int first) {
    int **dp, minNum;
    dp = new int*[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[n];
    
    dp[0][first] = rgb[0][first];
    
    //note: always n >= 2
    dp[1][first] = INFINITY_;
    dp[1][(first+1)%3] = rgb[1][(first+1)%3] + dp[0][first];
    dp[1][(first+2)%3] = rgb[1][(first+2)%3] + dp[0][first];
    
    for (int i = 2; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            dp[i][j] = rgb[i][j] + findMin(dp[i-1][(j+1)%3], dp[i-1][(j+2)%3]);
        }
    }
    
    minNum = INFINITY_;
    if (first!=0 && dp[n-1][0] < minNum) minNum = dp[n-1][0];
    if (first!=1 && dp[n-1][1] < minNum) minNum = dp[n-1][1];
    if (first!=2 && dp[n-1][2] < minNum) minNum = dp[n-1][2];
    
    for (int i = 0; i < n; i++)
        delete[] dp[i];
    delete[] dp;
    
    return minNum;
}

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int **rgb_house;
    int n;
    std::cin >> n;
    
    rgb_house = new int*[n];
    for (int i = 0; i < n; i++) {
        rgb_house[i] = new int[3];
        for (int j = 0; j < 3; j++)
            std::cin >> rgb_house[i][j];
    }
    
    int minNum = INFINITY_;
    for (int i = 0; i < 3; i++) {
        minNum = findMin(minNum, findMinCost(rgb_house, n, i));
    }
    
    std::cout << minNum << '\n';
    
    for (int i = 0; i < n; i++) {
        delete[] rgb_house[i];
    }
    delete[] rgb_house;
    
    return 0;
}
