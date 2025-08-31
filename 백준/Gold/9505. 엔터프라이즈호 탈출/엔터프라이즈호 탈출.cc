#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>

using namespace std;

int cost[26];
string arr[1010];
struct node {
	int y;
	int x;
	int cost;
	bool operator <(node right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};
int ydir[] = { -1, 1, 0, 0 };
int xdir[] = { 0, 0, -1, 1 };
int dist[1010][1010];
int k, n, m;

void dijkstra(int y, int x) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = 21e8;
		}
	}
	priority_queue<node> pq;
	pq.push({ y, x, 0 });
	dist[y][x] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.y][now.x] < now.cost) continue;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (arr[ny][nx] == 'E') continue;
			int nextcost = dist[now.y][now.x] + (cost[arr[ny][nx] - 'A']);
			if (dist[ny][nx] <= nextcost) continue;
			dist[ny][nx] = nextcost;
			pq.push({ ny, nx, nextcost });
		}
	}
}

int main() {
	int T;
	cin >> T;

	for (int tc = 1; tc <= T; tc++) {
		memset(cost, 0, sizeof(cost));
		
		int Min = 21e8;
		
		cin >> k >> n >> m;
		for (int i = 0; i < k; i++) {
			char num;
			int index_cost;
			cin >> num >> index_cost;

			cost[num - 'A'] = index_cost;
		}

		for (int i = 0; i < m; i++) {
			cin >> arr[i];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] == 'E') {
					dijkstra( i, j );
				}
			}
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
					if (dist[i][j] < Min) Min = dist[i][j];
				}
				else continue;
			}
		}
		cout << Min << "\n";

		for (int i = 0; i < m; i++) {
			arr[i].clear();
		}
	}

	return 0;
}