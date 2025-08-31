#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int arr[310][310];
int visited[310][310];
int ydir[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int xdir[] = { -2, -1, 1, 2, 2, 1, -1, -2 };
int n;

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
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (visited[ny][nx] > visited[now.y][now.x] + 1) {
				visited[ny][nx] = visited[now.y][now.x] + 1;
			}
			else if (visited[ny][nx] >= 0) continue;
			else {
				visited[ny][nx] = visited[now.y][now.x] + 1;
			}
			q.push({ ny,nx });
		}
	}
}

int main() {
	int T;
	cin >> T;
	for (int tc = 1; tc <= T; tc++) {
		memset(visited, -1, sizeof(visited));
		cin >> n;
		int y1, x1;
		int y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;

		bfs(y1, x1);

		cout << visited[y2][x2] << "\n";
	}
}