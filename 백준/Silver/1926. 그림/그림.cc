#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int arr[501][501];
int visited[501][501];
int cnt;
int cnt2;
int Max;
int ydir[] = { -1, 1, 0,0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
	int y;
	int x;
};

//void bfs(int y, int x) {
//	queue<node> q;
//	q.push({ y,x });
//	visited[y][x] = 1;
//
//	while (!q.empty()) {
//		node now = q.front(); q.pop();
//
//		for (int i = 0; i < 4; i++) {
//			int ny = now.y + ydir[i];
//			int nx = now.x + xdir[i];
//			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
//			if (arr[ny][nx] == 0) continue;
//			if (visited[ny][nx] > 0) continue;
//			visited[ny][nx] = visited[now.y][now.x] + 1;
//			cnt2++;
//			q.push({ ny,nx });
//		}
//	}
//}
void dfs(int y, int x) {

	cnt2++;
	for (int i = 0; i < 4; i++) {
		int ny = y + ydir[i];
		int nx = x + xdir[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (arr[ny][nx] == 0) continue;
		if (visited[ny][nx] > 0) continue;
		visited[ny][nx] = visited[y][x] + 1;
		dfs(ny, nx);
	}
}

int main() {
	
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0) continue;
			else if (arr[i][j] == 1 && visited[i][j] == -1) {
				visited[i][j] = 1;
				dfs(i, j);
				if (cnt2 > Max) Max = cnt2;
				cnt2 = 0;
			}
			
		}
	}
	for (int y = 0; y < n; y++) {
		for (int x = 0; x < m; x++) {
			if (arr[y][x] == 1 && visited[y][x] == 1) cnt++;

			
		}
	}
	cout << cnt << "\n";
	cout << Max;

	return 0;
}