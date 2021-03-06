//[boj 1934 : 최소공배수](https://www.acmicpc.net/problem/1934)

#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, temp, T;
    std::cin >> T;
    while(T--) {
        std::cin >> a >> b;
        int A = a, B = b;
        
        //유클리드 호제법
        while(b!=0) {
            temp = b;
            b = a%b;
            a = temp;
        }
        std::cout << A/a*B << '\n';
    }
    
    return 0;
}
