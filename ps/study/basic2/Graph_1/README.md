# 그래프1

- 문제의 상황을 그래프로 모델링한 뒤 알고리즘 수행

    → 어떻게 모델링하는지가 중요하다.

정점 (Node, Vertex)

간선 (Edge)

G = (V,E)로 나타낸다.

### 그래프의 타입

- 방향 그래프
- 방향 없는 그래프 (보통 방향 없는 그래프를 **방향 그래프로 표현**한다.)
- 간선 여러개, 루프 ...

### 그래프 용어

- **경로 (Path)**

    → 정점 A에서 B로 가는 간선의 수열

    → 주로 최단경로에서 자주 쓰인다.

    → 단순 경로 : 정점은 한 번만.

- 사이클(Cycle) - 경로의 일종

    → 경로의 일종으로 정점 A에서 다시 A로 돌아오는 경로.

    → 단순 사이클 : A는 두번, 그외 정점은 한 번만.

- **가중치 (Weight)**

    → 간선의 값 (cost, distance, time, ...)

    → 주로 가중치가 없으면 가중치를 모두 1이라 생각하면 된다.

- 차수 (Degree)

    → 한 정점에 연결된 간선 개수 (그 정점의 차수)

    → 방향 그래프: in-degree, out-degree

### 그래프 예시 (정점, 간선, 차수)

- 지도: 교차로, 도로, 도로 수
- 페이스북: 사람, 친구관계, 친구 수
- 트위터: 사람, follow관계, (follower, followee)

### 그래프의 표현

- 정점: 정점의 수(6개 → 0~5 인덱스)
- 간선: pair(정점→정점): (정점,정점)

### 그래프의 저장 방법

1. 인접 행렬: 2D array
    - space complexity: O(V^2)
    - 한정점과 연결된 모든 간선 찾는 시간: O(차수)
2. **인접 리스트**: 1D list array(하나의 인덱스에 하나의 리스트가 존재)
    - space complexity: O(E)
    - 한 정점과 연결된 모든 간선 찾는 시간: O(차수)
    - c++: vector, java: arraylist, python: [ ]
3. 인접행렬? 인접리스트?
    - 공간복잡도: 인접행렬 > 인접리스트
    - (u,v) 간선 유무 판별 시간: 인접행렬O(1), 인접리스트O(차수)
    - 한 정점과 연결된 모든 간선 찾는 시간: 인접행렬 > 인접리스트

    → 그래프 이론에서 3번째 목록의 연산을 가장 많이 사용하므로 **주로 인접리스트를 사용하자.**

4. 간선리스트: 인접리스트 사용 불가 혹은 사용하기 싫을 때 사용
    - E[ ]: 간선을 순서대로 저장
    - cnt[ ]: cnt[i]는 정점 i의 차수를 누적
    (즉, 0,1,2정점의 차수가 1,2,3이면 cnt[0,1,2] = 1,3,6이다. → 정점 i와 연결된 간선은 E[cnt[i-1]]~E[cnt[i]-1]이다.

#### problems

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
| [boj 13023 : ABCDE](https://www.acmicpc.net/problem/13023) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj13023_ABCDE%5D.cpp)| 그래프 모델링 문제 |

### 그래프의 탐색

목적: 임의의 정점에서 시작 (시작 점이 존재)해서 연결되어 있는 모든 정점을 한 번씩 방문하는 것.

1. DFS (깊이 우선 탐색)
    - 스택이용 - 더 이상 나아갈 수 없을 때, 돌아갈 노드 저장
    - visit check (방문할 때, 혹은 방문하고 맨 처음으로 visit true)
    - (단, 재귀함수를 이용하면 돌아갈 노드를 따로 저장할 필요가 없다.)
2. BFS (너비 우선 탐색)
    - 큐이용 - 나아갈 노드를 저장
    - visit check (큐에 넣을 때, visit true)

**BFS → 모든 가중치가 1일 때, 최단 거리 구하기에 용이하다.**

#### problems

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
| [boj 1260 : DFS와 BFS](https://www.acmicpc.net/problem/1260) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj1260_DFS%EC%99%80BFS%5D.cpp)| dfs, bfs 사용법|

### 연결요소

연결된 노드들을 하나의 집합이라 할 때, 이 집합을 연결요소라 한다.

DFS,BFS를 통해 이 연결요소를 알 수 있다. 

이때, 연결요소가 1개인 그래프를 연결 그래프라 한다.

### 이분 그래프

집합 A의 노드에서 집합 B의 노드로 연결되는 그래프를 의미한다. 같은 집합 내에서는 연결되지 않아야 한다.

집합A,B구분하기 → dfs(or bfs)를 통해 아직 색칠하지 않은 노드들을 방문하여 색칠한다. 인접한 노드는 다른 색으로 색칠한다. 만약 연결 그래프면 하나의 dfs(or bfs)를 이용하면 되지만 그렇지 않다면 연결요소 만큼의 dfs(or bfs)를 수행해준다. 모두 수행한 이후에 인접한 두 노드의 색이 같은 경우가 있다면 이분 그래프가 아니다.

### problems

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
| [boj 2667 : 단지번호붙이기](http://www.acmicpc.net/problem/2667)| [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj2667_%EB%8B%A8%EC%A7%80%EB%B2%88%ED%98%B8%EB%B6%99%EC%9D%B4%EA%B8%B0%5D.cpp) | dfs |
| [boj 2282 : 섬의 개수](https://www.acmicpc.net/problem/4963)| [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj4963_%EC%84%AC%EC%9D%98%EA%B0%9C%EC%88%98%5D.cpp) | dfs |
| [boj 7576 : 토마토](https://www.acmicpc.net/problem/7576)| [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj7576_%ED%86%A0%EB%A7%88%ED%86%A0%5D.cpp) | bfs(최단시간) |
| [boj 7562 : 나이트의 이동](https://www.acmicpc.net/problem/7576)| [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj7562_%EB%82%98%EC%9D%B4%ED%8A%B8%EC%9D%98%EC%9D%B4%EB%8F%99%5D.cpp) | bfs(최단거리) |
| [boj 16929 : Two Dots](https://www.acmicpc.net/problem/16929) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj7562_TwoDots%5D.cpp) | dfs(cycle) |
| [boj 16957 : 서울 지하철 2호선](https://www.acmicpc.net/problem/16947) | [(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj16947_%EC%84%9C%EC%9A%B8%EC%A7%80%ED%95%98%EC%B2%A02%ED%98%B8%EC%84%A0%5D.cpp) [(소스2)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj16947_%EC%84%9C%EC%9A%B8%EC%A7%80%ED%95%98%EC%B2%A02%ED%98%B8%EC%84%A0%5D_2.cpp) | dfs(cycle), bfs(최단거리) |

### challenge

|문제(링크)|소스코드(링크)|비고|
|:------:|:--------:|:--:|
|[boj 16940 : BFS 스페셜 저지](https://www.acmicpc.net/problem/16940)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj16940_BFS%EC%8A%A4%ED%8E%98%EC%85%9C%EC%A0%80%EC%A7%80%5D.cpp)|BFS 특징 응용|
|[boj 16940 : BFS 스페셜 저지](https://www.acmicpc.net/problem/16940)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj16964_DFS%EC%8A%A4%ED%8E%98%EC%85%9C%EC%A0%80%EC%A7%80%5D.cpp)|DFS 특징 응용|
|[boj 2164 : 다리 만들기](https://www.acmicpc.net/problem/2164)|[(소스)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj2164_%EB%8B%A4%EB%A6%AC%EB%A7%8C%EB%93%A4%EA%B8%B0%5D.cpp) [(소스2)](https://github.com/95kim1/study_learn/blob/main/ps/learn/basic2/Graph_1/%5Bboj2164_%EB%8B%A4%EB%A6%AC%EB%A7%8C%EB%93%A4%EA%B8%B0%5D_2.cpp)|DFS(separate) BFS(최단거리)|
