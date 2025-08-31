#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

struct node {
	int num;
	int cost;
	bool operator < (node right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};
vector<node> arr[1010];
int dist[1010];
int a, b;
int n, m;
int path[1010];
vector<int> path2;

void dijkstra(int start) {
	for (int i = 0; i <= n; i++) {
		dist[i] = 2e8;
	}
	priority_queue<node>pq;
	pq.push({ start, 0 });
	dist[start] = 0;
	
	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.num] < now.cost) continue;

		for (int i = 0; i < arr[now.num].size(); i++) {
			node next = arr[now.num][i];
			int nextcost = dist[now.num] + next.cost;
			if (dist[next.num] <= nextcost) continue;
			dist[next.num] = nextcost;
			path[next.num] = now.num;
			pq.push({ next.num, nextcost });
		}
	}
}

void findPath(int end) {
	path2.clear();
	for (int cur = end; cur != -1; cur = path[cur]) {
		path2.push_back(cur);
	}
	reverse(path2.begin(), path2.end());
}

int main() {
	memset(path, -1, sizeof(path));
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;
		arr[from].push_back({ to,cost });
	}
	
	cin >> a >> b;

	dijkstra(a);
	findPath(b);

	cout << dist[b] << "\n";
	cout << path2.size() << "\n";
	for (int i = 0; i < path2.size(); i++) {
		cout << path2[i] << " ";
	}

	return 0;
}