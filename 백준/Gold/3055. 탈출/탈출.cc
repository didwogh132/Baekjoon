#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
string arr[55];
int visited[55][55];
int visited2[55][55];
int ya, xa;
int yb, xb;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
	int y;
	int x;
};
queue<node>q;

void bfs() {
	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 'X' || arr[ny][nx] == 'D') continue;
			if (visited[ny][nx] > visited[now.y][now.x] + 1) {
				visited[ny][nx] = visited[now.y][now.x] + 1;
			}
			else if (visited[ny][nx] > -1) continue;
			else {
				visited[ny][nx] = visited[now.y][now.x] + 1;
			}
			q.push({ ny,nx });
		}
	}
}
void bfs2(int y, int x) {
	q.push({ y,x });
	visited2[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++ ) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 'X' || arr[ny][nx] == '*') continue;
			if (visited2[now.y][now.x] + 1 >= visited[ny][nx] && visited[ny][nx] != -1) continue;
			if (visited2[ny][nx] > visited2[now.y][now.x] + 1) {
				visited2[ny][nx] = visited2[now.y][now.x] + 1;
			}
			else if (visited2[ny][nx] > -1) continue;
			else {
				visited2[ny][nx] = visited2[now.y][now.x] + 1;
			}
			q.push({ ny,nx });
		}
	}
}

int main() {
	
	memset(visited, -1, sizeof(visited));
	memset(visited2, -1, sizeof(visited2));

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == '*') {
				q.push({ i,j });
				visited[i][j] = 0;
			}
			else if (arr[i][j] == 'D') {
				ya = i;
				xa = j;
			}
			else if (arr[i][j] == 'S') {
				yb = i;
				xb = j;
			}
		}
	}
	bfs();
	bfs2(yb, xb);

	if (visited2[ya][xa] == -1) {
		cout << "KAKTUS";
	}
	else {
		cout << visited2[ya][xa];
	}
	return 0;
}