#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

string arr[31][31];
int L, R, C;
int visited[31][31][31];
int ydir[] = { -1, 1, 0, 0, 0, 0 };
int xdir[] = { 0, 0, -1, 1, 0, 0 };
int zdir[] = { 0, 0, 0, 0, -1, 1 };
int ey, ex, ez;
struct node {
	int z;
	int y;
	int x;
};
void bfs(int z, int y, int x) {
	queue<node> q;
	q.push({ z, y, x });
	visited[z][y][x] = 0;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 6; i++) {
			int nz = now.z + zdir[i];
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (nz < 0 || ny < 0 || nx < 0 || nz >= L || ny >= R || nx >= C) continue;
			if (arr[nz][ny][nx] == '#') continue;
			if (visited[nz][ny][nx] > visited[now.z][now.y][now.x] + 1) {
				visited[nz][ny][nx] = visited[now.z][now.y][now.x] + 1;
			}
			else if (visited[nz][ny][nx] > -1) continue;
			else {
				visited[nz][ny][nx] = visited[now.z][now.y][now.x] + 1;
			}
			q.push({ nz,ny,nx });
		}
	}
}

int main() {
	while (true) {
		memset(visited, -1, sizeof(visited));
		
		cin >> L >> R >> C;
		if (L == 0 && R == 0 && C == 0) break;
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				cin >> arr[i][j];
			}
		}
		for (int i = 0; i < L; i++) {
			for (int j = 0; j < R; j++) {
				for (int k = 0; k < C; k++) {
					if (arr[i][j][k] == 'S') {
						bfs(i, j, k );
					}
					else if (arr[i][j][k] == 'E') {
						ez = i;
						ey = j;
						ex = k;
					}
				}
			}
		}

		if (visited[ez][ey][ex] == -1) {
			cout << "Trapped!" << "\n";
		}
		else {
			cout << "Escaped in " << visited[ez][ey][ex] << " minute(s)." << "\n";
		}
	}

	
	
}