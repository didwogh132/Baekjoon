#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int n;
vector<int> arr[110];
int a, b;
int visited[110];

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
	cin >> n;
	cin >> a >> b;
	int m;
	cin >> m;
	for (int i = 0; i < m; i++) {
		int from, to;
		cin >> from >> to;
		arr[from].push_back(to);
		arr[to].push_back(from);
	}

	bfs(a);

	cout << visited[b];

	return 0;
}