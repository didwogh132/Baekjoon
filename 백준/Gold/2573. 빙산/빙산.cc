#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
int arr[310][310];
int arr2[310][310];
int visited[310][310];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int cnt;
int cnt2;
int cnt3;
int zerocheck;
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
			if (arr[ny][nx] == 0) continue;
			if (visited[ny][nx] >= 0) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}
}

int main() {

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	while (cnt >= 0) {
		cnt3 = 0;
		zerocheck = 0;
		memset(visited, -1, sizeof(visited));
		memset(arr2, 0, sizeof(arr2));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0 && visited[i][j] == -1) {
					bfs(i, j);
					cnt3++;
				}
				if (arr[i][j] == 0) {
					zerocheck++;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					cnt2 = 0;
					visited[i][j] = 0;
					for (int k = 0; k < 4; k++) {
						int ny = i + ydir[k];
						int nx = j + xdir[k];
						if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
						if (arr[ny][nx] == 0) cnt2++;
					}
					arr2[i][j] = cnt2;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] != 0) {
					if (arr[i][j] - arr2[i][j] < 0) {
						arr[i][j] = 0;
					}
					else {
						arr[i][j] = arr[i][j] - arr2[i][j];
					}
				}
			}
		}
		if (zerocheck == n * m) {
			cnt = 0;
			break;
		}
		if (cnt3 == 1) {
			cnt++;
		}
		else if (cnt3 >= 2) {
			break;
		}
	}
	cout << cnt;

	return 0;
}