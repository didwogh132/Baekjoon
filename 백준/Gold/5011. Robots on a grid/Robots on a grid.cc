#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n;
string arr[1010];
int ydir[] = { 0, 1 };
int xdir[] = { 1, 0 };
int ydir2[] = { 0, 0, -1, 1 };
int xdir2[] = { -1, 1, 0, 0 };
long long visited[1010][1010];
int visited2[1010][1010];
struct node {
	int y;
	int x;
};

void bfs2(int y, int x) {
	queue<node>q;
	q.push({ y, x });
	visited2[y][x] = 1;

	while (!q.empty()) {
		node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir2[i];
			int nx = now.x + xdir2[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
			if (arr[ny][nx] == '#') continue;
			if (visited2[ny][nx] > visited2[now.y][now.x] + 1) {
				visited2[ny][nx] = visited2[now.y][now.x] + 1;
			}
			else if (visited2[ny][nx] > -1) continue;
			else {
				visited2[ny][nx] = visited2[now.y][now.x] + 1;
			}
			q.push({ ny, nx });
		}
	}
}

int main() {
	memset(visited, 0, sizeof(visited));
	memset(visited2, -1, sizeof(visited2));
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bfs2(0, 0);

	visited[0][0] = 1;
	for (int i = 1; i < n; i++) {
		if (arr[i][0] == '#')
			break;
		visited[i][0] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (arr[0][i] == '#')
			break;
		visited[0][i] = 1;
	}
	for (int i = 1; i < n; i++) {
		for (int j = 1; j < n; j++) {
			if (arr[i][j] == '#') continue;
			else {
				visited[i][j] += (visited[i - 1][j] + visited[i][j-1]);
				visited[i][j] %= INT_MAX;
			}
		}
	}
	if (visited[n - 1][n - 1] == 0) {
		if (visited2[n - 1][n - 1] > 0) {
			cout << "THE GAME IS A LIE";
		}
		else {
			cout << "INCONCEIVABLE";
		}
	}
	else {
		cout << visited[n - 1][n - 1];
	}
	return 0;
}