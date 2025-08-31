#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
string arr[51];
int visited[51][51];
int ydir[] = { -1, 1, 0,0 };
int xdir[] = { 0, 0, -1, 1 };
int Max;
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

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == 'W') continue;
			if (visited[ny][nx] >= 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			visited[y][x] = -1;;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'W') continue;
			bfs(i, j);

			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					if (arr[y][x] == 'W') continue;
					if (visited[y][x] > Max) Max = visited[y][x];
				}
			}
			for (int y = 0; y < n; y++) {
				for (int x = 0; x < m; x++) {
					visited[y][x] = -1;;
				}
			}
		}
	}
	cout << Max;

	return 0;
}