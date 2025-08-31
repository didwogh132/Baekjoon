#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int n, m;
vector<int> arr[110];
int visited[110];

void bfs(int start) {
	queue<int>q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 1; i <= 6; i++) {
			int next = now + i;
			if (next > 100) continue;

			if (arr[next].size() != 0) {
				next = arr[next][0];
			}
			if (visited[next] > visited[now] + 1) {
				visited[next] = visited[now] + 1;
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
	cin >> n >> m;

	for (int i = 0; i < n + m; i++) {
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
	}

	bfs(1);

	cout << visited[100];

	return 0;
}