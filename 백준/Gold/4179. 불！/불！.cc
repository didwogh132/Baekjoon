#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
string arr[1010];
struct node {
	int y;
	int x;
};
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int visited[1010][1010];
int visited2[1010][1010];
int Min;
int ya, xa;


void bfs2(int y, int x) {
	queue<node>q;
	q.push({ y,x });
	visited2[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == '#') continue;
			if (visited2[ny][nx] > visited2[now.y][now.x] + 1) {
				visited2[ny][nx] = visited2[now.y][now.x] + 1;
			}
			else if (visited2[ny][nx] >= 0) continue;
			else {
				visited2[ny][nx] = visited2[now.y][now.x] + 1;
			}
			q.push({ ny,nx });
		}
	}
}
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
			if (arr[ny][nx] == '#' || arr[ny][nx] == 'F' ) continue;
			if (visited[ny][nx] >= 0) continue;
			if (visited2[ny][nx] == -1) {
				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ ny,nx });
			}
			else if (visited[now.y][now.x] + 1 >= visited2[ny][nx]) continue;
			else {
				visited[ny][nx] = visited[now.y][now.x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = -1;
			visited2[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'F') {
				bfs2(i, j);
			}
			if (arr[i][j] == 'J') {
				ya = i;
				xa = j;
			}
		}
	}

	bfs(ya, xa);
	Min = 21e7;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
				if (arr[i][j] == '.' || arr[i][j] == 'J') {
					if (visited[i][j] != -1 && visited[i][j] < Min) Min = visited[i][j];
				}
				else if (arr[i][j] == '#') continue;
			}
		}
	}
	if (Min == 21e7) {
		cout << "IMPOSSIBLE";
	}
	else {
		cout << Min + 1;
	}

	return 0;
}