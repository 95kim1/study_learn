//[boj 10819 : 차이를 최대로](https://www.acmicpc.net/problem/10819)

//greedy
#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#define ABS(X) ((X<0)?-(X):X)

/* 방법 :
 *      sort로 오름차순으로 정렬.
 *      그리디 알고리즘으로, 처음에 가장 큰 수를 처음에 넣고,
 *      가장 작은 수를 맨 앞에, 그 다음 작은 수를 맨 뒤에,
 *      가장 큰 수를 맨 앞에, 그 다음 작은 수를 맨 뒤에 넣는 것을 반복한다.
 *      단, 마지막 수는 앞과 뒤 중 어떤 곳에 넣어야 큰 지 비교하여 넣는다.
 *      만들어진 새로운 배열에 문제에 나온 식을 대입하여 답을 구한다. */
int main(void) {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    std::deque<int> dq;
    for (int i = 0; i < n; i++)
        std::cin >> v[i];

    std::sort(v.begin(), v.end());

    int min_i = 0, max_i = (int)v.size()-1;
    dq.push_back(v[max_i--]);
    while (min_i < max_i) {
        dq.push_front(v[min_i++]);
        if (min_i < max_i)
            dq.push_back(v[min_i++]);
        if (min_i < max_i)
            dq.push_front(v[max_i--]);
        if (min_i < max_i)
            dq.push_back(v[max_i--]);
    }
    if (min_i == max_i) {
        if (ABS(dq.front()-v[min_i]) < ABS(dq.back()-v[min_i])) {
            dq.push_back(v[min_i]);
        }
        else
            dq.push_front(v[min_i]);
    }

    int ans = 0;
    for (int i = 1; i < (int)dq.size(); i++) {
        ans += ABS(dq[i]-dq[i-1]);
    }
    printf("%d\n", ans);

    return 0;
}
