//[boj 1107 : 리모컨](https://www.acmicpc.net/problem/1107)

#include <iostream>
#include <string>
#define ABS(X) ((X > 0) ? X : -(X))
#define MIN(X, Y) ((X>Y) ? Y : X)


/* 목적 : 선택 가능한 채널인가? + 해당 채널의 자리수는? */
int posible(int channel, bool *btn_broken) {
    if (channel == 0) {
        if (btn_broken[0]) return 0;
        else return 1;
    }
    
    int len = 0;
    
    while(channel>0) {
        if (btn_broken[channel%10]) return 0;
        channel/=10;
        len++;
    }
    
    return len;
}

/* 방법 :
 *      0~1000000까지 탐색하며 선택 가능한 숫자(채널)이라면
 *      최소값을 갱신한다.*/
int main(void) {
    int channel, n;
    bool btn_broken[10] = {0,};
    std::cin >> channel >> n;
    for (int i = n; i > 0; i--) {
        std::cin >> n;
        btn_broken[n] = true;
    }
    
    int cnt = ABS(channel-100);
    for (int i = channel; i < 1000000; i++) {
        int len = posible(i, btn_broken);
        if (len > 0) {
            cnt = MIN( cnt, i - channel + len );
            break;
        }
    }
    for (int i = channel; i >= 0; i--) {
        int len = posible(i, btn_broken);
        if (len > 0) {
            cnt = MIN( cnt, channel - i + len);
        }
    }
    std::cout << cnt << '\n';
    
    return 0;
}
