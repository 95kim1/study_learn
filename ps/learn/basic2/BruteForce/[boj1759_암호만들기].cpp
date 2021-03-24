//[boj 1759 : 암호 만들기](https://www.acmicpc.net/problem/1759)

#include <iostream>
#include <string>
#include <algorithm>

bool isAeiou(const char c) {
    switch(c) {
        case 'a':
        case 'e':
        case 'i':
        case 'o':
        case 'u':
            return true;
        default:
            return false;
    }
}

bool checkPassword(std::string &pwd) {
    int cnt_aeiou = 0, cnt_else = 0;
    for (char c : pwd) {
        if (isAeiou(c)) cnt_aeiou++;
        else cnt_else++;
        if (cnt_aeiou >= 1 && cnt_else >=2) return true;
    }
    return false;
}

//str: 사용할 문자, password: 암호, idx: 현재 선택여부 결정하고 있는 문자의 인덱스, L: 암호의 길이
void printPossiblePasswords(std::string &str, std::string password, int idx, int &L) {
    if (password.length() == L) {
        //자모 체크 후 출력
        if (checkPassword(password)) {
            std::cout  << password << '\n';
        }
        return;
    }
    
    if (idx >= str.length()) return;
    
    //선택
    printPossiblePasswords(str, password+str[idx], idx+1, L);
    //선택x
    printPossiblePasswords(str, password, idx+1, L);
        
}

/* 방법:
 *  브루트포스, 재귀, 순열
 *  문자열 중 L개 선택 (재귀함수 호출 시, 선택할지 안 할지 결정)
 *  std::sort로 정렬
 * 입력: L, C, string */
int main(void) {
    int L, C;
    std::cin >> L >> C;
    std::string str;
    for (int i = 0 ; i < C; i++) {
        char c;
        std::cin >> c;
        str+=c;
    }
    std::sort(str.begin(), str.end());
    printPossiblePasswords(str, "", 0, L);
    
    return 0;
}
