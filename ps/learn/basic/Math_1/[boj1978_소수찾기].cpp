//[boj 1978 : 소수 찾기](https://www.acmicpc.net/problem/1978)

#include <iostream>
int a[1001];

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    //에라스토테네스의 
    a[0] = a[1] = 1;
    for (int i = 2; i <= 1000; i++) {
        if (a[i]) continue;
        for (int j = i+i; j <= 1000; j+=i)
            a[j] = 1;
    }
    
    int n, cnt = 0, temp;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> temp;
        if (!a[temp]) cnt++;
    }
    
    std::cout << cnt << '\n';
    
    return 0;
}
