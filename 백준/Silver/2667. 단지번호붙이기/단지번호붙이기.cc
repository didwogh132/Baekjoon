#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n;
string arr[30];
int visited[30][30];
int cnt;
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
	int y;
	int x;
};
int a;
int path[600];


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
			if (arr[ny][nx] == '0') continue;
			if (visited[ny][nx] >= 0) continue;
			cnt++;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			q.push({ ny,nx });
		}

	}
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			visited[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < arr[i].size(); j++) {
			if (arr[i][j] == '1' && visited[i][j] == -1) {
				cnt = 1;
				bfs(i, j);
				path[a] = cnt;
				a++;
			}
		}
	}
	sort(path, path + a);

	cout << a << "\n";
	for (int i = 0; i < a; i++) {
		cout << path[i] << "\n";
	}

	return 0;
}