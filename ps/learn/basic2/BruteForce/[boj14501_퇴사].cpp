//[boj 14501 : 퇴사](https://www.acmicpc.net/problem/14501)

#include <iostream>
#include <vector>
#define MAX(X, Y) ((X > Y)?X:Y)
void setTable(std::vector<int> &T, std::vector<int> &P, std::vector<int> &choose, int idx, int &N, int &maxBenefit, int curBenefit) {
    if (idx >= N) {
        //max 갱신
        maxBenefit = MAX(maxBenefit, curBenefit);
        return;
    }
    
    //선택 (그만두기 전까지 끝낼 수 있다면 선택)
    if (idx+T[idx] <= N) {
        choose.push_back(idx);
        setTable(T, P, choose, idx+T[idx], N, maxBenefit, curBenefit+P[idx]);
        choose.pop_back();
    }
    //선택x
    setTable(T, P, choose, idx+1, N, maxBenefit, curBenefit);
}

/* 방법:
 *  브루트포스, 재귀, 순열(선택)
 *  recursionFunc(T, P, choose, idx, N, maxBenefit, curBenefit)
 *      T: time list, P: price list, choose: choosed list
 *      idx: current day(0:day1, 1:day2),
 *      N: max day (N : day(N+1) is D-day), maxBenefit: 최대 이익
 *      curBenefit: choose된 상담료들의 합
 * 입력: N, T, P */
int main(void) {
    int N;
    std::cin >> N;
    std::vector<int> T(N), P(N);
    std::vector<int> choose;
    for (int i = 0; i < N; i++)
        std::cin >> T[i] >> P[i];
    
    int maxBenefit = 0;
    setTable(T, P, choose, 0, N, maxBenefit, 0);
    
    printf("%d\n", maxBenefit);
    
    return 0;
}
