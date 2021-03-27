//[boj 14889 : 스타트와 링크](https://www.acmicpc.net/problem/14889)

#include <iostream>
#define ABS(X) ((X<0)?-(X):X)
#define MIN(X,Y) ((X<Y)?X:Y)

/* 방법:
 *  비트마스크 이용 (bit 1 : team1, bit 0: team2)*/
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, **s;
    std::cin >> n;
    s = new int*[n];
    for (int i = 0; i < n; i++) {
        s[i] = new int[n];
        for (int j = 0; j < n; j++) {
            std::cin >> s[i][j];
        }
    }
    
    int *team1_ary = new int[n/2];
    int *team2_ary = new int[n/2];
    int minDiff = 40000;
    for (int i = 0; i < (1<<n); i++) {
        int team1_idx = 0, team2_idx = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1<<j) && team1_idx < n/2) {
                team1_ary[team1_idx++] = j;
            }
            else if (!(i&(1<<j)) && team2_idx < n/2){
                team2_ary[team2_idx++] = j;
            }
        }
        if (team1_idx != n/2 || team2_idx != n/2) {
            continue;
        }
        
        int team1 = 0, team2 = 0;
        for (int t_i = 0; t_i < n/2 - 1; t_i++) {
            for (int t_j = t_i+1; t_j < n/2; t_j++) {
                team1 += s[team1_ary[t_i]][team1_ary[t_j]]+s[team1_ary[t_j]][team1_ary[t_i]];
                team2 += s[team2_ary[t_i]][team2_ary[t_j]]+s[team2_ary[t_j]][team2_ary[t_i]];
            }
        }
        minDiff = MIN(minDiff, ABS(team1-team2));
    }
    
    printf("%d\n", minDiff);
    
    for (int i = 0; i < n; i++) {
        delete[] s[i];
    }
    delete[]s;
    delete[]team1_ary;
    delete[]team2_ary;
    return 0;
}
