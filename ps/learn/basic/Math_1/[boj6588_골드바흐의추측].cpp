//[boj 6588 : 골드바흐의 추측](https://www.acmicpc.net/problem/6588)

#include <iostream>
#include <vector>
int a[1000001];
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::vector<int> v;
    
    //에라스토테네스의 체
    a[0] = a[1] = 1;
    for (int i = 2; i <= 1000000; i++) {
        if (a[i]) continue;
        v.push_back(i); //소수만 따로 
        for (int j = i+i; j <= 1000000; j+=i)
            a[j] = 1;
    }
    
    int n;
    while(true) {
        std::cin >> n;
        if (n==0) break;
        
        for (int i = 0; i < (int)v.size() && v[i] < n; i++) {
            if (!a[n-v[i]]) {
                std::cout << n << " = " << v[i] << " + " << n-v[i] << '\n';
                break;
            }
        }
    }
    
    return 0;
}
