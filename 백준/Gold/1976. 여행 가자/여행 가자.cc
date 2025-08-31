#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m;
int arr[210][210];
int visited[210];
int list[210];
int start;
bool flag = true;

void bfs(int s) {
	queue<int> q;
	q.push(s);
	visited[s] = 1;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int i = 1; i <= n; i++) {
			if (arr[now][i] == 0) continue;
			int next = i;
			if (visited[next] > -1) continue;
			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
}
int main() {
	
	cin >> n >> m;
	memset(visited, -1, sizeof(visited));
	memset(list, 0, sizeof(list));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		int num;
		cin >> num;
		list[num]++;
		if (i == 0) {
			start = num;
		}
	}
	bfs(start);

	for (int i = 1; i <= n; i++) {
		if (list[i] != 0) {
			if (visited[i] == -1) {
				flag = false;
				break;
			}
			else {
				continue;
			}
		}
	}
	if (flag) {
		cout << "YES";
	}
	else {
		cout << "NO";
	}

	return 0;
}
