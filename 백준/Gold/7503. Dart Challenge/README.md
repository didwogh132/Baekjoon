# [Gold IV] Dart Challenge - 7503 

[문제 링크](https://www.acmicpc.net/problem/7503) 

### 성능 요약

메모리: 2768 KB, 시간: 316 ms

### 분류

다이나믹 프로그래밍, 배낭 문제

### 제출 일자

2025년 12월 10일 21:30:33

### 문제 설명

<p>Clark and Harry are siblings. As they had been rivals since their early childhood, their father decided that both should concentrate on a different sport when they were thirteen. That way, they would not have to compete for success. Now both are twenty years old and excel in different fields: Clark plays chess while Harry participates in dart-tournaments.</p>

<p>Having won a series of three tournaments in a row, Harry started teasing Clark about not having as much success. Clark retorted that chess was less luck-based and thus more difficult. That offended Harry and led him to the reply that in order to play darts optimally, a lot of combinatorics are necessary. Clark returned an icy smile and the comment that memorizing all different late-games could hardly be called “combinatorics”.</p>

<p>This is how it came to the wager. Harry bets that he can find all possible late-games for generalized dart-boards where memorized late-games do not help him. When Clark showed him a list of possible dartboards, Harry had to admit that he probably bit off more than he can chew. As his friend, you have to help him!</p>

<p>A dart-board consists of different areas. Each area has an assigned score for hitting it. Each area also has a double- and a triple-field that are worth twice and three times the score of the area. The only exception is the area for the highest score: It has only a double- and no triple-field! Given the values of the different areas you have to find the number of possible scores that can be obtained with a given number of darts.</p>

### 입력 

 <p>The inputs start with a line containing a single integer n. Each of the n following lines contains one test case. Each test case starts with two integers 1 ≤ a ≤ 100, 1 ≤ k ≤ 50, the number of different areas on the dart-board and the number of darts. a integers 1 ≤ s<sub>i</sub> ≤ 100 follow. s<sub>i</sub> is the score for hitting area i. All scores are distinct. Remember that each area has a double- and, with exception of the area with the highest score, a triple-field. It is always possible to score 0 with any given dart by not hitting the board.</p>

### 출력 

 <p>The output for every test case begins with a line containing “Scenario #i:”, where i is the number of the scenario counting from 1. After that, output a single line containing the number of different scores that can be obtained with k darts on the given board. Terminate each test case with an empty line.</p>

