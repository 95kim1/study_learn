//[boj 2309 : 일곱 난쟁이](https://www.acmicpc.net/problem/2309)

#include <iostream>
#include <algorithm>
/* 방법 :
 *      9난쟁이의 키의 합을 구한 뒤,
 *      2명의 난쟁이를 뺐을 때 키의 합이 100이 되는 나머지 난쟁이 출력 */
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int *a = new int[9], sum = 0;
    for (int i = 0; i < 9; i++) {
        std::cin >> a[i];
        sum += a[i];
    }
    std::sort(a, a+9, [](int a, int b)->bool{return (a>b) ? false : true;});
    // i, j : 9명의 난쟁이에서 제외 되는 2명의 난쟁이의 키가 담긴 배열 인덱스
    for (int i = 0; i < 9; i++) {
        for (int j = i+1; j < 9; j++) {
            if (sum - a[i] - a[j] != 100) continue;
            for (int k = 0; k < 9; k++) {
                if (k ==i || k == j) continue;
                printf("%d\n", a[k]);
            }
            delete[]a;
            return 0;
        }
    }
    return 0;
}
