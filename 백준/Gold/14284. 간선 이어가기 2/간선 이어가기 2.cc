#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
#include<cstring>

using namespace std;
struct node {
	int num;
	int cost;
	bool operator<(node right) const {
		if (cost < right.cost) return false;
		if (cost > right.cost) return true;
		return false;
	}
};
vector<node>arr[5010];
int dist[5010];
int n, m;

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
		arr[from].push_back({ to, cost });
		arr[to].push_back({ from, cost });
	}
	int s, t;
	cin >> s >> t;
	dijkstra(s);

	cout << dist[t];

	return 0;
}