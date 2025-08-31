#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[101][71];
int visited[101][71];
struct node {
	int y;
	int x;
};
int ydir[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int xdir[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

bool bfs(int y, int x) {
	queue<node>q;
	q.push({ y,x });
	visited[y][x] = 1;

	bool peak = true;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 8; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] > arr[y][x]) {
				peak = false;
			}

			else if (arr[ny][nx] == arr[y][x] && visited[ny][nx] == 0) {
				visited[ny][nx] = 1;
				q.push({ ny, nx });
			}
		}
	}
	return peak;
}

int main() {

	memset(visited, 0, sizeof(visited));
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0 && visited[i][j] == 0) {
				if (bfs(i, j)) cnt++;
			}
		}
	}

	cout << cnt;

	return 0;
}