#include <iostream>
#include <queue>
#include <memory.h>

using namespace std;

int n;
int arr[1001];
int visited[1001];

void bfs(int num) {
	queue<int> q;
	q.push(num);
	visited[num] = 0;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (arr[now] == 0) continue;

		for (int i = 0; i < arr[now]; i++) {
			int next = now + i + 1;
			if (visited[next] > -1) continue;
			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	memset(visited, -1, sizeof(visited));

	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	bfs(0);

	cout << visited[n - 1];

	return 0;
}