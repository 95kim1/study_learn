//[boj 2609 : 최대공약수와 최소공배수](https://www.acmicpc.net/problem/2609)


#include <iostream>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int a, b, temp;
    std::cin >> a >> b;
    int A = a, B = b;
    
    //유클리드 호제법
    while(b!=0) {
        temp = b;
        b = a%b;
        a = temp;
    }
    std::cout << a << '\n' << A/a*B << '\n';
    
    return 0;
}
