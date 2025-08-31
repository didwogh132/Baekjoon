#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n;
int arr[110][110];
int visited[110][110];
int height;
int Max;
int cnt;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
	int y;
	int x;
};

void bfs(int y, int x) {
	queue<node> q;
	q.push({ y,x });
	visited[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (arr[ny][nx] <= height) continue;
			if (visited[ny][nx] >= 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	while (true) {
		memset(visited, -1, sizeof(visited));
		cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > height && visited[i][j] == -1) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		if (cnt > Max) Max = cnt;
		if (cnt == 0) break;
		height++;
	}
	cout << Max;
	return 0;
}