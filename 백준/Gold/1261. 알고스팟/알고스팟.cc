#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
string arr[110];
int visited[110][110];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
	int y;
	int x;
};

void bfs(int y, int x) {
	queue<node>q;
	q.push({ y, x });
	visited[y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == '1') {
				if (visited[ny][nx] > visited[now.y][now.x] + 1) {
					visited[ny][nx] = visited[now.y][now.x] + 1;
				}
				else if (visited[ny][nx] > -1) continue;
				else {
					visited[ny][nx] = visited[now.y][now.x] + 1;
				}
			}
			else {
				if (visited[ny][nx] > visited[now.y][now.x]) {
					visited[ny][nx] = visited[now.y][now.x];
				}
				else if (visited[ny][nx] > -1) continue;
				else {
					visited[ny][nx] = visited[now.y][now.x];
				}
			}
			q.push({ ny,nx });
		}
	}
}


int main() {
	memset(visited, -1, sizeof(visited));
	cin >> m >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bfs(0, 0);

	
	cout << visited[n - 1][m - 1];
	return 0;
}