//[boj 2745 : 진법 변환](https://www.acmicpc.net/problem/2745)

#include <iostream>
#include <vector>
#include <string>
int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string str;
    int n = 0, b, temp;
    std::cin >> str >> b;
    
    int s = 0, e = (int)str.length()-1;
    while(s < e) {
        temp = str[s];
        str[s++] = str[e];
        str[e--] = temp;
    }
    
    temp = 1;
    for (char c : str) {
        if ('A' <= c && c <= 'Z') {
            n += (c-55)*temp;
        }
        else {
            n += (c-'0')*temp;
        }
        temp*=b;
    }
    
    std::cout << n << '\n';
    
    return 0;
}
