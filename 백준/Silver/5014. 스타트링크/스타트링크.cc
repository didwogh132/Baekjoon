#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int f, s, g, u, d;
int visited[1000010];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (now == g) break;
		for (int i = 0; i < 2; i++) {
			int next;
			if (i == 0) {
				next = now + u;
				if (next > f) continue;
				if (visited[next] > visited[now] + 1) {
					visited[next] = visited[now] + 1;
				}
				else if (visited[next] >= 0) continue;
				else {
					visited[next] = visited[now] + 1;
				}
			}
			else {
				next = now - d;
				if (d == 0 && s > g) break;
				if (next <= 0) continue;
				if (visited[next] > visited[now] + 1) {
					visited[next] = visited[now] + 1;
				}
				else if (visited[next] >= 0) continue;
				else {
					visited[next] = visited[now] + 1;
				}
			}
			q.push(next);
		}
	}

}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> f >> s >> g >> u >> d;

	bfs(s);
	if (visited[g] == -1) {
		cout << "use the stairs";
	}
	else {
		cout << visited[g];
	}
	return 0;
}