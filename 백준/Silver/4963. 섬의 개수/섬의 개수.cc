#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[55][55];
int visited[55][55];
int cnt;
int ydir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int xdir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
struct node {
	int y;
	int x;
};

void bfs(int y, int x) {
	queue<node>q;
	q.push({ y,x });
	visited[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 0) continue;
			if (visited[ny][nx] > -1) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	
	while (true) {
		cin >> m >> n;
		if (m == 0 && n == 0) break;
		memset(visited, -1, sizeof(visited));
		memset(arr, 0, sizeof(arr));
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> arr[i][j];
			}
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