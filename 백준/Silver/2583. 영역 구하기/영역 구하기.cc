#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m, k;
int arr[110][110];
int visited[110][110];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
	int y;
	int x;
};
vector<int> area;
int cnt;
int area_cnt;

void bfs(int y, int x) {
	cnt = 0;
	queue<node>q;
	q.push({ y,x });
	visited[y][x] = 0;
	cnt++;
	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];

			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (visited[ny][nx] > -1) continue;
			if (arr[ny][nx] == 1) continue;
			visited[ny][nx] = visited[now.y][now.x] + 1;
			cnt++;
			q.push({ ny,nx });
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> n >> m >> k;
	for (int i = 0; i < k; i++) {
		int y1, x1;
		int y2, x2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = n - y2; i < n - y1; i++) {
			for (int j = x1; j < x2; j++) {
				arr[i][j] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 0 && visited[i][j] == -1) {
				area_cnt++;
				bfs(i, j);
				area.push_back(cnt);
			}
		}
	}
	sort(area.begin(), area.end());

	cout << area_cnt << "\n";
	for (int i = 0; i < area.size(); i++) {
		cout << area[i] << " ";
	}

	return 0;
}