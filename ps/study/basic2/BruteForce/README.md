# 브루트포스

#### 목록
+ 설명
+ problems
  - just doing all things
  - doing with jump
  - recursion N and M
  - Permutation
  - recuresion (choice & backtracking)
  - bitmask
--------------
### 설명
1. 문제의 가능한 경우의 수는?
    1. 손으로 직접 구해보기
2. 가능한 모든 방법을 만들어 보기
    1. 빠짐 없이 모든 경우
    2. 그냥 다 해보기, for, 순열, 재귀, 비트마스크 -
3. 각각의 방법을 이용해 답을 구한다.
    1. 문제에 나와있는 대로 답 계산

### problems

#### 1. Just doing all things

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
| [boj 2309 : 일곱 난쟁이](https://www.acmicpc.net/problem/2309)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj2309_%EC%9D%BC%EA%B3%B1%EB%82%9C%EC%9F%81%EC%9D%B4%5D.cpp) |9C7 -> 9! / 2! / 7! = 36가지|
| [boj 3085 : 사탕게임](https://www.acmicpc.net/problem/3085)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj3085_%EC%82%AC%ED%83%95%EA%B2%8C%EC%9E%84%5D.cpp) ||
| [boj 1476 : 날짜 계산](https://www.acmicpc.net/problem/1476)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj1476_%EB%82%A0%EC%A7%9C%EA%B3%84%EC%82%B0%5D.cpp)||
| [boj 1107 : 리모컨](https://www.acmicpc.net/problem/1107) |[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj1107_%EB%A6%AC%EB%AA%A8%EC%BB%A8%5D.cpp) | 최소값 : 의미없는 것, 중복되는 것이 있으면 안 됨.|
| [boj 14500 : 테트로미노](https://www.acmicpc.net/problem/14500)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj14500_%ED%85%8C%ED%8A%B8%EB%A1%9C%EB%AF%B8%EB%85%B8%5D.cpp)||

<br>

#### 2. Doing with jump

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
| [boj 6064 : 카잉 달력](https://www.acmicpc.net/problem/6064)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj6064_%EC%B9%B4%EC%9E%89%EB%8B%AC%EB%A0%A5%5D.cpp)|나머지 연산|
| [boj 1748 : 수 이어 쓰기 1](https://www.acmicpc.net/problem/1748)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj1748_%EC%88%98%EC%9D%B4%EC%96%B4%EC%93%B0%EA%B8%B01%5D.cpp)|묶어서 처리|

<br>

#### 3. Recursion N and M (basics)

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
| [boj 15649 : N과M (1)](https://www.acmicpc.net/problem/15649)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15649_N%EA%B3%BCM(1)%5D.cpp)| |
| [boj 15650 : N과M (2)](https://www.acmicpc.net/problem/15650)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15650_N%EA%B3%BCM(2)%5D.cpp)| |
| [boj 15651 : N과M (3)](https://www.acmicpc.net/problem/15651)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15651_N%EA%B3%BCM(3)%5D.cpp)| |
| [boj 15652 : N과M (4)](https://www.acmicpc.net/problem/15652)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15652_N%EA%B3%BCM(4)%5D.cpp)| |
| [boj 15654 : N과M (5)](https://www.acmicpc.net/problem/15654)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15654_N%EA%B3%BCM(5)%5D.cpp)| |
| [boj 15655 : N과M (6)](https://www.acmicpc.net/problem/15655)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15655_N%EA%B3%BCM(6)%5D.cpp)| |
| [boj 15656 : N과M (7)](https://www.acmicpc.net/problem/15656)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15656_N%EA%B3%BCM(7)%5D.cpp)| |
| [boj 15657 : N과M (8)](https://www.acmicpc.net/problem/15657)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15657_N%EA%B3%BCM(8)%5D.cpp)| |
| [boj 15663 : N과M (9)](https://www.acmicpc.net/problem/15663)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15663_N%EA%B3%BCM(9)%5D.cpp)| |
| [boj 15664 : N과M (10)](https://www.acmicpc.net/problem/15664)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15664_N%EA%B3%BCM(10)%5D.cpp)| |
| [boj 15665 : N과M (11)](https://www.acmicpc.net/problem/15665)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15665_N%EA%B3%BCM(11)%5D.cpp)| |
| [boj 15666 : N과M (12)](https://www.acmicpc.net/problem/15666)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj15666_N%EA%B3%BCM(12)%5D.cpp)| |

<br>

#### 4. Permutation

**다음 순열 구하기**

    1. 다음 수열은 현재 수열의 뒷 부분에서 증가하다가 처음으로 감소하는 인덱스가 바뀌어서 탄생한다.
        1247653 → 124, 7653 →  '4' will be swaped 
        
    2. 해당(바뀌는) 인덱스를 idx라 할 때, idx+1부터 탐색하여 idx의 값보다 큰 수들 중 가장 작은 값과 바꾼다.
      (-> 퍼뮤테이션을 오름차순으로 한다고 할 때, 다음 수열은 현재 수열보다 오름차순으로 한 단계 앞선 수열이기 때문)
        124, 7653 → 124, 76 '5' 3 → 125, 7643 : '4', '5' swaped each other
        
    3. idx+1부터 끝까지 순서를 뒤집는다.
        125, 7643 → 125, 3467 →1253467

이전 순열 (~~ 다음 순열 구하기)
  
    1. 처음으로 증가하는 인덱스
    2. 작은 값들 중 가장 큰 값과 바꿈
    3. 순서 뒤집기는 동일

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
| [boj 10972 : 다음 순열](https://www.acmicpc.net/problem/10972)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj10972_%EB%8B%A4%EC%9D%8C%EC%88%9C%EC%97%B4%5D.cpp)||
| [boj 10973 : 이전 순열](https://www.acmicpc.net/problem/10973)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj10973_%EC%9D%B4%EC%A0%84%EC%88%9C%EC%97%B4%5D.cpp)||
| [boj 10974 : 모든 순열](https://www.acmicpc.net/problem/10974)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj10974_%EB%AA%A8%EB%93%A0%EC%88%9C%EC%97%B4%5D.cpp)||
| [boj 10819 : 차이를 최대로](https://www.acmicpc.net/problem/10819)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj10819_%EC%B0%A8%EC%9D%B4%EB%A5%BC%EC%B5%9C%EB%8C%80%EB%A1%9C%5D.cpp) [(소스2)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj10819_%EC%B0%A8%EC%9D%B4%EB%A5%BC%EC%B5%9C%EB%8C%80%EB%A1%9C%5D_2.cpp)||
| [boj 10971 : 외판원 순회 2](https://www.acmicpc.net/problem/10971)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj10971_%EC%99%B8%ED%8C%90%EC%9B%90%EC%88%9C%ED%9A%8C2%5D.cpp)||
| [boj 6603 : 로또](https://www.acmicpc.net/problem/6603)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj6603_%EB%A1%9C%EB%98%90%5D.cpp)||

<br>

#### 5. Recursion (choice & backtracking)

(base)

    1. 정답을 찾은 경우 처리
    2. 불가능한 경우 처리
    3. 다음 경우 호출 처리

(backtracking)

    1. 정답을 찾은 경우 처리
    2. 불가능한 경우 처리 + 다음 경우 호출 처리

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
| [boj 9095 : 1,2,3 더하기](https://www.acmicpc.net/problem/9095) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj9095_1%2C2%2C3%EB%8D%94%ED%95%98%EA%B8%B0%5D.cpp) |선택여부 정하기|
| [boj 1759 : 암호 만들기](https://www.acmicpc.net/problem/1759) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj1759_%EC%95%94%ED%98%B8%EB%A7%8C%EB%93%A4%EA%B8%B0%5D.cpp) |선택여부 정하기 (순열) -> 2^c|
| [boj 14501 : 퇴사](https://www.acmicpc.net/problem/14501) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj14501_%ED%87%B4%EC%82%AC%5D.cpp) |선택여부 정하기 (순열) -> 2^N|
| [boj 14889 : 스타트와 링크](https://www.acmicpc.net/problem/14889) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj14889_%EC%8A%A4%ED%83%80%ED%8A%B8%EC%99%80%EB%A7%81%ED%81%AC%5D.cpp) |선택여부 정하기|
| [boj 2529 : 부등호](https://www.acmicpc.net/problem/2529) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj2529_%EB%B6%80%EB%93%B1%ED%98%B8%5D.cpp) |백트랙킹|
| [boj 1248 : 맞춰봐](https://www.acmicpc.net/problem/1248) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj1248_%EB%A7%9E%EC%B6%B0%EB%B4%90%5D.cpp) |백트랙킹, 이론상 시간 초과, 실제론 통과|

<br>

#### 6. Bitmask

**비트 연산 (bitmask)**

    1. 검사: A & (1<<i) == A의 i번째 비트가 1인지 아닌지 검사
    2. 추가: A |= (1<<i) → A의 i번째 비트에 1 추가
    3. 제거: A &= ~(1<<i) → A의 i번째 비트에 1 제거
    4. 토글: A ^= (1<<i) → A의 i번째 비트를 반대 비트로 변경 
      
    (전체 집합 : (1<<N)-1, 공집합 : 0)
    
|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:-:|
| [boj 1182 : 부분집합의 합](https://www.acmicpc.net/problem/1182) |[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj1182_%EB%B6%80%EB%B6%84%EC%A7%91%ED%95%A9%EC%9D%98%ED%95%A9%5D.cpp)||
| [boj 14889 : 스타트와 링크](https://www.acmicpc.net/problem/14889) |[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj14889_%EC%8A%A4%ED%83%80%ED%8A%B8%EC%99%80%EB%A7%81%ED%81%AC%5D_2.cpp)||
| [boj 14391 : 종이 조각](https://www.acmicpc.net/problem/14391) |[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BruteForce/%5Bboj14391_%EC%A2%85%EC%9D%B4%EC%A1%B0%EA%B0%81%5D.cpp)||
