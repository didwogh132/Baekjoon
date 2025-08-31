#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int n;
string arr[110];
int visited[110][110];
int visited2[110][110];
int cnt, cnt2;
struct node {
	int y;
	int x;
};
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };

void bfsr(int y, int x) {
	queue<node>q;
	q.push({ y,x });
	visited[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (arr[ny][nx] != 'R') continue;
			if (visited[ny][nx] >= 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}
void bfsg(int y, int x) {
	queue<node>q;
	q.push({ y,x });
	visited[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (arr[ny][nx] != 'G') continue;
			if (visited[ny][nx] >= 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}
void bfsb(int y, int x) {
	queue<node>q;
	q.push({ y,x });
	visited[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (arr[ny][nx] != 'B') continue;
			if (visited[ny][nx] >= 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}
void bfsrg(int y, int x) {
	queue<node>q;
	q.push({ y,x });
	visited2[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (arr[ny][nx] == 'B') continue;
			if (visited2[ny][nx] >= 0) continue;
			visited2[ny][nx] = visited2[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}
void bfsb2(int y, int x) {
	queue<node>q;
	q.push({ y,x });
	visited2[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (arr[ny][nx] != 'B') continue;
			if (visited2[ny][nx] >= 0) continue;
			visited2[ny][nx] = visited2[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	memset(visited2, -1, sizeof(visited2));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'R' && visited[i][j] == -1) {
				bfsr(i, j);
				cnt++;
				if (visited2[i][j] == -1) {
					bfsrg(i, j);
					cnt2++;
				}
			}
			else if (arr[i][j] == 'B' && visited[i][j] == -1) {
				bfsb(i, j);
				cnt++;
				if (visited2[i][j] == -1) {
					bfsb2(i, j);
					cnt2++;
				}
				
			}
			else if (arr[i][j] == 'G' && visited[i][j] == -1) {
				bfsg(i, j);
				cnt++;
				if (visited2[i][j] == -1) {
					bfsrg(i, j);
					cnt2++;
				}
			}

		}
	}

	cout << cnt << " " << cnt2;

	return 0;
}