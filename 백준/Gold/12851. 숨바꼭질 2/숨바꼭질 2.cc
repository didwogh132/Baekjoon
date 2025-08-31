#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int n, m;
int arr[100010];
int visited[100010];
int cnt;
int Min = 21e8;

void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start]=0;

	while (!q.empty()) {
		int now = q.front(); q.pop();


		for (int i = 0;i < 3; i++) {
			int next;
			if (i == 0) {
				next = now * 2;
				if (next > 100000) continue;
				if (visited[next] >= visited[now] + 1) {
					visited[next] = visited[now] + 1;
				}
				else if (visited[next] >= 0) continue;
				else {
					visited[next] = visited[now] + 1;
				}
				q.push(next);
			}
			else if (i == 1) {
				next = now + 1;
				if (next > 100000) continue;
				if (visited[next] >= visited[now] + 1) {
					visited[next] = visited[now] + 1;
				}
				else if (visited[next] >= 0) continue;
				else {
					visited[next] = visited[now] + 1;
				}
				q.push(next);
			}
			else {
				next = now - 1;
				if (next < 0) continue;
				if (visited[next] >= visited[now] + 1) {
					visited[next] = visited[now] + 1;
				}
				else if (visited[next] >= 0) continue;
				else {
					visited[next] = visited[now] + 1;
				}
				q.push(next);
			}
			if (next == m) {
				if (visited[m] < Min) Min = visited[m];
				if (visited[m] == Min) cnt++;
			}
		}
	}
}


int main() {

	memset(visited, -1, sizeof(visited));
	cin >> n >> m;

	bfs(n);

	if (n == m) {
		cout << visited[m] << "\n";
		cout << cnt + 1;
	}
	else {
		cout << visited[m] << "\n";
		cout << cnt;
	}
	return 0;
}