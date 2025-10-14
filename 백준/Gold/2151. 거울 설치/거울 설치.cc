#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <climits>
#include <memory.h>

using namespace std;

int n;
struct node {
	int y;
	int x;
	int cost;
	int dr;
	bool operator < (node right) const {
		return cost > right.cost;
	}
};
struct edge {
	int y;
	int x;
};
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int turn_left[4] = { 2, 3, 1, 0 }; // U->L, D->R, L->D, R->U
int turn_right[4] = { 3, 2, 0, 1 }; // U->R, D->L, L->U, R->D
string arr[55];
vector<edge> use;
int dist[4][55][55];

void dijkstra(int y, int x) {
	
	
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < n; j++) {
			fill(dist[i][j], dist[i][j] + n, INT_MAX);
		}
	}

	priority_queue<node> pq;

	for (int i = 0; i < 4; i++) {
		pq.push({ y, x, 0, i });
		dist[i][y][x] = 0;
	}

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.dr][now.y][now.x] < now.cost) continue;


		int ny = now.y + ydir[now.dr];
		int nx = now.x + xdir[now.dr];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
		if (arr[ny][nx] == '*') continue;

		if (arr[ny][nx] == '!') {
			if (dist[now.dr][ny][nx] > now.cost) {
				dist[now.dr][ny][nx] = now.cost;
				pq.push({ ny, nx, now.cost, now.dr });
			}

			int ld = turn_left[now.dr];
			if (dist[ld][ny][nx] > now.cost + 1) {
				dist[ld][ny][nx] = now.cost + 1;
				pq.push({ ny, nx, now.cost + 1, ld });
			}
			int rd = turn_right[now.dr];
			if (dist[rd][ny][nx] > now.cost + 1) {
				dist[rd][ny][nx] = now.cost + 1;
				pq.push({ ny, nx, now.cost + 1, rd });
			}
		}
		else {
			if (dist[now.dr][ny][nx] > now.cost) {
				dist[now.dr][ny][nx] = now.cost;
				pq.push({ ny, nx, now.cost, now.dr });
			}
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == '#') {
				use.push_back({ i, j });
			}
		}
	}

	dijkstra(use[0].y, use[0].x);

	
	int ans = INT_MAX;

	for (int i = 0; i < 4; i++) {
		if (dist[i][use[1].y][use[1].x] < ans) ans = dist[i][use[1].y][use[1].x];
	}

	if (ans == INT_MAX) {
		cout << -1;
	}
	else {
		cout << ans;
	}

	return 0;
}