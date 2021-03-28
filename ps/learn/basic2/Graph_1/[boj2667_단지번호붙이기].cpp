//[boj 2667 : 단지번호붙이기](https://www.acmicpc.net/problem/2667)

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
int dr[4] = {-1, 0, 1, 0}, dc[4] = {0, 1, 0, -1};
//아직 단지를 분리하지 않은 아파트가 있으면 1->2로 바꾸어 탐색 완료 의미 부여
int dfs(std::string *cpx, int &n, int r, int c)
{
    cpx[r][c] = '2';
    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        int R = r + dr[i];
        int C = c + dc[i];
        if (!(0 <= R && R < n && 0 <= C && C < n) || cpx[R][C] != '1')
            continue;
        cnt += dfs(cpx, n, R, C);
    }
    return cnt;
}

void separateComplex(std::string *cpx, int &n)
{
    std::vector<int> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (cpx[i][j] != '1')
                continue;
            v.push_back(dfs(cpx, n, i, j)); //단지 내에 아파트 개수
        }
    }

    printf("%d\n", (int)v.size()); //v.size()==단지의 개수
    std::sort(v.begin(), v.end()); //단지내 아파트 개수를 오름차순으로 정리
    for (int i = 0; i < (int)v.size(); i++)
    {
        printf("%d\n", v[i]);
    }
}

/* 방법:
 *  그래프의 연결요소 찾기
 *  문제에서 2차원 배열을 쓰므로 인접행렬을 사용한다. */
int main(void)
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string *apt_complex = new std::string[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> apt_complex[i];
    }

    separateComplex(apt_complex, n);

    delete[] apt_complex;
    return 0;
}
