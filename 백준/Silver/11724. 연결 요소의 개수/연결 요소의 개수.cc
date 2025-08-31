#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
vector<int>arr[1010];
int visited[1010];
int cnt;

void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
			if (visited[next] >= 0) continue;
			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) {
		if (visited[i] == -1) {
			bfs(i);
			cnt++;
		}
	}
	cout << cnt;
	return 0;
}