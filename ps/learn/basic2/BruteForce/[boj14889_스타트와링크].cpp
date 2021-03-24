//[boj 14889 : 스타트와 링크](https://www.acmicpc.net/problem/14889)

#include <iostream>
#include <vector>
#define MIN(X,Y) (((X)>(Y))?(Y):(X))
#define ABS(X) (((X)<0)?-(X):(X))

void ability(std::vector<std::vector<int> > &S, std::vector<int> team1, int &sum1, std::vector<int> team2, int &sum2) {
    sum1 = 0; sum2 = 0;
    for (int i = 0; i < (int)team1.size(); i++) {
        for (int j = 0; j < (int)team1.size(); j++) {
            if (i==j) continue;
            sum1 += S[team1[i]][team1[j]];
            sum2 += S[team2[i]][team2[j]];
        }
    }
}

int findMinDiff(std::vector<std::vector<int> > &S, std::vector<int> team1, std::vector<int> team2, int idx, int &N) {
    //1. 정답 찾은 경우
    if (idx==N) {
        int sum1, sum2;
        ability(S, team1, sum1, team2, sum2);
        return ABS(sum1-sum2);
    }
    
    int ans = 40000;
    //2. 불가능한 경우 처리 + 다음 호출
    //team1 선택
    if (team1.size() < N/2) {
        team1.push_back(idx);
        int t1 = findMinDiff(S, team1, team2, idx+1, N);
        ans = MIN(ans, t1);
        team1.pop_back();
    }
    
    //team2선택
    if (team2.size() < N/2) {
        team2.push_back(idx);
        int t2 = findMinDiff(S, team1, team2, idx+1, N);
        ans = MIN(ans, t2);
        team2.pop_back();
    }
    
    return ans;
}

/* 방법:
 *  브루트포스, 백트랙킹 : 재귀 순열 선택(team1 or team2), team선택시 N/2 넘어가면 백트랙킹
 * 입력: N, S*/
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int N;
    std::cin >> N;
    std::vector<std::vector<int> > S(N);
    std::vector<int> team1, team2;
    
    for (int i = 0; i < N; i++) {
        for (int temp, j = 0; j < N; j++) {
            std::cin >> temp;
            S[i].push_back(temp);
        }
    }
    
    printf("%d\n",findMinDiff(S, team1, team2, 0, N));
    
    
    return 0;
}
