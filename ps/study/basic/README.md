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

   [boj 10828 : 스택](https://www.acmicpc.net/problem/10828), [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B01/%5Bboj%2010828:%20%EC%8A%A4%ED%83%9D%5D.md)<br>
   [boj 9093 : 단어뒤집기](https://www.acmicpc.net/problem/9093), [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B01/%5Bboj%209093%20:%20%EB%8B%A8%EC%96%B4%EB%92%A4%EC%A7%91%EA%B8%B0%5D.md)<br>
   [boj 9012 : 괄호](https://www.acmicpc.net/problem/9012), [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B01/%5Bboj%209012%20:%20%EA%B4%84%ED%98%B8%5D.md)<br>
   [boj 1874 : 스택 수열](https://www.acmicpc.net/problem/1874), [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B01/%5Bboj%201874%20:%20%EC%8A%A4%ED%83%9D%20%EC%88%98%EC%97%B4%5D.md)<br>
   [boj 1406 : 에디터](https://www.acmicpc.net/problem/1406) [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B01/%5Bboj%201406%20:%20%EC%97%90%EB%94%94%ED%84%B0%5D.md)<br>
   [boj 10845 : 큐](https://www.acmicpc.net/problem/10845) [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic/%EC%9E%90%EB%A3%8C%EA%B5%AC%EC%A1%B01/%5Bboj%2010845%20:%20%ED%81%90%5D.md)<br>
   [boj : 조세퍼스 문제](https://acmicpc.net/problem/1158) [[소스]]<br>
   [boj : 덱](https://www.acmicpc.net/problem/10866) [[소스]]<br>
    
   [boj : 단어 뒤집기2](https://www.acmicpc.net/problem/17413) [[소스]]<br>
   [boj : 쇠막대기](https://www.acmicpc.net/problem/10799) [[소스]]<br>
   [boj : 오큰수](https://www.acmicpc.net/problem/17298) [[소스]]<br>
   [boj : 오등큰수](https://www.acmicpc.net/problem/17299) [[소스]]<br>
   
   [boj : 후위 표기식](https://www.acmicpc.net/problem/1918) [[소스]]<br>
   [boj : 후위 표기식2](https://www.acmicpc.net/problem/1935) [[소스]]<br>
   [boj : 알파벳 개수](https://www.acmicpc.net/problem/10808) [[소스]]<br>
   [boj : 문자열 분석](https://www.acmicpc.net/problem/10820) [[소스]]<br>
   [boj : ROT13](https://www.acmicpc.net/problem/11655) [[소스]]<br>
   [boj : 네 수](https://www.acmicpc.net/problem/10824) [[소스]]<br>
   [boj : 접미사 배열](https://www.acmicpc.net/problem/11656) [[소스]]
    
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


	


