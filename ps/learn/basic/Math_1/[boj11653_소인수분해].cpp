//[boj 11653 : 소인수분해](https://www.acmicpc.net/problem/11653)

#include <iostream>
#include <vector>
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    if (n==1) return 0;
    
    std::vector<int> v;
    for (int i = 2; i*i <= n; i++) {
        while(n%i==0) {
            v.push_back(i);
            n/=i;
        }
    }
    
    if (n!=1) {
        v.push_back(n);
    }
    
    for (int i = 0; i < (int)v.size(); i++) {
        std::cout << v[i] << '\n';
    }
    
    return 0;
}
