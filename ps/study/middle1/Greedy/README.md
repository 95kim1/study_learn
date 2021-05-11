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
    - 증명 : A[i] > A[i-k], i>k≥0 일 때, A[i] 대신 A[i-k] for some k > 0(i>k) 를 선택했다고 해보자. 이 때 A[i] = n * A[i-k], n ≥ 1 이고 따라서 A[i-k] 선택하면 A[i]를 선택한 것보다 (n-1)개 더 사용해야한다. 즉 모순이다. 따라서 A[i]를 선택해야만 한다.

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

### 연습문제

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:-:|
|[[boj 1541 : 잃어버린 괄호]](https://www.acmicpc.net/problem/1541)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1541.cpp)||
|[[boj 1744 : 수 묶기]](https://www.acmicpc.net/problem/1744)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1744.cpp)||
|[[boj 2875 : 대회 or 인턴]](https://www.acmicpc.net/problem/2875)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj2875.cpp)||
|[[boj 10610 : 30]](https://www.acmicpc.net/problem/10610)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj10610.cpp)||
|[[boj 1783 : 병든 나이트]](https://www.acmicpc.net/problem/1783)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj1783.cpp)||
|[[boj 12970 : AB]](https://www.acmicpc.net/problem/12970)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj12970.cpp)||
|[[boj 12904 : A와 B]](https://www.acmicpc.net/problem/12904)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/Greedy/boj12904.cpp)||