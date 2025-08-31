#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int n, k;
int visited[100010] = { -1 };

void bfs(int start) {
	queue<int>q;
	q.push({ start });
	visited[start] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == k) return;
		for (int i = 0; i < 3; i++) {
			if (i == 0) {
				int next = now - 1;
				if (next < 0) continue;
				if (visited[next] > visited[now] + 1) {
					visited[next] = visited[now] + 1;
				}
				else if (visited[next] > 0) continue;
				else {
					visited[next] = visited[now] + 1;
				}
				q.push(next);
			}
			else if (i == 1) {
				int next = now + 1;
				if (next > 100000) continue;
				if (visited[next] > visited[now] + 1) {
					visited[next] = visited[now] + 1;
				}
				else if (visited[next] > 0) continue;
				else {
					visited[next] = visited[now] + 1;
				}
				q.push(next);
			}
			else {
				int next = now * 2;
				if (next > 100000) continue;
				if (visited[next] > visited[now] + 1) {
					visited[next] = visited[now] + 1;
				}
				else if (visited[next] > 0) continue;
				else {
					visited[next] = visited[now] + 1;
				}
				q.push(next);
			}
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> n >> k;

	bfs(n);

	cout << visited[k];

	return 0;
}