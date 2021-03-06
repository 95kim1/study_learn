//[boj 1158 : 조세퍼스 문제](https://acmicpc.net/problem/1158)
#include <iostream>
#include <vector>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n, k;
    std::cin >> n >> k;
    
    std::vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    
    std::cout << '<';
    int i = 0;
    while (n) {
        i = (i+k-1) % n;
        std::cout << v[i];
        for (int j = i; j < n-1; j++) v[j] = v[j+1];
       
        if (n>1)
            std::cout << ", ";
        else
            std::cout << ">\n";
        n--;
    }
    
    return 0;
}

