- 2개 이상의 작은 부분 문제로 나누기(분할)
- 나눈 문제를 다시 합쳐서 정답을 구하기(정복)
- DP와의 차이점:
    1. 작은 문제가 중복x  
    (작은 문제를 한 번씩만 풀어 주면 된다.
    2. 보통 균등하게 나눈다. 
    (DP는 편향된 경우가 보통)

### 탐색과 정렬

1. 이분 탐색 : O(logN)
    - [[boj 10815 : 숫자 카드]](https://www.acmicpc.net/problem/10815) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj10815.cpp)
2. 상한과 하한
    - 상한: 큰 수 중 첫 번째 수
    - 하한: 크거나 같은 수 중 첫번째 수
    - 상한 idx - 하한 idx = 그 수의 개수
    - [[boj 10816 : 숫자 카드 2]](https://www.acmicpc.net/problem/10816) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj10816.cpp)
3. 병합 정렬
    - N → N/2 , N/2 → ... → 1, 1, 1, 1, ... , 1
    - 1, 1, 1, 1, ..., 1 → ... → N/2, N/2 → N
    - 분할 후 정렬하면서 합친다.
    - [[boj 11728 : 배열 합치기]](https://www.acmicpc.net/problem/11728) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj11728.cpp)
4. 퀵 정렬
    - 평균적인 상황에서 최고의 성능
    - pivot을 골라서 이를 기준으로 양옆으로 작은 거 큰 거를 몰아 넣은 후 pivot을 기준으로 분할 한다.
    - 병합 정렬보다 빠른 이유:
        1. locality: 하나의 배열만 사용 → page가 잘 안 바뀜 (page cache hit 증가)
        2. 꼬리 재귀 최적화: 재귀함수 뒤에 어떠한 연산도 없다면 최적화가 이루어진다. 물론 비재귀면 효용성이 없다.
    - 추가로 비재귀/재귀를 구현했을 때, 1억,...,3,2,1 수열을 오름차순으로 정렬하는 데 있어서 비재귀: 29.98초, 재귀: 17.76초가 걸렸다.
    - quick select: k번째 작은 수 찾기
        - partitioning을 한 후 pivot과 k를 비교하여 같으면 그대로 return 작으면 pivot의 왼쪽에 대해서, 크면 pivot의 오른쪽에 대해서 진행한다.
        - O(N)이다.(  N + N/2 + N/4 + ... + N/(2^n) = N (1/(1-1/2)) = 2 N as n→infinity 물론 이상적인 경우에 해당, 평균적으로 이와 비슷한 양상을 띈다.)

### 연습문제

1. [[boj 1780 : 종이의 개수]](https://www.acmicpc.net/problem/1780) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj1780.cpp)
2. [[boj 11729 : 하노이 탑 이동 순서]](https://www.acmicpc.net/problem/11729) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj11729.cpp)
3. [[boj 2263 : 트리의 순회]](https://www.acmicpc.net/problem/2263) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj2263.cpp)
4. [[boj 1074 : Z]](https://www.acmicpc.net/problem/1074) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj1074.cpp)
5. [[boj 1891 : 사분면]](https://www.acmicpc.net/problem/1891) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj1891.cpp)
6. [[boj 2447 : 별 찍기-10]](https://www.acmicpc.net/problem/2447) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj2447.cpp)
7. [[boj 2448 : 별 찍기-11]](https://www.acmicpc.net/problem/2448) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj2448.cpp)
8. [[boj 1517 : 버블 소트]](https://www.acmicpc.net/problem/1517) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj1517.cpp)

### 도전문제

1. [[boj 1933 : 스카이라인]](https://www.acmicpc.net/problem/1933) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj1933.cpp)

    분할정복,  합칠 때 경우 나누기가 까다로움 (추상화를 잘 시켜야 한다.)

2. [[boj 2261 : 가장 가까운 두 점]](https://www.acmicpc.net/problem/2261) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj2261.cpp)

    분할정복,  합칠 때 중간 케이스(최소거리)의 조건을 잘 따져보면 O(n)이다. (정렬하는 거 제외하고 O(n).)

## 정렬

구현되어 있는 것 사용하자.

stable sort : 같은 데이터면 입력 순서에 따라 정렬

### 정렬 문제

1. [[boj 2751 : 수 정렬하기2]](https://www.acmicpc.net/problem/2751) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj2751.cpp)
2. [[boj 11650 : 좌표 정렬하기]](https://www.acmicpc.net/problem/11650) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj11650.cpp)
3. [[boj 11651 : 좌표 정렬하기2]](https://www.acmicpc.net/problem/11651) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj11651.cpp)
4. [[boj 10814: 나이순 정렬]](https://www.acmicpc.net/problem/10814) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj10814.cpp)

    stable sorting

5. [[boj 10825 : 국영수]](https://www.acmicpc.net/problem/10825) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj10825.cpp)
6. [[boj 10989 : 수 정렬하기3]](https://www.acmicpc.net/problem/10989) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj10989.cpp)

    counting sorting

### 정렬 응용 문제

1. [[boj 11652 : 카드]](https://www.acmicpc.net/problem/11652) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj11652.cpp)
2. [[boj 1377 : 버블 소트]](https://www.acmicpc.net/problem/1377) / [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/middle1/DivideConquer/boj1377.cpp)

## 이분탐색

이용법:

1. 이분 탐색으로 정답 찾기
    1. x가 가능한지 알아내기
        - 예) A에서 B까지 x라는 시간으로 이동할 수 있나? → yes/no 문제
        - 최적해 문제와 대응된다.
    2. 다음 x 구하기 ... 1,2를 반복해서 답 구하기
    - 가능한 정답의 최소, 최대값을 알고 있어야 한다.
        - 최소 중간 최대  : 중간 검색 → 최소~중간 or 중간~최대
    - **1 최소, 2 최대, 3 중간값 조건 체크, 4 조건 맞을 때 중간보다 크게? or 작게?**
    - **보통 최대값의 최소값 혹은 최소값의 최대값 구하기 문제를 풀 때 사용한다. 혹은 Yes/No가 필요한 경우 사용한다.**

### 기본문제

1. [boj 1790 : 수 이어 쓰기2]

    k번째 수는 어느 n에 속하는가 (이분 탐색)

2. [boj 1654 : 랜선 자르기]

    최소, 최대: 랜선 길이

3. [boj 2805 : 나무 자르기]
4. [boj 2110 : 공유기 설치]
5. [boj 1939 : 중량제한]
6. [boj 2022 : 사다리]

### 연습문제

1. [boj 2343 : 기타 레슨]
2. [boj

## 삼분탐색

대부분 실수에서 사용한다.

정답이 커지다가 작아지는 경우 혹은 작아지다가 커지는 경우 구할 수 있다. (극대 극소)

### 문제

1. [boj 11664 : 선분과 점]