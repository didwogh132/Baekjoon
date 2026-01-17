# [Gold II] Median Tree - 10661 

[문제 링크](https://www.acmicpc.net/problem/10661) 

### 성능 요약

메모리: 2276 KB, 시간: 32 ms

### 분류

그래프 이론, 자료 구조, 분리 집합, 최소 스패닝 트리

### 제출 일자

2026년 1월 17일 15:09:44

### 문제 설명

<p>You are given a connected undirected graph which has even numbers of nodes. A connected graph is a graph in which all nodes are connected directly or indirectly by edges.</p>

<p>Your task is to find a spanning tree whose median value of edges' costs is minimum. A spanning tree of a graph means that a tree which contains all nodes of the graph.</p>

### 입력 

 <p>The input consists of multiple datasets.</p>

<p>The format of each dataset is as follows.</p>

<pre>n m
s<sub>1</sub> t<sub>1</sub> c<sub>1</sub>
...
s<sub>m</sub> t<sub>m</sub> c<sub>m</sub>
</pre>

<p>The first line contains an even number n (2 ≤ n ≤ 1,000) and an integer m (n-1 ≤ m ≤ 10,000). n is the nubmer of nodes and m is the number of edges in the graph.</p>

<p>Then m lines follow, each of which contains s<sub>i</sub> (1 ≤ s<sub>i</sub> ≤ n), t<sub>i</sub> (1 ≤ s<sub>i</sub> ≤ n, t<sub>i</sub> ≤ s<sub>i</sub>) and c<sub>i</sub> (1 ≤ c<sub>i</sub> ≤ 1,000). This means there is an edge between the nodes s<sub>i</sub> and t<sub>i</sub> and its cost is c<sub>i</sub>. There is no more than one edge which connects s<sub>i</sub> and t<sub>i</sub>.</p>

<p>The input terminates when n=0 and m=0. Your program must not output anything for this case.</p>

### 출력 

 <p>
Print the median value in a line for each dataset.
</p>

