//[boj 9093 : 단어뒤집기](https://www.acmicpc.net/problem/9093)

#include <iostream>
#include <string>

int main(void) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int t;
    std::cin >> t;
    std::cin.ignore();
    while(t--) {
        std::string st;
        getline(std::cin, st);
        st+='\n';
        
        int l = 0;
        int s;
        while(true) {
            s = l;
            while(st[l] != ' ' && st[l] != '\n') l++;
            int e = l-1;
            while(s < e) {
                char temp = st[s];
                st[s] = st[e];
                st[e] = temp;
                s++;
                e--;
            }
            
            if (st[l] == '\n') break;
            else l++;
        }
        
        std::cout << st;
    }
    
    return 0;
}

