#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
string arr[1010];
int visited[1010][1010];
int visited2[1010][1010];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int ya, xa;
struct node {
	int y;
	int x;
};
int Min;
queue<node>q;
void bfs() {

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == '#') continue;
			if (visited[ny][nx] > visited[now.y][now.x] + 1) {
				visited[ny][nx] = visited[now.y][now.x] + 1;
			}
			else if (visited[ny][nx] >= 0) continue;
			else {
				visited[ny][nx] = visited[now.y][now.x] + 1;
			}
			q.push({ ny, nx });
		}
	}
}
void bfs2(int y, int x) {
	queue<node>q2;
	q2.push({ y,x });
	visited2[y][x] = 0;

	while (!q2.empty()) {
		node now = q2.front(); q2.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == '#' || arr[ny][nx] == '*') continue;
			if (visited2[now.y][now.x] + 1 >= visited[ny][nx] && visited[ny][nx] != -1) continue;
			if (visited2[ny][nx] >= 0) continue;
			visited2[ny][nx] = visited2[now.y][now.x] + 1;
			q2.push({ ny, nx });
		}
	}
}


int main() {
	int T;
	cin >> T;
	for (int tc = 0; tc < T; tc++) {
		cin >> m >> n;
		for (int i = 0; i < n; i++) {
			cin >> arr[i];
		}
		memset(visited, -1, sizeof(visited));
		memset(visited2, -1, sizeof(visited2));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == '*') {
					q.push({ i,j });
					visited[i][j] = 0;
				}
				else if (arr[i][j] == '@') {
					ya = i;
					xa = j;
				}
			}
		}
		bfs();
		bfs2(ya, xa);
		Min = 21e7;
		for (int i = 0; i < n; i++) {
			if (arr[i][0] == '.' || arr[i][0] == '@') {
				if (visited2[i][0] != -1) {
					if (visited2[i][0] < Min) Min = visited2[i][0];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			if (arr[i][m-1] == '.' || arr[i][m-1] == '@') {
				if (visited2[i][m-1] != -1) {
					if (visited2[i][m-1] < Min) Min = visited2[i][m-1];
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (arr[0][i] == '.' || arr[0][i] == '@') {
				if (visited2[0][i] != -1) {
					if (visited2[0][i] < Min) Min = visited2[0][i];
				}
			}
		}
		for (int i = 0; i < m; i++) {
			if (arr[n-1][i] == '.' || arr[n-1][i] == '@') {
				if (visited2[n-1][i] != -1) {
					if (visited2[n-1][i] < Min) Min = visited2[n-1][i];
				}
			}
		}
		if (Min == 21e7) {
			cout << "IMPOSSIBLE" << "\n";
		}
		else {
			cout << Min + 1 << "\n";
		}
	}
	
	return 0;
}