//[boj 1406 : 에디터](https://www.acmicpc.net/problem/1406)

#include <iostream>
#include <string>

int main(void){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    std::string sl, sr;
    
    std::cin >> sl;

    int n;
    std::cin >> n;
    
    while(n--) {
        char order;
        std::cin >> order;
        switch(order) {
            case 'L':
                if (!sl.empty()) {
                    sr.push_back(sl.back());
                    sl.pop_back();
                }
                break;
            case 'D':
                if (!sr.empty()) {
                    sl.push_back(sr.back());
                    sr.pop_back();
                }
                break;
            case 'B':
                if (!sl.empty()) {
                    sl.pop_back();
                }
                break;
            case 'P':
                char c;
                std::cin >> c;
                sl.push_back(c);
                break;
        }
    }
    
    int s = 0, e = (int)sr.length()-1;
    while(s < e) {
        sr[s] = sr[s] ^ sr[e];
        sr[e] = sr[s] ^ sr[e];
        sr[s] = sr[s] ^ sr[e];
        s++; e--;
    }
    sl += sr;
    sl += '\n';
    std::cout << sl;
    
    return 0;
}
