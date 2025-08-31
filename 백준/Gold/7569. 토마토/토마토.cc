#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int m, n, h;
int map[101][101][101];
int visited[101][101][101];
int ydir[] = { -1, 1, 0, 0, 0, 0 };
int xdir[] = { 0, 0, -1, 1, 0, 0 };
int zdir[] = { 0, 0, 0, 0, -1, 1 };
int Max;
struct node {
	int z;
	int y;
	int x;
};
queue<node>q;

void bfs() {
	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = now.z + zdir[i];
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || nz < 0 || ny >= n || nx >= m || nz >= h) continue;
			if (map[nz][ny][nx] == -1) continue;
			if (visited[nz][ny][nx] > visited[now.z][now.y][now.x] + 1) {
				visited[nz][ny][nx] = visited[now.z][now.y][now.x] + 1;
			}
			else if (visited[nz][ny][nx] >= 0)continue;
			else {
				visited[nz][ny][nx] = visited[now.z][now.y][now.x] + 1;
			}
			q.push({ nz, ny, nx });
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0;i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> map[k][i][j];
			}
		}
	}
	for (int k = 0; k < h; k++) {
		for (int i = 0;i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[k][i][j] == 1 && visited[k][i][j] == -1) {
					q.push({ k,i,j });
					visited[k][i][j] = 0;
				}
			}
		}
	}
	bfs();
	for (int k = 0; k < h; k++) {
		for (int i = 0;i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[k][i][j] == 0 && visited[k][i][j] == -1) {
					cout << -1;
					return 0;
				}
				if (visited[k][i][j] > Max) Max = visited[k][i][j];
			}
		}
	}
	cout << Max;

	return 0;
}