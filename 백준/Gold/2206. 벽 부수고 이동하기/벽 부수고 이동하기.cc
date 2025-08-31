#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;
string arr[1010];
int visited[2][1010][1010];
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
struct node {
	int destroy;
	int y;
	int x;
	
};

void bfs(int cnt, int y, int x ) {
	queue<node>q;
	q.push({ cnt, y, x });
	visited[cnt][y][x] = 1;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			int nd = now.destroy;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			if (arr[ny][nx] == '1' && nd == 0) continue;
			else if (arr[ny][nx] == '1') {
				nd = 0;
				visited[nd][ny][nx] = visited[now.destroy][now.y][now.x] + 1;
				q.push({ nd, ny, nx });
			}
			else {
				if (visited[nd][ny][nx] > visited[now.destroy][now.y][now.x] + 1) {
					visited[nd][ny][nx]= visited[now.destroy][now.y][now.x] + 1;
				}
				else if (visited[nd][ny][nx] > 0) continue;
				else {
					visited[nd][ny][nx] = visited[now.destroy][now.y][now.x] + 1;
				}
				q.push({ nd, ny, nx });
			}
			
		}
	}
}

int main() {
	memset(visited, -1, sizeof(visited));
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	bfs(1, 0, 0);

	if (visited[0][n - 1][m - 1] != -1 || visited[1][n - 1][m - 1] != -1) {
		if (visited[1][n - 1][m - 1] == -1) {
			cout << visited[0][n - 1][m - 1];
		}
		else if(visited[0][n - 1][m - 1] == -1){
			cout << visited[1][n - 1][m - 1];
		}
		else {
			if (visited[0][n - 1][m - 1] > visited[1][n - 1][m - 1])
				cout << visited[1][n - 1][m - 1];
			else
				cout << visited[0][n - 1][m - 1];
		}
	}
	else
		cout << visited[0][n - 1][m - 1];

	return 0;
}