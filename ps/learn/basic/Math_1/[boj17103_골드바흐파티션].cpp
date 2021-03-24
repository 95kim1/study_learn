//[boj 17103 : 골드바흐 파티션](https://www.acmicpc.net/problem/17103)

#include <iostream>
#include <vector>
int a[1000001];
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    
    std::vector<int> v;
    a[0] = a[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (a[i]) continue;
        v.push_back(i);
        for (int j = i+i; j <= 1000000; j+=i) {
            a[j] = 1;
        }
    }
    
    while(t--) {
        int n, cnt = 0, temp;
        std::cin >> n;
        temp = n/2;
        for (int i = 0; i < (int)v.size() && v[i] <= temp; i++) {
            if (!a[n-v[i]])
                cnt++;
        }
        
        std::cout << cnt << '\n';
    }
    
    return 0;
}
