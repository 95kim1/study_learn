//[boj 1182 : 부분집합의 합](https://www.acmicpc.net/problem/1182)

#include <iostream>

int go(int *a, int &bitmask, int depth, int &n, int &s, int b) {
    if (depth == n) {
        int bit = 1, sum = 0;
        int choose_cnt = 0; //공집합인 경우 제거
        for (int i = 0; i < n; i++) {
            if (bitmask & bit) {
                sum += a[i];
                choose_cnt++;
            }
            bit = bit << 1;
        }
        if (sum==s && choose_cnt>0) return 1;
        return 0;
    }
    
    int cnt = 0;
    //배열의 해당 인덱스(depth) 선택
    bitmask = bitmask | b;
    cnt += go(a, bitmask, depth+1, n, s, b<<1);
    //배열의 해당 인덱스(depth) 선택x
    bitmask = bitmask & ~b;
    cnt += go(a, bitmask, depth+1, n, s, b<<1);
    
    return cnt;
}

/* 방법:
 *  재귀함수 이용.
 *  정수 배열의 인덱스의 선택 여부를 정수하나에 비트마스크를 통해 저장한다.
 *  배열의 개수만큼 선택여부를 결정하면 저장된 인덱스를 더해서 원하는 값과 비교 후 개수를 1 증가.*/
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, s;
    std::cin >> n >> s;
    int *a = new int[n];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    
    int bitmask = 0; //공집합
    printf("%d\n", go(a, bitmask, 0, n, s, 1));
    
    delete[]a;
    return 0;
}
