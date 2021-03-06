# BFS

- 시작 정점에서 모든 정점을 1번씩 방문

- dfs와는 다르게 최단 거리를 구할 수 있는 경우가 잇는데, 가중치가 1인 그래프가 그러한 경우다.

- BFS를 이용해 해결할 수 있는 문제의 조건

  1. 최소 비용 문제
  2. 간선의 가중치가 1
  3. 정점과 간선의 개수가 적어야 한다.(O(V+E)와 제한 시간을 고려)
  4. 비용과 가중치의 단위가 일치 (거리면 거리 시간이면 시간)

<br>

## problems

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
|[boj 1697 : 숨바꼭질](https://www.acmicpc.net/problem/1697)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BFS/%5Bboj1697_%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%88%5D.cpp)||
|[boj 13913 : 숨바꼭질4](https://www.acmicpc.net/problem/13913)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BFS/%5Bboj13913_%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%884%5D.cpp)||

<br>

## problems

    정점 나누기 (같은 정점을 서로 다른 정점으로 나눠야 하는 경우)

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
|[boj 14226 : 이모티콘](https://www.acmicpc.net/problem/14226)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BFS/%5Bboj14226_%EC%9D%B4%EB%AA%A8%ED%8B%B0%EC%BD%98%5D.cpp)||

<br>

## problems

    덱 사용하기
    (BFS는 가중치가 1인 경우가 아닌, 0과 1인 경우도 사용 가능)

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
|[boj 13549 : 숨바꼭질 3](https://www.acmicpc.net/problem/13549)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BFS/%5Bboj13549_%EC%88%A8%EB%B0%94%EA%BC%AD%EC%A7%883%5D.cpp)||
|[boj 1261 : 알고스팟](https://www.acmicpc.net/problem/1261)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/BFS/%5Bboj1261_%EC%95%8C%EA%B3%A0%EC%8A%A4%ED%8C%9F%5D.cpp)||