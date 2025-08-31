#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

int n, m;

struct node {
	int num;
	int cost;

	bool operator <(node right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;

		return false;
	}
};
vector<node> arr[1010];
int dist[1010];

void dijkstra(int start) {
	for (int i = 0; i <= n; i++) {
		dist[i] = 21e8;
	}
	priority_queue<node> pq;
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
			pq.push({ next.num, nextcost });

		}
	}
}
int main() {
	
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int from, to, cost;
		cin >> from >> to >> cost;

		arr[from].push_back({ to,cost });
	}
	int a, b;
	cin >> a >> b;
	dijkstra(a);

	cout << dist[b];

	return 0;
}