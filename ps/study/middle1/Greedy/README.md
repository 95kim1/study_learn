# Greedy

매 순간 최선을 선택하는 알고리즘

1. 최선에 대한 기준을 결정
2. 해당 기준을 반복

그리디 증명

1. 그리디가 아니다. → 반례 찾기
2. 그리디 이다. → 수학적 증명

<br>

### problems

1. [boj 11047 : 동전 0](https://www.acmicpc.net/prblem/11047)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj11047.cpp)
   - 기준 : 안 쓴 종류의 동전 중 가장 큰 동전 선택
   - 증명 : A[i] > A[i-k], i>k≥0 일 때, A[i] 대신 A[i-k] for some k > 0(i>k) 를 선택했다고 해보자. 이 때 A[i] = n \* A[i-k], n ≥ 1 이고 따라서 A[i-k] 선택하면 A[i]를 선택한 것보다 (n-1)개 더 사용해야한다. 즉 모순이다. 따라서 A[i]를 선택해야만 한다.

2. [boj 1931 : 회의실 배정](https://www.acmicpc.net/prblem/1931)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1931.cpp)
   - 기준 : 남은 회의 중 종료시각이 가장 빠른 것 선택

3. [boj 11399 : ATM](https://www.acmicpc.net/prblem/11399)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj11399.cpp)
   - 기준 : 가장 적게 걸리는 사람이 인출

4. [boj 1080 : 행렬](https://www.acmicpc.net/prblem/1080)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1080.cpp)
   - 기준 : 좌측 상단부터 차례로 바꿀지 말지 결정(겹치는 행렬의 개수가 1개인 칸 부터)

5. [boj 2138 : 전구와 스위치](https://www.acmicpc.net/prblem/2138)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj2138.cpp)
   - 기준 : 누를 수 있는 스위치가 1개인 칸부터
   - 이 기준을 만족하려면 0번째의 스위치를 눌렀을 때와, 안 눌렀을 때로 경우를 나눠서 이미 0번째 스위치의 동작을 결정한 후 두 갈래로 진행하면 된다.

6. [boj 1285 : 동전 뒤집기](https://www.acmicpc.net/prblem/1285)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1285.cpp)
   - 기준 : 각 열마다 flip했을 때, 안 했을 때 중 최소 선택
   - 모든 칸은 최대 2번씩 플립할 수 있다. (3이상은 의미가 없다.)
     열들의 칸들이 1번씩 플립할 수 있게 만들어 주어야 그리디 방식을 적용할 수 있다. (한 번 선택하면 더이상 그 칸을 선택할 수 없어야 하기 때문이다.)
     그러기 위해서는 모든 행들에 대해서 플립을 할지 안 할지를 결정해 주어야 한다.
     즉, 모든 행들에 대해서 플립을 할지 말지 브루트포스(dfs: 선택)을 이용하여 모든 칸을 1번씩 플립할 수 있게 만든 뒤, 각 열에 대해서 플립을 했을 때와 안 했을 때의 Tail의 개수 중 최소값을 더해준다. (브루트포스(dfs: 선택)의 각 경우마다 T의 개수를 세어서 최소값을 갱신해준다.)

7. [boj 1202 : 보석 도둑](https://www.acmicpc.net/prblem/1202)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1202.cpp)
   - 기준 :
     1. 보석 가격이 높은 것부터 차례대로 가방에 넣는다. 가방 선택은 보석 무게 보다 크거나 같은 것 중 가장 작은 것 선택.
     2. 작은 가방부터 무엇을 넣을 지 결정 (보석과 가방을 하나의 배열에 넣고 정렬한다. 가방을 발견하면 여태까지 탐색한 보석 중 제일 가치 높은 넘을 이 가방에 넣는다.)

8. [boj 2109 : 순회강연](https://www.acmicpc.net/prblem/2109)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj2109.cpp)
   - 기준 :
     1. 강연의 가치가 높은 순으로 어떤 날짜에 배치할지 선택한다.
     2. 날짜 순으로 어떤 강연을 넣을지 결정한다.

9. [boj 12738 : 가장 긴 증가하는 부분 수열 3](https://www.acmicpc.net/prblem/12738)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj12738.cpp)
   - 기준 : 새로운 배열을 만들고, 매 원소마다 이 배열에 어느 위치에 들어가는지 결정하고 갱신한다. 최종적으로 새로운 배열의 길이가 가장 긴 부분 수열의 길이다.

10. [boj 12015 : 가장 긴 증가하는 부분 수열 2](https://www.acmicpc.net/prblem/12015)
    - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj12015.cpp)
    - 기준 : 위와 동일

<br>
<br>

### 연습 문제

1. [[boj 1541 : 잃어버린 괄호]](https://www.acmicpc.net/problem/1541)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1541.cpp)
   - 기준 : 덧셈 먼저 계산 ( -(양의 최대값) = 최소값)

2. [[boj 1744 : 수 묶기]](https://www.acmicpc.net/problem/1744)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1744.cpp)
   - 기준 : 양, 음수 나눠서 각각 절대값 제일 큰 수 두개씩 곱한다.(이때 두 수를 더한 값보다 곱한 값이 절대값으로 더 커야 한다.)

3. [[boj 2875 : 대회 or 인턴]](https://www.acmicpc.net/problem/2875)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj2875.cpp)
   - 기준 : 여자:남자 = 2:1로 맞추고 여자-2,남자-1 씩 뺀다.

4. [[boj 10610 : 30]](https://www.acmicpc.net/problem/10610)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj10610.cpp)
   - 기준 : 0이 존재하고 3의 배수면 30의 배수 만들 수 있다. (내림 차순으로 정렬)

5. [[boj 1783 : 병든 나이트]](https://www.acmicpc.net/problem/1783)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1783.cpp)
   - 기준 : 위,아래로 번갈아 가며 움직인다.

6. [[boj 12970 : AB]](https://www.acmicpc.net/problem/12970)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj12970.cpp)
   - 기준 : A의 개수를 정한다. A를 배치 후에 B가 어디에 들어갈 지 결정. 가능한 최대한 뒤에 배치하여 AB 쌍을 늘린다.

7. [[boj 12904 : A와 B]](https://www.acmicpc.net/problem/12904)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj12904.cpp)
   - 기준 : 연산을 거꾸로 진행

### 도전

1. [[boj 1201 : NMK]](https://www.acmicpc.net/problem/1201)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1201.cpp)
   - 기준 : (감소수열을) 덩어리로 묶어서 m개의 덩어리를 아래와 같은 순서로 배치
   - | ... | N-k ~ N - (2k-1) | N ~ N-(k-1)|
     → | | : 한 칸에 k개의 감소하는 수열
   - | | | | ... | → m개의 칸 → 최대 길이 m인 증가 수열만 만들 수 있음

2. [[boj 2873 : 롤러코스터]](https://www.acmicpc.net/problem/2873)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj2873.cpp)
   - 기준 : R,C 중 하나라도 홀수면 방법이 정해져 있음. 둘 다 짝수라면, 1곳을 못 지나가는데, 최소 코스트의 한 칸(y,x)를 빼고 지나 간다.
   - 지나가는 방법은 시작점과 끝점을 각각 아래 위로 움직여서 (y,x)를 포함한 2행 짜리로 만들고, 각각 오른쪽, 왼쪽으로 움직여서 (y,x)를 포함한 2행 2열 짜리로 만든다. 최종적으로 2행 2열에 대해서 작업을 해준다.

3. [[boj 12919 : A와 B 2]](https://www.acmicpc.net/problem/12919)

   - [(소스 코드)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj12919.cpp)
   - 기준 : 연산 2개를 T에서 거꾸로 실행하여(하나씩 무낮를 제거하여) S를 만든다.
   - BX....YA는 경우의 수가 2가지여서 O(2^N)인 거 같지만 실상은 그렇지 않다.
     1. BX...Y의 경우 Y가 B면 경우의 수가 1이고, A면 경우의 수가 2다.
     2. AY...X의 경우 X가 B면 경우의 수가 0이고, A면 경우의 수가 1이다.
     3. 즉 길이 별로 경우의 수가 2인 것은 1번만 나온다.
     4. 따라서 최악의 경우 2 + 3 + 4 + 5 + .... + N+1 ⇒ O(N^2)다. 문자열 연산이 O(N)이므로 최종적으로 O(N^3)이다.
