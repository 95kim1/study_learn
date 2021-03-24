//[boj 10819 : 차이를 최대로](https://www.acmicpc.net/problem/10819)

//brute force
#include <iostream>
#include <algorithm>
#include <vector>
#define MAX(X,Y) ((X>Y)?X:Y)
#define ABS(X) ((X<0)?-(X):X)

/* a > b : true */
template<class T>
bool nextPermutation(std::vector<T> &v, bool (*comp)(T a, T b)=[](T a, T b)->bool{return (a>b) ? true : false;}) {
    bool last = true;
    int i, j = (int)v.size();
    for (i = (int)v.size()-1; i > 0; i--) {
        if (comp(v[i], v[i-1])) {
            last = false;
            break;
        }
    }
    
    // 654321 같은 경우 : 마지막 패턴임. ->
    if (last) {
        return !last;
    }
    
    for (j = i; j < (int)v.size(); j++) {
        if (!comp(v[j], v[i-1])) {
            break;
        }
    }
    j--;
    
    // check that "deep copy operator=" is operating well
    T temp = v[j];
    v[j] = v[i-1];
    v[i-1] = temp;

    j = (int)v.size()-1;
    while(i < j) {
        temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++; j--;
    }
    return !last;
}

// a > b : true
template<class T>
bool prevPermutation(std::vector<T> &v, bool (*comp)(T a, T b)=[](T a, T b)->bool{return (a>b) ? true : false;}) {
    bool first = true;
    int i, j = (int)v.size();
    for (i = (int)v.size()-1; i > 0; i--) {
        if (comp(v[i-1], v[i])) {
            first = false;
            break;
        }
    }
    
    if (first) {
        return !first;
    }
    
    for (j = i; j < (int)v.size(); j++) {
        if (!comp(v[i-1], v[j])) {
            break;
        }
    }
    j--;
    
    T temp = v[i-1];
    v[i-1] = v[j];
    v[j] = temp;
    
    j = (int)v.size()-1;
    while(i < j) {
        T temp = v[i];
        v[i] = v[j];
        v[j] = temp;
        i++; j--;
    }
    return !first;
}

int solve(std::vector<int> &v) {
    int ans = 0;
    for (int i = 1; i < v.size(); i++) {
        ans += ABS(v[i]-v[i-1]);
    }
    return ans;
}

/* 방법 :
 *      sort로 오름차순으로 정렬.
 *      permutation 함수로 모든 조합에 대해 문제의 식을 적용하여 최대값 갱신. */
int main(void) {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
        std::cin >> v[i];
    
    std::sort(v.begin(), v.end());
    
    int ans = 0;
    do {
        ans = MAX(ans, solve(v));
    } while(nextPermutation(v));
    
    printf("%d\n", ans);
    
    return 0;
}
