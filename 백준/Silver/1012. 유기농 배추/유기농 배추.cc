#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int arr[55][55];
int visited[55][55];
int cnt;
struct node {
	int y;
	int x;
};
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int n, m, k;

void bfs(int y, int x) {
	queue<node>q;
	q.push({ y,x });
	visited[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 0) continue;
			if (visited[ny][nx] >= 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cnt = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				arr[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				visited[i][j] = -1;
			}
		}
		for (int i = 0; i < k; i++) {
			int y, x;
			cin >> y >> x;
			arr[y][x] = 1;
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1 && visited[i][j] == -1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}