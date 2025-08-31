#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m, r;
vector<int> arr[100010];
int visited[100010];

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (visited[next] > visited[now] + 1) {
				visited[next] > visited[now] + 1;
			}
			else if (visited[next] > -1) continue;
			else {
				visited[next] = visited[now] + 1;
			}
			q.push(next);
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> n >> m >> r;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}

	bfs(r);

	for (int i = 1; i <= n; i++) {
		cout << visited[i] << "\n";
	}
}