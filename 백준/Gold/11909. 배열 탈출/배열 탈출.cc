#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

int n;
int arr[2222][2222];
int visited[2222][2222];
int ydir[] = { 0, 1 };
int xdir[] = { 1, 0 };
struct node {
	int y;
	int x;
	int cost;
	bool operator <(node right) const {
		if (cost > right.cost) return true;
		if (cost < right.cost) return false;
		return false;
	}
};

void dijkstra(int y, int x) {
	priority_queue<node> pq;
	pq.push({ y, x, 0 });
	visited[y][x] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (visited[now.y][now.x] < now.cost) continue;
		for (int i = 0; i < 2; i++) {
			int ny = now.y + ydir[i];
			int nx = now.x + xdir[i];
			int nextcost;
			if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
			if (arr[now.y][now.x] > arr[ny][nx]) {
				nextcost = visited[now.y][now.x];
			}
			else {
				nextcost = visited[now.y][now.x] + arr[ny][nx] - arr[now.y][now.x] + 1;
			}
			if (visited[ny][nx] <= nextcost) continue;
			visited[ny][nx] = nextcost;
			pq.push({ ny, nx, nextcost });
		}
	}
}

int main() {
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		fill(visited[i], visited[i] + n, INT_MAX);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
	dijkstra(0, 0);

	cout << visited[n - 1][n - 1];
	return 0;
}