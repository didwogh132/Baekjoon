#include <iostream>
#include <algorithm>
#include <cstring>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

vector<int> arr[101];
int visited[101];
int dat[101];
int Min = INT_MAX;

void bfs(int start) {
	queue<int> q;
	q.push(start);
	visited[start] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 0; i < arr[now].size(); i++) {
			int next = arr[now][i];
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
	int n, m;
	int num;
	memset(dat, 0, sizeof(dat));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}
	for (int i = 1; i <= n; i++) {
		memset(visited, -1, sizeof(visited));
		bfs(i);
		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += visited[j];
		}
		if (sum < Min) {
			Min = sum;
			num = i;
		}
	}

	cout << num;

	return 0;
}