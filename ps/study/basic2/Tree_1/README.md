# Tree_1

## 트리의 특징

- 사이클이 없는 연결 그래프
- 정점의 개수: V
- 간선의 개수: V-1

      루트는 정해주기 나름이다.  
      루트를 정해주면 아래 특징이 생긴다.

      1. 부모-자식 관계.
      2. 형제: 부모가 같은 노드들
      3. leaf(terminal) node (단말노드): 자식 없는 노드
      4. 높이: 깊이의 최대값
      5. 조상ancester,자손decendent - 자신포함

1. 이진트리: 

        최대 2개의 자식

2. 포화 이진 트리(perfect Binary Tree): 

        모든 단말 노드의 깊이가 같은 이진 트리

3. 완전 이진 트리(complete Binary Tree): 
  
        모든 단말 노드의 형제가 존재 (모든 노드의 자식이 0 or 2개 존재) 하는 이진 트리

<br>

## 트리의 표현

- 그래프의 표현과 같은 방식

- 루트가 있다면 트리만의 방식 존재

  → 트리의 부모만 저장하는 방식 ⇒ union find

  → 완전이진트리: 배열 ⇒ heap, segment tree

      전자의 장단점 : 부모찾기 O(1), 자식 찾기 O(N)

      후자의 장단점 : 부모/자식찾기 O(1) 완전이진트리만 사용가능

<br>

## 트리의 순회

- 트리의 모든 노드를 방문하는 순서
- DFS BFS 존재

DFS의 경우 3가지 존재
      
      pre-order, in-order, post-order  
      각각 부모 노드 방문의 순서가 처음, 2번째 3번째다.

순회의 의미: 

      pre-order : 그래프의 DFS 방식과 같음
      in-order : 보통 이진 트리에서 쓰임 (BST 삭제에서 쓰임)
      ⭐post-order : 자식에 대한 정보로 현재(부모)노드의 정보를 정할 때 쓰임

### problems

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
|[boj 2250 : 트리의 높이와 너비]([https://www.acmicpc.net/problem/2250](https://www.acmicpc.net/problem/2250))|[(소스)]()|DFS in-order|

<br>

## 트리의 탐색

- 트리의 탐색은 DFS BFS
- 트리는 사이클 없는 그래프
    → 두 정점의 경로 1개
    → BFS(DFS) 알고리즘으로 최단 거리

### problems

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
|[boj 11725 : 트리의 부모 찾기]([https://www.acmicpc.net/problem/11725](https://www.acmicpc.net/problem/11725))|[(소스)]()|DFS or BFS|

<br>

## 트리의 지름

- 모든 경로 중 가장 긴 경로의 길이
- 탐색 2번으로 구한다.
    1. 한 정점에서 가장 먼 거리의 정점 u 구하기
    2. 정점 u에서 가장 먼 거리의 정점 v 구하기 → path[u - v]가 지름

### problems

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
|[boj 1167 : 트리의 지름]([https://www.acmicpc.net/problem/1167](https://www.acmicpc.net/problem/1167))|[(소스)]()|BFS or DFS(post-order|