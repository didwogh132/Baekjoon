#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
#include <queue>

using namespace std;

int n, m;
int arr[1010][1010];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int Max;
struct node {
	int y, x;
};
queue<node>q;

void bfs() {
	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (arr[ny][nx] == -1) continue;
			if (arr[ny][nx] == 0) {
				arr[ny][nx] = arr[now.y][now.x] + 1;
				q.push({ ny,nx });
			}
		}
		
	}
}

int main() {
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 1) q.push({ i,j });
		}
	}
	bfs();

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0) {
				Max = -1;
				cout << Max;
				return 0;
			}
			if (arr[i][j] > Max) Max = arr[i][j];
		}
	}

	cout << Max - 1;

	return 0;
}