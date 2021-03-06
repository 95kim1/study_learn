//[boj 10808 : 알파벳 개수](https://www.acmicpc.net/problem/10808)

#include <iostream>
#include <string>
using namespace std;
int alpha[26];

int main(void) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string str;
    cin >> str;
    
    for (char c : str) {
        alpha[c-'a']++;
    }
    
    cout << alpha[0];
    for (int i = 1; i < 26; i++) {
        cout << ' ' << alpha[i];
    }
    cout << '\n';
    
    return 0;
}

