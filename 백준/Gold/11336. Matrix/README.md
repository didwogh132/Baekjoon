# [Gold III] Matrix - 11336 

[문제 링크](https://www.acmicpc.net/problem/11336) 

### 성능 요약

메모리: 10760 KB, 시간: 148 ms

### 분류

데이크스트라, 그래프 이론, 최단 경로

### 제출 일자

2025년 11월 30일 22:32:43

### 문제 설명

<p>After several years of searching, Morpheus finally found The One - Thomas A. Anderson, a computer programmer known to his friends as Neo. You and Neo are best friends. In fact, you participated several times together in Regional Programming Contests. Morpheus decided to save both of you from the Matrix world by offering you the red pill. After several months of training aboard Morpheus ship, Nebuchadnezzar, it was the time for Neo to see Oracle, who predicted the eventual emergence of The One. While Neo and Morpheus went to see her in the Matrix world you stayed back in the real world to ensure that everything was going according to plan.</p>

<p>After seeing Oracle, Neo and Morpheus were trying to get back to the real world through one of the telephones in the Matrix world. After Morpheus managed to get back and before Neo could use the telephone, an agent destroyed it leaving Neo stranded in the Matrix world. Since Neo was still not at his full potential, his only choice was to avoid fighting agents by running to the nearest telephone that he could reach without the possibility of finding one of the agents on the way.</p>

<p>Since you are the best programmer aboard the Nebuchadnezzar, Morpheus asks you to write a program to determine whether Neo will have to fight an agent or not (since you don't know how the agents will move, your code should assume the worst case scenario). If Neo is able to avoid agents, your program should determine when Neo will get out of the Matrix world given locations of the agents and telephones and the amount of time needed to move between different locations.</p>

<p>Note that if both Neo and an agent arrive at a telephone location at the same time, Neo will have to fight the agent before picking up the phone.</p>

### 입력 

 <p>First line of the input contains an integer T (1 <= T <= 100) - the number of test cases.</p>

<p>Each test case start with a line containing four integers: N (3 <= N <= 1000) - representing the number of locations in the Matrix world, M - representing the number of paths connecting different locations, NA - representing the number of agents and NT - representing the number of telephones. (NA,NT > 0, NA+NT < N-1)</p>

<p>Next M lines each contain three integers u, v and m (0 <= u,v < N, 1 <= m <= 30). The first two integers represent two locations in the matrix (With 0 representing Neo's starting location) and the third integer represents the time (in minutes) required to between these two locations.</p>

<p>Next line contains NA integers giving the locations of the agents.</p>

<p>The last line of the test case contains NT integers giving the locations of the telephones</p>

<p>Note that there is no agent, nor telephone at location 0 (i.e. Neo's initial location). Also, there is no location that initially has both a telephone and an agent present.</p>

### 출력 

 <p>For each test case, print "Neo may fight an Agent" if there is no path that ensures the safety of Neo. Otherwise, print the time (in minutes) needed in order to get out of the Matrix.</p>

