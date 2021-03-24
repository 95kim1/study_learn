알고리즘 기초1
===========

ㅁ 알고리즘 시작
------------

### - 시간복잡도

  Big-O : 최악의 경우 시간복잡도<br>
  
  보통 1억 -> 1초 미만 (실제로 5억 정도가 1초)<br>
  => 예상되는 제한을 정해두고 알고리즘을 선택하자.
  
<table>
  <caption>시간복잡도 별 1초 걸리는 대략적 입력 크기</caption>
  <tr>
    <th>Big-O</th>
    <th>크기 (N)</th>
  </tr>
  <tr>
    <td>O(N)</td>	
    <td>1억</td>
  </tr>
  <tr>
    <td>O(N logN)</td>	
    <td>5백만</td>
  </tr>
  <tr>
    <td>O(N^2)</td>
    <td>10000</td>
  </tr>
  <tr>
    <td>O(N^3)</td>	
    <td>500</td>
  </tr>
  <tr>
    <td>O(2^N)</td>	
    <td>20</td>
  </tr>
  <tr>
    <td>O(N!)</td>
    <td>10</td>
  </tr>
</table>
<br>

### - 메모리

  보통 배열과 같은 data의 논리적 크기를 따짐.<br>
  보통 시간복잡도를 잘 맞추면 크기도 잘 맞춰짐.
<table>
  <caption>배열 크기별 실제 용량 + O(N)일 때 시간</caption>
  <tr> 
    <th>배열 크기</th>	
    <th>대략적 용량(실제 용량)</th>	
    <th>O(N)일 때 시간</th> 
  </tr>
  <tr> 
    <td>int a[10,000]</td>	
    <td>40KB(39.06KB)</td>	
    <td>< 10^-5 sec</td>
  </tr>
  <tr>
    <td>int a[100,000]</td>	
    <td>400KB(390.62KB)</td>	
    <td>< 10^-4 sec</td>
  </tr>
  <tr>
    <td>int a[1,000,000]</td>	
    <td>4MB(3.814MB)</td>	
    <td>< 1 ms</td>
  </tr>
  <tr>
    <td>int a[1,000][1,000]</td> 
    <td>4MB(3.814MB)</td>	
    <td>< 1 ms</td>
  </tr>
  <tr>
    <td>int a[10,000][10,000]</td>	
    <td>400MB(381.469MB)</td>	
    <td>< 0.1 sec</td>
  </tr>
  <tr>
    <td>int a[100,000][100,000]</td>
    <td>40GB(37.25GB)</td>
    <td>< 10 sec</td>
  </tr>
</table>

<br>

### - 입출력

C++ : <br>
* std::ios_base::sync_with_stdio(false);<br>
* std::cin.tie(nullptr);<br>
-> cin이 굉장히 느리기 때문에 위 명령어를 사용하여 빠르게 한다. 이 때 scanf는 사용할 수 없다.  (scanf보다 빠름)

<table>
  <caption>입력속도비교 : 10,000 이하 자연수 10^7개 파일 입력 받는 시간</caption>
  <tr>
    <th>C++17(cin.tie, cin)</th>
    <th>0.5938 sec</th>
  </tr>
  <tr>
    <td>Java(BufferedReader)</td>
    <td>0.6585 sec</td>
  </tr>
  <tr>
    <td>C11(scanf)</td>
    <td>0.9206 sec</td>
  </tr>
  <tr>
    <td>C++17(cin)</td>	
    <td>2.1742 sec</td>
  </tr>
  <tr>
    <td>Java(Scanner)</td>
    <td>4.8448 sec</td>
  </tr>
</table>

<b>EOF</b>
* C: while(scanf("%d %d", &a, &b) == 2){...}  scanf는 성공적으로 입력받으면 입력 개수를 반환한다.<br>
* C++: while(cin >> ... ) cin은 true false 반환
* JAVA: while(sc.hasNextInt) true false

<br><br>

ㅁ 자료구조1
---------

### - 스택(stack)

  스택은 <b>마지막 원소에 관심</b> 있을 때 사용한다. <b>순서를 뒤집을 때</b> 사용한다. (LIFO : 가장 마지막에 들어간 자료가 첫 번째로 나온다.)

c++:<br>
* std::stack<T> in stack<br>
* 멤버함수 : empty, size, top, push, pop -> O(1)<br>
* (위에 넣고 위에서 뺀다.) - 랜덤 접근 불가


### - 큐(queue)

  큐는 FIFO 성질을 가지며 <b>순서 바뀌지 않을 때</b> 사용한다. -> BFS 알고리즘에서 많이 활용된다.

c++:<br>
* std::queue<T> in queue<br>
* 멤버함수 : empty, size, front, back, push, pop -> O(1)<br>
* (뒤로 넣고 앞으로 뺀다.) - 랜덤 접근 불가


### - 덱(deque)
  
  덱은 double ended queue의 약자로 스택과 큐 성질을 다 가진다.

c++:<br>
* std::deque<T> in deque<br>
* 멤버함수 :
  - empty, size, front, back, push_front, push_back, pop_front, pop_back -> O(1)<br>
	- erase, remove, insert -> O(N)..? (O(1)은 아니다.)<br>
* 랜덤 접근이 가능 - 연산자 [ ]를 사용. -> O(1)<br>

##### vector, deque, list : <br>
   1. vector가 원소접근, push(pop)_back의 속도가 가장 빠르다. <br>
   2. deque는 list 보다 중간 삽입/제거 제외하고 모두 빠르다. <br>
   3. list는 중간 삽입/제거가 빠르다.

### - problems
|문제(링크)|소스코드(링크)|
|:---------:|:----------:|
| [boj 10828 : 스택](https://www.acmicpc.net/problem/10828) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj10828_%EC%8A%A4%ED%83%9D%5D.cpp) |
| [boj 9093 : 단어뒤집기](https://www.acmicpc.net/problem/9093) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj9093_%EB%8B%A8%EC%96%B4%EB%92%A4%EC%A7%91%EA%B8%B0%5D.cpp)|
| [boj 9012 : 괄호](https://www.acmicpc.net/problem/9012) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj9012_%EA%B4%84%ED%98%B8%5D.cpp)|
| [boj 1874 : 스택 수열](https://www.acmicpc.net/problem/1874) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj1874_%EC%8A%A4%ED%83%9D%EC%88%98%EC%97%B4%5D.cpp)|
| [boj 1406 : 에디터](https://www.acmicpc.net/problem/1406) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj1406_%EC%97%90%EB%94%94%ED%84%B0%5D.cpp)|
| [boj 10845 : 큐](https://www.acmicpc.net/problem/10845) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj10845_%ED%81%90%5D.cpp)|
| [boj 1158 : 조세퍼스 문제](https://acmicpc.net/problem/1158) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj1158_%EC%A1%B0%EC%84%B8%ED%8D%BC%EC%8A%A4%EB%AC%B8%EC%A0%9C%5D.cpp)|
| [boj 10866 : 덱](https://www.acmicpc.net/problem/10866) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj10866_%EB%8D%B1%5D.cpp)|
|  |  |
| [boj 17413 : 단어 뒤집기2](https://www.acmicpc.net/problem/17413) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj17413_%EB%8B%A8%EC%96%B4%EB%92%A4%EC%A7%91%EA%B8%B02%5D.cpp)|
| [boj 10799 : 쇠막대기](https://www.acmicpc.net/problem/10799) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj10799_%EC%87%A0%EB%A7%89%EB%8C%80%EA%B8%B0%5D.cpp)|
| [boj 17298 : 오큰수](https://www.acmicpc.net/problem/17298) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj17298_%EC%98%A4%ED%81%B0%EC%88%98%5D.cpp)</td>
| [boj 17299 : 오등큰수](https://www.acmicpc.net/problem/17299) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj17299_%EC%98%A4%EB%93%B1%ED%81%B0%EC%88%98%5D.cpp)|
|  |  |
| [boj 1918 : 후위 표기식](https://www.acmicpc.net/problem/1918) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj1918_%ED%9B%84%EC%9C%84%ED%91%9C%EA%B8%B0%EC%8B%9D%5D.cpp)|
| [boj 1935 : 후위 표기식2](https://www.acmicpc.net/problem/1935) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj1935_%ED%9B%84%EC%9C%84%ED%91%9C%EA%B8%B0%EC%8B%9D2%5D.cpp)|
| [boj 10808 : 알파벳 개수](https://www.acmicpc.net/problem/10808) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj10808_%EC%95%8C%ED%8C%8C%EB%B2%B3%EA%B0%9C%EC%88%98%5D.cpp)|
| [boj 10820 : 문자열 분석](https://www.acmicpc.net/problem/10820) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj10820_%EB%AC%B8%EC%9E%90%EC%97%B4%EB%B6%84%EC%84%9D%5D.cpp)|
| [boj 11655 : ROT13](https://www.acmicpc.net/problem/11655) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj11655_ROT13%5D.cpp)|
| [boj 10824 : 네 수](https://www.acmicpc.net/problem/10824) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj10824_%EB%84%A4%EC%88%98%5D.cpp)|
| [boj 11656 : 접미사 배열](https://www.acmicpc.net/problem/11656) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DataSturcture_1/%5Bboj11656_%EC%A0%91%EB%AF%B8%EC%82%AC%EB%B0%B0%EC%97%B4%5D.cpp)|
    
<br><br>

ㅁ 수학1
-------

#### - 나머지 연산

    (a-b) % M  =  (a%M - b%M + M) % M   :   c++과 java 같은 경우 -2%3 = -2 (python은 -2%3 = 1)

#### - 최대공약수

    GCD(a,b) = GCD(b,r) = ... = GCD(d,0) = d,   d:최대공약수  a%b = r ,   유클리드 호제법

#### - 최소공배수 :   

    a*b = gcd*lcm   ->  lcm = gcd * (a/gcd) * (b/gcd)  or  a/gcd * b

#### - 소수
    1. n % (2 ~ root(n) )  == 0 의 개수  즉, for ( i=2; i*i < n; i++) { if (n%i == 0) cnt++; // cnt > 2 면 break }  cnt == 2면 소수 --- O(root(N))
    2. n이하 소수 모두 찾기:  에라토스테네스의체 이용 --- O(N log(logN)) )

#### - problems
|문제(링크)|소스코드(링크)|
|:------:|:------:|
| [boj 10430 : 나머지](https://www.acmicpc.net/problem/10430) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj10430_%EB%82%98%EB%A8%B8%EC%A7%80%5D.cpp) |
| [boj 2609 : 최대공약수와 최소공배수](https://www.acmicpc.net/problem/2609) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj2609_%EC%B5%9C%EB%8C%80%EA%B3%B5%EC%95%BD%EC%88%98%EC%99%80%EC%B5%9C%EC%86%8C%EA%B3%B5%EB%B0%B0%EC%88%98%5D.cpp) |
| [boj 1934 : 최소공배수](https://www.acmicpc.net/problem/1934) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj1934_%EC%B5%9C%EC%86%8C%EA%B3%B5%EB%B0%B0%EC%88%98%5D.cpp) |
| [boj 1978 : 소수 찾기](https://www.acmicpc.net/problem/1978) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj1978_%EC%86%8C%EC%88%98%EC%B0%BE%EA%B8%B0%5D.cpp) |
| [boj 1929 : 소수 구하기](https://www.acmicpc.net/problem/1929) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj1929_%EC%86%8C%EC%88%98%EA%B5%AC%ED%95%98%EA%B8%B0%5D.cpp) |
| [boj 6588 : 골드바흐의 추측](https://www.acmicpc.net/problem/6588) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj6588_%EA%B3%A8%EB%93%9C%EB%B0%94%ED%9D%90%EC%9D%98%EC%B6%94%EC%B8%A1%5D.cpp) |
| [boj 10872 : 팩토리얼](https://www.acmicpc.net/problem/10872) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj10872_%ED%8C%A9%ED%86%A0%EB%A6%AC%EC%96%BC%5D.cpp) |
| [boj 1676 : 팩토리얼 0의 개수](https://www.acmicpc.net/problem/1676) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj1676_%ED%8C%A9%ED%86%A0%EB%A6%AC%EC%96%BC0%EC%9D%98%EA%B0%9C%EC%88%98%5D.cpp) |
| [boj 2004 : 조합 0의 개수](https://www.acmicpc.net/problem/2004) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj2004_%EC%A1%B0%ED%95%A90%EC%9D%98%EA%B0%9C%EC%88%98%5D.cpp) |
| | |
| [boj 9613 : GCD 합](https://www.acmicpc.net/problem/9613) | [(소스)](hhttps://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj9613_GCD%ED%95%A9%5D.cpp) |
| [boj 17087 : 숨바꼭질6](https://www.acmicpc.net/problem/17087) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj17087_%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%886%5D.cpp) |
| [boj 1373 : 2진수 8진수](https://www.acmicpc.net/problem/1373) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj1373_2%EC%A7%84%EC%88%988%EC%A7%84%EC%88%98%5D.cpp) |
| [boj 1212 : 8진수 2진수](https://www.acmicpc.net/problem/1212) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj1212_8%EC%A7%84%EC%88%982%EC%A7%84%EC%88%98%5D.cpp) |
| [boj 2089 : -2진수](https://www.acmicpc.net/problem/2089) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj2089_-2%EC%A7%84%EC%88%98%5D.cpp) |
| [boj 17103 : 골드바흐 파티션](https://www.acmicpc.net/problem/17103) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj17103_%EA%B3%A8%EB%93%9C%EB%B0%94%ED%9D%90%ED%8C%8C%ED%8B%B0%EC%85%98%5D.cpp) |
| | |
| [boj 2745 : 진법 변환](https://www.acmicpc.net/problem/2745) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj2745_%EC%A7%84%EB%B2%95%EB%B3%80%ED%99%98%5D.cpp) |
| [boj 11005 : 진법 변환 2](https://www.acmicpc.net/problem/11005) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj11005_%EC%A7%84%EB%B2%95%EB%B3%80%ED%99%982%5D.cpp) |
| [boj 11576 : Base Conversion](https://www.acmicpc.net/problem/11576) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj11576_Base%20Conversion%5D.cpp) |
| [boj 11653 : 소인수분해](https://www.acmicpc.net/problem/11653) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/Math_1/%5Bboj11653_%EC%86%8C%EC%9D%B8%EC%88%98%EB%B6%84%ED%95%B4%5D.cpp) |

<br><br>

ㅁ 다이나믹 프로그래밍 1
-------------------

큰 문제를 작은 문제로. => 1 DP,  2 분할 정복

DP와 분할 정복의 차이점 : 중복의 발생 여부
* DP :  ex) 40명 => [10, 30]  => [10, [10, 20]] => [10, [10, [10, 10]]]
* 분할정복 : ex) 40명 => [15, 15]//왼,오 => [[7, 8], [7, 8]]//왼,오 => ... =>[1,...,1]

### - DP

#### 두 가지 속성.
    1. Overlapping Subproblem : 작은(부분) 문제가 겹침.
		  ex) 피보나치수열:  Fn = Fn-1 + Fn-2,  Fn-1 = Fn-2 + Fn-3, ...
    2. Optimal Substructure : 최적 부분 구조 (문제의 정답을 작은(부분)문제에서 구함)
		  ex) 서울에서 부산까지 가는 가장 빠른 길이 대전 대구를 순서대로 거쳐야 한다면,  대전->부산 의 가장 빠른 길은 대전->대구->부산이다.
		  ex) 피보나치수열:  Fn = Fn-1 + Fn-2, Fn-1 = Fn-2 + Fn-3

위 두가지 속성을 이용하려면 이미 풀었던 작은 문제의 답을 저장하는 것이 좋다. => Memoization

#### 구현 방식
    1. top down : 큰 문제를 작은 문제로 나누고 푼 뒤 큰 문제를 다시 품 => 재귀 방식
    2. bottom up : 작은 문제를 풀고 큰 문제로 합쳐 품 => 반복문
 
#### 시간 차이
    언뜻 재귀(top down)가 더 많이 걸릴 것 같지만, 점화식에 따라 다르다.

#### 문제 풀이 전략
    점화식 정의 세우기 -> 점화식 세우기

#### problems
|문제(링크)|소스코드(링크)|
|:-------:|:-------:|
| [boj 1463 : 1로 만들기](https://acmicpc.net/problem/1463) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj1463_1%EB%A1%9C%EB%A7%8C%EB%93%A4%EA%B8%B0%5D.cpp) |
| [boj 11726 : 2Xn 타일링](https://acmicpc.net/problem/11726) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj11726_2Xn%ED%83%80%EC%9D%BC%EB%A7%81%5D.cpp) |
| [boj 11727 : 2Xn 타일링 2](https://acmicpc.net/problem/11727) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj11727_2Xn%20%ED%83%80%EC%9D%BC%EB%A7%812%5D.cpp) |
| [boj 9095 : 1,2,3 더하기](https://acmicpc.net/problem/9095) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj9095_1%2C2%2C3%EB%8D%94%ED%95%98%EA%B8%B0%5D.cpp) |
| [boj 11052 : 카드 구매하기](https://acmicpc.net/problem/11052) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj11052_%EC%B9%B4%EB%93%9C%EA%B5%AC%EB%A7%A4%ED%95%98%EA%B8%B0%5D.cpp) |
| [boj 16194 : 카드 구매하기 2](https://acmicpc.net/problem/16194) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj16194_%EC%B9%B4%EB%93%9C%EA%B5%AC%EB%A7%A4%ED%95%98%EA%B8%B02%5D.cpp) |
| [boj 15990 : 1,2,3 더하기 5](https://acmicpc.net/problem/15990) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj15990_1%2C2%2C3%EB%8D%94%ED%95%98%EA%B8%B05%5D.cpp) |
| [boj 10844 : 쉬운 계단 수](https://acmicpc.net/problem/10844) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj10844_%EC%89%AC%EC%9A%B4%EA%B3%84%EB%8B%A8%EC%88%98%5D.cpp) |
| [boj 2193 : 이친수](https://acmicpc.net/problem/2193) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj2193_%EC%9D%B4%EC%B9%9C%EC%88%98%5D.cpp) |
| [boj 11053 : 가장 긴 증가하는 부분 수열](https://acmicpc.net/problem/11053) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj11053_%EA%B0%80%EC%9E%A5%EA%B8%B4%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B4%5D.cpp) |
| [boj 14002 : 가장 긴 증가하는 부분 수열 4](https://acmicpc.net/problem/14002) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj14002_%EA%B0%80%EC%9E%A5%EA%B8%B4%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B44%5D.cpp) |
| [boj 1912 : 연속합](https://acmicpc.net/problem/1912) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj1912%20_%EC%97%B0%EC%86%8D%ED%95%A9%5D.cpp) |
| [boj 1699 : 제곱수의 합](https://acmicpc.net/problem/1699) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj1699_%EC%A0%9C%EA%B3%B1%EC%88%98%EC%9D%98%ED%95%A9%5D.cpp) |
| [boj 2225 : 합분해](https://acmicpc.net/problem/2225) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj2225_%ED%95%A9%EB%B6%84%ED%95%B4%5D.cpp) |
| | |
| [boj 15988 : 1,2,3 더하기 3](https://acmicpc.net/problem/15988) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj15988_1%2C2%2C3%EB%8D%94%ED%95%98%EA%B8%B03%5D.cpp) |
| [boj 1149 : RGB 거리](https://acmicpc.net/problem/1149) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj1149_RGB%EA%B1%B0%EB%A6%AC%5D.cpp) |
| [boj 1309 : 동물원](https://acmicpc.net/problem/1309) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj1309_%EB%8F%99%EB%AC%BC%EC%9B%90%5D.cpp) |
| [boj 11057 : 오르막 수](https://acmicpc.net/problem/11057) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj11057_%EC%98%A4%EB%A5%B4%EB%A7%89%EC%88%98%5D.cpp) |
| [boj 9465 : 스티커](https://acmicpc.net/problem/9465) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj9465_%EC%8A%A4%ED%8B%B0%EC%BB%A4%5D.cpp) |
| [boj 2156 : 포도주 시식](https://acmicpc.net/problem/2156) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj2156_%ED%8F%AC%EB%8F%84%EC%A3%BC%EC%8B%9C%EC%8B%9D%5D.cpp) |
| [boj 1932 : 정수 삼각형](https://acmicpc.net/problem/1932) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj1932_%EC%A0%95%EC%88%98%EC%82%BC%EA%B0%81%ED%98%95%5D.cpp) |
| [boj 11055 : 가장 큰 증가하는 부분 수열](https://acmicpc.net/problem/11055) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj11055_%EA%B0%80%EC%9E%A5%ED%81%B0%EC%A6%9D%EA%B0%80%ED%95%98%EB%8A%94%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B4%5D.cpp) |
| [boj 11722 : 가장 긴 감소하는 부분 수열](https://acmicpc.net/problem/11722) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj11722_%EA%B0%80%EC%9E%A5%EA%B8%B4%EA%B0%90%EC%86%8C%ED%95%98%EB%8A%94%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B4%5D.cpp) |
| [boj 11054 : 가장 긴 바이토닉 부분 수열](https://acmicpc.net/problem/11054) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj11054_%EA%B0%80%EC%9E%A5%EA%B8%B4%EB%B0%94%EC%9D%B4%ED%86%A0%EB%8B%89%EB%B6%80%EB%B6%84%EC%88%98%EC%97%B4%5D.cpp) |
| [boj 13398 : 연속합 2](https://acmicpc.net/problem/13398) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj13398_%EC%97%B0%EC%86%8D%ED%95%A92%5D.cpp) |
| [boj 2133 : 타일 채우기](https://acmicpc.net/problem/2133) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj2133_%ED%83%80%EC%9D%BC%EC%B1%84%EC%9A%B0%EA%B8%B0%5D.cpp) |
| | |
| [boj 17404 : RGB 거리 2](https://acmicpc.net/problem/17404) | [(source code)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/DynamicProgramming_1/%5Bboj17404_RGB%EA%B1%B0%EB%A6%AC2%5D.cpp) |

